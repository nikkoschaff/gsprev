
#include "gui_panel_grade.h"

///////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////

gui_panel_grade::gui_panel_grade( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	//m_bitmap5 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs_icon.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	//bSizer10->Add( m_bitmap5, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Name: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer16->Add( m_staticText9, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Number of questions: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer16->Add( m_staticText10, 0, wxALL, 5 );
	
	
	bSizer14->Add( bSizer16, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	name_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	name_input->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer15->Add( name_input, 0, wxALL, 5 );
	
	num_quest_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	num_quest_input->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer15->Add( num_quest_input, 0, wxALL, 5 );
	
	
	bSizer14->Add( bSizer15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer10->Add( bSizer14, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Select Tests: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	m_staticText8->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer13->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	browse = new wxButton( this, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( browse, 0, wxEXPAND, 5 );

	

	bSizer10->Add( bSizer13, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxArrayString panel_grade_listboxChoices;
	panel_grade_listbox = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 450,250 ), panel_grade_listboxChoices, wxLB_ALWAYS_SB|wxLB_HSCROLL|wxLB_SINGLE );
	panel_grade_listbox->SetFont( wxFont( 15, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer10->Add( panel_grade_listbox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* sizer_grade_button_holder;
	sizer_grade_button_holder = new wxBoxSizer( wxHORIZONTAL );
	
	
	sizer_grade_button_holder->Add( 0, 0, 1, wxEXPAND, 5 );
	
	panel_grade_gradebutton = new wxButton( this, wxID_ANY, wxT("Grade"), wxDefaultPosition, wxSize( 150,40 ), 0 );
	sizer_grade_button_holder->Add( panel_grade_gradebutton, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizer_grade_button_holder->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer10->Add( sizer_grade_button_holder, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	// Connect Events
	name_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNameTextEnter ), NULL, this );
	num_quest_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNumQuestionsTextEnter ), NULL, this );
	panel_grade_listbox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_grade::onListElementSelected ), NULL, this );
	panel_grade_listbox->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( gui_panel_grade::onCheckListBoxToggled ), NULL, this );
	panel_grade_gradebutton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onGradeButtonClick ), NULL, this );

	browse->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::OnBrowseClick ), NULL, this );
}

gui_panel_grade::~gui_panel_grade()
{
	// Disconnect Events
	name_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNameTextEnter ), NULL, this );
	num_quest_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNumQuestionsTextEnter ), NULL, this );
	panel_grade_listbox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_grade::onListElementSelected ), NULL, this );
	panel_grade_listbox->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( gui_panel_grade::onCheckListBoxToggled ), NULL, this );
	panel_grade_gradebutton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onGradeButtonClick ), NULL, this );
	

	browse->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::OnBrowseClick ), NULL, this );
}


void gui_panel_grade::OnBrowseClick( wxCommandEvent& event ) {
	wxFileDialog *picker = new wxFileDialog( this, wxT("Select a file"), wxEmptyString, wxEmptyString, wxT("*.*"), wxFLP_OPEN|wxFD_MULTIPLE );

	if( picker->ShowModal() == wxID_OK ) {
		wxArrayString fnames;
		picker->GetFilenames( fnames );
		panel_grade_listbox->InsertItems( fnames, panel_grade_listbox->GetCount() );
	}
}


// finalize data and grade, then progress to next window
void gui_panel_grade::onGradeButtonClick( wxCommandEvent& event ) {

	// TODO make warning dialog if no test was selected
	if( panel_grade_listbox->GetSelection() == wxNOT_FOUND ) {
		wxDialog( this, wxID_ANY, wxT( "Warning! - No test selected!" ) );
	}

	int classID = 1;
	int keyID;
	int assignmentID;
	string numQuestions = num_quest_input->GetValue().ToStdString();
	std::vector< std::pair< int, std::string > > studentFilePairs;
	string keyFilename = panel_grade_listbox->GetString( panel_grade_listbox->GetSelection() ).ToStdString();

	// get assignment name and numQ into test
	assignmentID = DBManager::makeDataObject( "Assignment", name_input->GetValue().ToStdString() );
	DBManager::setDataObjectValue( "Assignment", assignmentID, "numQuestions", numQuestions );

	// Create key, link to assignment, set filename
	keyID =	DBManager::makeDataObject( "Student", keyFilename );

	DBManager::linkAToB( "LinkerStudentAssignment", assignmentID, "AssignmentID", 
		keyID, "StudentID" );
	DBManager::setLinkedValues( "LinkerStudentAssignment", keyID, assignmentID, 
		"StudentID", "AssignmentID", "key", "YES" );
	DBManager::setLinkedValues( "LinkerStudentAssignment", keyID, assignmentID,
		"StudentID", "AssignmentID", "filename", keyFilename );

	// Pair for use in the model
	pair< int, string > keyFilePair( keyID, keyFilename );

	// Vector of student IDs
	vector< int > studentIDs;

	vector< string > studentExamFilenames;

	int selidx = panel_grade_listbox->GetSelection();

	// Gets filenames from the listbox and places into exam filename vector
	for( unsigned int i = 0; i < panel_grade_listbox->GetCount(); i++ ) {
		if( i != selidx ) {
			studentExamFilenames.push_back( panel_grade_listbox->GetString( i ).ToStdString() );
		}
	}


	// Gets student IDs by setting them to be in the DB and finding their ID
	//	Links the necessary student data and pushes their info into the pair vector
	for( unsigned int i = 0; i < studentExamFilenames.size(); i++ ) {
		string name = studentExamFilenames.at( i );

		// Extracts information about the studentID and places corresponding
		//	student data into the database
		int sID = DBManager::makeDataObject( "Student", name );
		DBManager::linkAToB( "LinkerStudentAssignment", assignmentID, "AssignmentID", 
			sID, "StudentID" );
		DBManager::linkAToB( "LinkerClassStudent", classID, "ClassID", sID, "StudentID" );
		DBManager::setLinkedValues( "LinkerStudentAssignment", sID, assignmentID,
			"StudentID", "AssignmentID", "filename", name );
		// Pushes student ID and name to the student pair vector
		studentFilePairs.push_back( pair< int, string >( sID, name ) );
		studentIDs.push_back( sID );
	}

	// Grade via gsm
	GradeSnapModel gsm;
	gsm.evaluateImage( assignmentID, classID, keyFilePair, studentFilePairs, atoi( numQuestions.c_str() ) );


	// Save values in gsm
	gsm.setkeyid( keyID );
	gsm.setassignmentid( assignmentID );
	gsm.setstudentids( studentIDs );
	gsm.setcurstudentid( gsm.getkeyid() );
	
	event.Skip();
}