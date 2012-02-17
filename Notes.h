/*

$$$1: TODO reflect changes: 
	A: Teacher.h to match DD
	B: only answers, no questions for now (reflect in DD)
	C: reflect changes in DD (q/a now in vector, not map)
	D: reflect changes in DD (no private EvalHelper in class)
$$$2: TODO handle issue - 2d mapping of data from datafield
	ex: map<field,value>fields.(handInDate)->map<studentID,date>
	^ This would be stored as a table of.... integers?  It has to be
		Within the table, yet it would need to be a table within the table
	SOLUTION -> store primary key of associated map of correct keys
	ex: map<field,value>fields.(handInDate)->handInPrimaryKey->(table of <studentID,date>
$$$3: Set standards
	1: NOTE: "name" in Student (needed for getIDFromName, not needed now)
***4: TODO handle issue -> how to grade and assign name if names already known 
	internally, and not using recognition to find name from sheet?
	TRY Mapping to a pair<studentID,filename>, where studentID wouldnt be necessary
		all times, making filenames more versatile

I: Stubbing & initial build

	A: Teacher
		1: Finish Teacher.cpp (DB)

	B: Class
		1: Finish Class.cpp (DB)

	C: Assignment
		1: Finish Assignment.cpp (DB)

	D: Student
		1: Finish Student.cpp (DB)

	E: EvalHelper
		1: Finish EvalHelper.cpp (implementation [filename/StudentID])

	G: ImageEvaluator (Special case - just needs extra implementation & cleanup)
		1: Finish ImageEvaluator.h
		2: Finish ImageEvaluator.cpp

II: Database -> Implement (more to do as needed)


III: Image Evaluator -> modify to work with new image, and apply needed changes
		(more to be added as needed)










































*/