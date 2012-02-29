

#include "GradeSnapMain.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_Quit, MainFrame::OnQuit)
    EVT_MENU(ID_About, MainFrame::OnAbout)
END_EVENT_TABLE()
 
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	DBManager::db_init();

    MainFrame *mainFrame = new MainFrame( "GradeSnap", 
         wxPoint(50,50), wxSize(1024,800) );
    mainFrame->Show(TRUE);
    SetTopWindow(mainFrame);
    return TRUE;
} 
 

MainFrame::MainFrame(const wxString& title, 
       const wxPoint& pos, const wxSize& size)
: wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append( ID_About, "&About..." );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, "E&xit" );
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
 
    SetMenuBar( menuBar );

	CreateStatusBar();
	SetStatusText( "Ready" );
}

 
void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	DBManager::db_close();

    Close(TRUE);
}
 
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{

    wxMessageBox("This is a wxWindows Hello world sample",
        "About Hello World", wxOK | wxICON_INFORMATION, this);
}
