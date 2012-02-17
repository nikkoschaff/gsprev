///
/// File: ImageEvaluator.cpp  Implementation for the 
///		ImageEvaluator, which reads tests
///
/// @author Nikko Schaff
///
/// /////////////////////////////////////////////////////////////////

//Local header includes
#include "stdafx.h"
#include "ImageEvaluator.h"
#include "ImageReadException.h"

/*
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
*/

#include "opencv2\opencv.hpp"


//System header includes - Used now for testing
#include < iostream >


using namespace std;
using namespace cv;

/// ImageEvaluator constructor
ImageEvaluator::ImageEvaluator( int numQ )
: numQuestions( numQ ), MAIN_X_OFFSET( 7.169230769 ),
	MAIN_Y_OFFSET( 35.58974359 ), regions( numQ + 1 ),
	nameLetterRegions( ), name( "" ), answersVector( numQ + 1 ) {

	// Sets the base image corner points (TEMP)
	mainUL.x = 113.0f;
	mainUL.y = 412.0f;
	mainUR.x = 2439.36f;
	mainUR.y = 413.28f;
	mainLL.x = 111.6f;
	mainLL.y = 3187.2f;
	mainLR.x = 2439.36f;
	mainLR.y = 3186.72f;


	// Sets the base image
	
	baseImage = imread( "GSTMain.jpg", 0 );
	if ( baseImage.data == NULL ) {
		cerr << "Read error for main file. " <<
			" Check to see if GSTMain.jpg is in the program directory" << endl;
	}
}

/// ImageEvaluator desstructor
ImageEvaluator::~ImageEvaluator() {
}

/// Loads the image from the given filename
void ImageEvaluator::setImage( string eFilename ) {

	try {
		//Loads and sets the image as the test image
		examImage = imread( eFilename, 0 );
		if ( examImage.data == NULL ) {
			throw ImageReadException;
		}
	} catch ( exception & e ) {
		cout << e.what() << endl;
		int stop = 1;
		cout << "Program will now end. Press any key and enter to terminate." << endl;
		cin >> stop;
		exit( 0 );
	}

	//Sets the resolution ratios
	resRatioWidth = double( examImage.cols ) / double( MAIN_RES_WIDTH );
	resRatioHeight = double( examImage.rows ) / double( MAIN_RES_HEIGHT );
}

/// Makes and returns a vector of ROIs for each answer region
void ImageEvaluator::cv_setAnswerRegions() {

	// Answer regions within the test
	vector< Rect > answerRegions( numQuestions + 1 );

	// Compute the calibration corner points
	cv_compCalibCorners();

	// Orient the image to be solidly readable for extracting information
	cv_orientImage();

	// Calculate and find each question ROI within range of numQuestions

	// x offset for main bounding box
	double mainxoff = ( double( UR.x - UL.x )
	 	/ ( MAIN_X_OFFSET * resRatioWidth ) );
	// y offset for main bounding box
	double mainyoff = ( double( LL.y - UL.y )
		/ ( MAIN_Y_OFFSET * resRatioHeight ) );

	//Main coordinates, will be set as points for Q1's bounding box
	double mainX( double( UL.x ) + ( mainxoff * resRatioWidth ) );
	double mainY( double( UL.y ) + ( mainyoff * resRatioHeight ) ); 

	//Relative coordinates, used for each Qs bounding box
	double relativeX( mainX );
	double relativeY( mainY );
	
	/// TODO Allow to handle for skewed rotation
	// idea: Maybe use detection in each ROI to find area to search in?
	// --------------------- START skewed rotation handling

	// Offset to handle skewed image rotation
	//double skewedRotationOffset;
	
	// --------------------- END


	//Find the ROIs located at each position
	for ( int numQ = 1; numQ <= numQuestions; numQ++ ) {
		// Create and store ROI
		CvRect answerRegion = { int( relativeX ), int( relativeY ), 
			int( double( QUESTION_ROI_WIDTH ) * resRatioWidth ),
			int( double( QUESTION_ROI_HEIGHT ) * resRatioHeight ) };
		// Stores the answer region ROI into the vector
		answerRegions.at( numQ ) = answerRegion;

		//Draws rectangle of bounding box; for testing
		
		//Point2f ROI_UL;
		//ROI_UL.x = relativeX;
		//ROI_UL.y = relativeY;
		//Point2f ROI_LR;
		//ROI_LR.x = relativeX + ( double( QUESTION_ROI_WIDTH ) * resRatioWidth );
		//ROI_LR.y = relativeY + ( double( QUESTION_ROI_HEIGHT ) * resRatioHeight );
		//rectangle( examImage, ROI_UL, ROI_LR, CV_RGB( 0, 255, 0 ), 1 );
		
		if ( numQ == 25 ) { //Change offset regions depending on next question
			double relxoff = ( ( UR.x - UL.x ) / ( 1.24799143 * resRatioWidth ) );
			relativeX = ( ( relxoff * resRatioWidth ) );
			relativeY = mainY;
		} else {
			double relyoff = 106 * resRatioHeight;
			relativeY += relyoff;	
		}
	}

	
	// Output -- for testing purposes only
	//namedWindow( "result", 0 );
	//imshow( "result", examImage );
	//waitKey( 0 );
	//destroyAllWindows();
	
	// Set the ROIs to regions
	regions = answerRegions; 
}

/// Returns the answer for that particular region
string ImageEvaluator::cv_getAnswer( Rect answerRegion ) {

	//Set up a projection for each of the five possible answer choices
	string answer = "";
	//Set the ROI for the image copy
	Mat answerROI = examImage( answerRegion );
	//Specific widths and heights for that particular row
	const int qWidth = answerRegion.width;
	const int qHeight = answerRegion.height;
	// Number of dark spots in an image region
	double darkCount;
	// min filled threshold to be considered "filled"
	double thresh = 225;
	// multiplied to thresh to work for each image regardless of configuration
	double threshModifier = ( double( qWidth/5 ) * qHeight ) / ( 79 * 75 );
	//double imageResolution;
	double totalThresh = thresh / threshModifier;
	// Adapted value for level of fill
	double modified;
	// Scalar value of the pixel at chosen location
	Scalar intensity;
	// NOTE: If needed, could use dereferencing to get value.

	//For each subdivision
	for( int a = 0; a < 5; a++ ) {
		// Resets the darkCount to zero
		darkCount = 0;

		// Iterates through each column (by width)
		for( int col = ( qWidth/5 * a ); col < ( qWidth/5 * ( a + 1 ) ); col++ ) {
			// Iterates through each row (by height)
			for( int row = 0; row < qHeight; row++ ) {

				// Sets the intensity as the value of the pixel at that location
				intensity = answerROI.at<uchar>(row, col);

				if ( intensity.val[ 0 ] < 200 ) {
					darkCount++;
					answerROI.at<uchar>(row, col) = 0;
				}

			}
		}
		// Assigns the darkCount a resolution-thresh modified value
		darkCount = darkCount / threshModifier;
		
		// Checks to see if it accurately corresponds with an answer region
		if ( a == 0 ) {
			modified = darkCount - 1151;
			if ( modified > totalThresh ) {
				answer.append( "A" );
			}
		} else if ( a == 1 ) {
			modified = darkCount - 1237;
			if ( modified > totalThresh ) {
				answer.append( "B" );
			}
		} else if ( a == 2 ) {
			modified = darkCount - 1099;
			if ( modified > totalThresh ) {
				answer.append( "C" );
			}
		} else if ( a == 3 ) {
			modified = darkCount - 1160;
			if ( modified > totalThresh ) {
				answer.append( "D" );
			}
		} else if ( a == 4 ) {
			modified = darkCount - 1144;
			if ( modified > totalThresh ) {
				answer.append( "E" );
			}
		}
	}


	return answer;
}

/// Reads and interprets the exam, returning the answers
vector< string > ImageEvaluator::readExam() {

	// Get the answer regions
	cv_setAnswerRegions();

	// Vector of answers for each question at index
	vector< string > answers( numQuestions + 1 );

	// For each answer region, determine answer and place it into answers vector
	for( int i = 1; i < numQuestions + 1; i++ ) {
		answers.at( i ) = cv_getAnswer( regions.at( i ) );
	}

	return answers;
}

/// Computes the four calibration corner points
void ImageEvaluator::cv_compCalibCorners() {

	//-- 1: Pre-Processing - match base and exam image sizes and dilate exam
	
	// Clones made so image processing doesn't affect main images
	Mat examCopy = examImage.clone();
	
	// Dilates the exam image to reduce noise
	dilate( examCopy, examCopy, Mat(), Point(-1,-1), 3 );

	//-- 2: Smooth, also reduces noise
	GaussianBlur( examCopy, examCopy, Size( 3, 3 ), 0, 0 );

	//-- 3: Apply an adaptive threshold to get a B/W image (TODO adjust)
	//adaptiveThreshold( examCopy, examCopy, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 10 );

	//-- 3a: Detect edges by Canny method
	Canny( examCopy, examCopy, 150, 250 );

	//-- 4: Find contours to establish the interesting marks
	vector< vector< Point > > contours;
	findContours( examCopy, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );

	// Vector to hold correct calibration points
	vector< Rect > calibCornerRects;
	
	// Draws contour marks (for testing)
	//drawContours( examCopy, contours, -1, CV_RGB( 150, 250, 150 ), 5 );

	double area;
	// Ratio of exam size to base size
	double resolutionRatio = double( (examImage.rows * examImage.cols) ) /
		double( (baseImage.rows * baseImage.cols) );
	// Adjusted area - area divided by ratio to match base iamge
	double adjustedArea;

	//-- 7: Finds correct contours for calib corners and sends
	//		rectangle representation to the corner rectangle vector
	for ( unsigned int i = 0; i < contours.size(); i++ ) {

		area = contourArea( contours.at( i ) );
		adjustedArea = area / resolutionRatio;

		// Allows only contours with correct specified area through
		// Must have area roughly greater than 16500
		// And have area roughly less than 23500
		// (All adjusted for total resolution)
		// NOTE: May need to stress test for equivalent (and errant) areas
		// NOTE: May need to test for rotation (area -> true)?
		if( adjustedArea > CALIB_RECT_AREA_LOWER ) {
			// Draws bounding rect - should only be the correct ones (for testing)
			//Rect box = boundingRect( contours.at( i ) );
			//rectangle( examCopy, Point( box.x, box.y ), Point( box.x + box.width, 
			//	box.y + box.height ), CV_RGB( 150, 250, 150 ), 8 );

			// Adds the rotated rectangle from the contour
			calibCornerRects.push_back( minAreaRect( contours.at( i ) ).boundingRect() );
		}
	}

	// Point, used to find edge calibration points
	Point corner;

	// Assign calibration points to be at the center of the image.
	UL = Point( examImage.cols / 2, examImage.rows / 2 );
	UR = Point( examImage.cols / 2, examImage.rows / 2 );
	LL = Point( examImage.cols / 2, examImage.rows / 2 );
	LR = Point( examImage.cols / 2, examImage.rows / 2 );

	//-- 8: Determine the calibration points
	for( unsigned int i = 0; i < calibCornerRects.size(); i++ ) {

		// Assigns points to find
		for( int point = 0; point < 4; point++ ) {

			// Makes each of the points
			// NOTE: Poor choice of algorithm (style). May need change
			if ( point == 0 ) { //UL
				corner = calibCornerRects.at( i ).tl();
			} else if ( point == 1 ) { //UR
				corner = calibCornerRects.at( i ).tl();
				corner.x = corner.x + calibCornerRects.at( i ).width;
			} else if ( point == 2 ) { //LL 
				corner = calibCornerRects.at( i ).tl();
				corner.y = corner.y + calibCornerRects.at( i ).height;
			} else if ( point == 3 ) { //LR
				corner = calibCornerRects.at( i ).br();
			}

			// Searches for value of the point to see where it is relative to others

			// If a UL point
			if ( 
				sqrt( pow( double( corner.x ), 2 ) 
					+ pow( double( corner.y ), 2 ) )
				< sqrt( pow( UL.x, 2 ) + pow( UL.y, 2 ) ) )  {

				UL = corner;
			}
			// If a UR point
			if ( sqrt( pow(  double( examImage.cols  - corner.x ), 2 ) 
			+ pow( double( corner.y ), 2 ) )
			< sqrt( pow( double( examImage.cols  - UR.x ), 2 ) + pow( double( UR.y ), 2 ) ) ) {

				UR = corner;
			}
			// If a LL point
			if ( sqrt(  pow( double( corner.x ), 2 ) 
			+ pow( double( examImage.rows - corner.y ), 2 ) )
			< sqrt( pow( LL.x, 2 ) + pow( examImage.rows - LL.y, 2 ) ) ) {

				LL = corner;
			}
			// If a LR point
			if ( sqrt( pow( double( examImage.cols - corner.x ), 2 ) 
			+ pow( double( examImage.rows  - corner.y ), 2 ) )
			< sqrt( pow( examImage.cols - LR.x, 2 ) + pow( examImage.rows - LR.y, 2 ) ) ) {

				LR = corner;
			}
		}

	}


	//-- 9: Make sure orientation is correct, assigns points to good orientation

	// ---- Handling to make sure the file properly had all 4 points visible -----
	try {	
		// Absolute distance from UL to UR
		float d1 = sqrt( abs( UR.x - UL.x ) + abs( UR.y - UL.y ) );
		// Absolute distance from LL to LR
		float d2 = sqrt( abs( LL.x - LR.x ) + abs( LL.y - LR.y ) );
		// Distance differential.  May have to be changed, as it is untested
		float distanceModifier = 5.0f;
		// Tests if distances are too varied ( result of bad read )
		if ( abs( d1 - d2 ) > distanceModifier ) {
			throw ImageReadException;
		}
	} catch ( exception & e ) {
		cout << e.what() << endl;
		int stop = 1;
		cout << "Program will now end. Press any key and enter to terminate." << endl;
		cin >> stop;
		exit( 0 );
	}
	
	// ---- Handling to fix problem of sideways-oriented image file ---- 
	
	// Boolean to assure program rotation has been dealt with, prevents extra work
	bool rotationHandled = false;
	
	// Horizontal distance between "top" two points
	float width1 = sqrt( UR.x - UL.x );
	// Vertical distance between "left" two points
	float height1 = sqrt( LL.y - UL.y );

	// If horizontal distace greater than vertical, then it's sideways
	if ( width1 > height1 ) {
		// Sum of both y distances from the points at the percieved page "top"
		double distanceFromLeft = UL.x + LL.x;
		// Sum of both y distances from the points at the percieved page "bottom"
		double distanceFromRight = ( ( examImage.cols * resRatioWidth ) - UR.x ) + 
			( ( examImage.cols * resRatioWidth ) - LR.x );
		// Temporary points for swapping corner points
		Point2f ULTemp;
		ULTemp = UL;
		// If image is angled 90 degrees clockwise
		if ( distanceFromLeft < distanceFromRight ) {
			UL = UR;
			UR = LR;
			LR = LL;
			LL = ULTemp;
		} else { // If image is angled 90 degrees counterclockwise
			UR = LR;
			LR = LL;
			LL = UL;
			UL = ULTemp;
		}
		rotationHandled = true;
	}
	

	// ---- Handling to fix problem of upside-down image file ----

	// If rotation hasn't already been dealt with
	if ( !rotationHandled ) {

		// Sum of both y distances from the points at the percieved page "top"
		double distanceFromTop = UL.y + UR.y;
		// Sum of both y distances from the points at the percieved page "bottom"
		double distanceFromBottom = ( ( examImage.rows * resRatioHeight )
			- LL.y ) + ( ( examImage.rows * resRatioHeight ) - LR.y );

		// If there is more distance from the bottom, ie. is upside down
		// Flip the points; used in perspective transform anyway, so it just
		// Adds a small step without being too processor-intensive
		if ( distanceFromTop < distanceFromBottom ) {
			Point2f ULTemp, URTemp;
			ULTemp = UL;
			URTemp = UR;
			UL = LR;
			UR = LL;
			LR = ULTemp;
			LL = URTemp;
		}
	}

	/*
	// Draw circles on points to verify accuracy (for testing)
	circle( examCopy, UL, 40, CV_RGB( 150, 250, 150 ), 7 );
	circle( examCopy, UR, 40, CV_RGB( 150, 250, 150 ), 7 );
	circle( examCopy, LL, 40, CV_RGB( 150, 250, 150 ), 7 );
	circle( examCopy, LR, 40, CV_RGB( 150, 250, 150 ), 7 );

	// Displays info visually (for testing)
	namedWindow( "c", 0 );
	imshow( "c", examCopy );
	waitKey( 0 );
	destroyAllWindows();
	*/
}

/// Adjust image orientation to be readable
void ImageEvaluator::cv_orientImage() {

	//Set up info for warp
	Point2f srcQuad[4], dstQuad[4];
	//Image clone of base image, used to calculate differences
	Mat examCloneForResize = examImage.clone();
	// Resizes the base image to follow
	resize( baseImage, examCloneForResize, examCloneForResize.size(),
		0, 0, INTER_LINEAR );
	// Copy of the exam image, used to create properly-oriented image
	Mat examCopy = examImage.clone();
	// Set up points for the source array
	srcQuad[0].x = float( mainUL.x * resRatioWidth ); //src Top left
	srcQuad[0].y = float( mainUL.y * resRatioHeight );
	srcQuad[1].x = float( mainUR.x * resRatioWidth ); //src Top right
	srcQuad[1].y = float( mainUR.y * resRatioHeight );
	srcQuad[2].x = float( mainLL.x * resRatioWidth ); //src Bottom left
	srcQuad[2].y = float( mainLL.y * resRatioHeight );
	srcQuad[3].x = float( mainLR.x * resRatioWidth );//src Bot right
	srcQuad[3].y = float( mainLR.y * resRatioHeight );

	// Set up points for the destination array
	dstQuad[ 0 ] = UL;
	dstQuad[ 1 ] = UR;
	dstQuad[ 2 ] = LL;
	dstQuad[ 3 ] = LR;

	//Get the transform information
	Mat warp_matrix = getPerspectiveTransform( srcQuad, dstQuad );
	//Apply an inverse perspective transform to normalize the exam image
	warpPerspective( examImage, examCopy, warp_matrix, examCopy.size(), WARP_INVERSE_MAP );

	// Recalculates the points, based on template image points and resolution
	UL = srcQuad[ 0 ];
	UR = srcQuad[ 1 ];
	LL = srcQuad[ 2 ];
	LR = srcQuad[ 3 ];

	//Set the exam image to the changed copy
	examImage = examCopy;

	/*
	namedWindow( "c", 0 );
	imshow( "c", examImage );
	waitKey( 0 );
	destroyAllWindows();
	*/
}

/// Getter for the exam image
Mat ImageEvaluator::getExamImage() const {
	return examImage;
}

/// Getter for the regions vector
vector< Rect > ImageEvaluator::getRegions() {
	return regions;
}

/// Copies the ImageEvaluator class
ImageEvaluator& ImageEvaluator::operator=( const ImageEvaluator &nIE ) {
	examImage = nIE.examImage;
	baseImage = nIE.baseImage;
	numQuestions = nIE.numQuestions;
	return *this;
}

// Newer read method - reads from a filename and returns completed image data
AssignmentImage ImageEvaluator::readImage( string filename ) {
	// TODO
	return AssignmentImage();
}

// Sets the name to be what was found in the exam image
void setName() {
	// TODO later
}

// Finds and sets the name letter regions on the exam
void setNameLetterRegions() {
	// TODO later
}

// Gets the letter found in the answer bubble region
char getNameLetter( Rect nameLetterRegion ) {
	// TODO later
}