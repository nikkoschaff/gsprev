

#include "GradeSnapApp.h"
#include "MainFrame.h"


IMPLEMENT_APP(GradeSnapApp);


bool GradeSnapApp::OnInit()
{
	DBManager::db_init();
	
	// Creates the main frame and sets it as the top-level window
	MainFrame *mainFrame = new MainFrame( NULL, wxID_ANY, wxT("GradeSnap") );
	mainFrame->Show( true );
	
    return TRUE;
} 
 
/*
int GradeSnapApp::OnExit() {

	DBManager::db_close();

	return (0);
}
*/