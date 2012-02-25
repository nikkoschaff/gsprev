/*

$$$1: TODO reflect changes: 
	A: Teacher.h to match DD
	B: only answers, no questions for now (reflect in DD)
	C: reflect changes in DD (q/a now in vector, not map)
	D: reflect changes in DD (no private EvalHelper in class)
$$$3: Set standards

I: TODO


1: The ID-getter only goes to the first possible one.  Other problems show up	
	like blanks table spaces, but that's because only the first IDNUM in the full
	possible set gets returned.  This should either be changed or at least understood
	throughout the program
2: The Model, when working with new inputs within the system, MUST, I REPEAT, MUST know
	everything about the associations as they need to know to extrapolate.  Although
	having the user select from a displayed list the options that reflect db entries,
	and letting that list send through to the model is easy to work with and doesn't
	involve searching or predicting, any action within the model that doesn't have user
	input *******MUST******* already know the IDs, or else it will completely crash and burn
	when it tries to predict them.
			->getIDfromValue *may* possibly be a useless or unpredictable function
3:	Grades don't seem to be accurate when setting in DB.  See if it's a translation problem
	or if they're not being graded properly from the get-go



	A: Better ID-maker in GS
	C: Finish GSM printresults()


	A: Make table/db clearing function in DBM
	B: Clear table/db at onset after load in GS



II: Database concerns
	1: What happens if searching out of index or availability? (or at a table that doesn't exist)
		-> BREAKS if asking for something that doesn't exist
	2: It's easy to have linked duplicates.  Would that also unnecessarily duplicate searches?



III: Image Evaluator -> modify to work with new image, and apply needed changes
		(more to be added as needed)










































*/