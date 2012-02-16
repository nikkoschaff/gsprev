/*

!!!!!!1: TODO set up Sqlite DB early - any changes arising from that should be made early
1: TODO Establish Serialization method (at least for IDs)
2: TODO reflect changes in Teacher.h to match DD
4: TODO only answers, no questions for now (reflect in DD)
5: TODO reflect changes in DD (q/a now in vector, not map)
6: TODO reflect changes in DD (no private EvalHelper in class)
7: TODO design and implement filesystem storage method.  Could match #9
8: TODO Make a list/map of student info fields (configurable by user), storing it
	and the ID for the DB in student, so it's a configurable file that works with data
9: (consider) dataClass interface, so all reading/writing classes can be sure to
	have their own implementation of the method.  That way dataClasses can be constructed
	raw, and have their info read in (if the ID number exists).  That way no manager
	class has to do it for them.  It also could be possible to implement a Factory pattern,
	though having the read/write to DB functions be private could override the necessity.
10: TODO consider zipping and/or compressing image file to save space

I: Stubbing & initial build

	A: Teacher
		1: Finish Teacher.cpp (ID)

	B: Class
		1: Finish Class.cpp (ID, implementation)

	C: Assignment
		1: Finish Assignment.cpp (ID, implementation)

	E: EvalHelper
		1: Finish EvalHelper.cpp (implementation)

	G: ImageEvaluator (Special case - just needs extra implementation & cleanup)
		1: Finish ImageEvaluator.h
		2: Finish ImageEvaluator.cpp

II: Database -> Implement (more to do as needed)


III: Image Evaluator -> modify to work with new image, and apply needed changes
		(more to be added as needed)










































*/