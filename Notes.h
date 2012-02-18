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
	1: "name" in Student (needed for getIDFromName, not needed now)
	2: 
****4: TOOO assignment - set Key, score vector for students


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
		1: Finish EvalHelper.cpp (filesystem, DB - finding studentID)

III: Image Evaluator -> modify to work with new image, and apply needed changes
		(more to be added as needed)










































*/