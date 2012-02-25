/*

$$$1: TODO reflect changes: 
	A: Teacher.h to match DD
	B: only answers, no questions for now (reflect in DD)
	C: reflect changes in DD (q/a now in vector, not map)
	D: reflect changes in DD (no private EvalHelper in class)
$$$3: Set standards

I: TODO
	A: Verify: store answers after directly after grading - good or bad idea?

	B: Problem - Using names as a way to store new stuff in the DB is a bad idea
		-> Any identical names just throw it all off.  
		Solution? 
			-> Make the makeDataObject method return the interger value of new row

II: Database concerns
	1: What happens if searching out of index or availability? (or at a table that doesn't exist)
		-> BREAKS if asking for something that doesn't exist
	2: It's easy to have linked duplicates.  Would that also unnecessarily duplicate searches?
	


III: Image Evaluator -> modify to work with new image, and apply needed changes
		(more to be added as needed)










































*/