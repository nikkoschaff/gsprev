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



I: DB-STUFF (Issues)
	A: Things I need to know how to do
		8: HOW TO STORE SELECT DATA - WORK WITH CALLBACK

	B: Notes on doing stuff
		1: When concatenating strings with integers, use output streams


	C: Todos
		1: Make generalized make-thing method
		2: Make generalized remove-thing method
		3: Make generalized set value method
		4: Make gernalized get value method
		5: Make generalied set AllValue method
		6: Make gerneralized get AllValue method
		7: Make generalized getter - things-of-that method
		8: Make generalized setter - things-of-that method


II: Stubbing & initial build

	A: DBManager - Finish 
		// TODO make getter/setter functions for each - use generic methods up top


	B: EvalHelper
		1: Finish EvalHelper.cpp (filesystem, DB - finding studentID)

III: Image Evaluator -> modify to work with new image, and apply needed changes
		(more to be added as needed)










































*/