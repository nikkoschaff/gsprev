///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb  9 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	// Initialize panels
	home = new gui_panel_home( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	home->Show();
	grade = new gui_panel_grade( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	grade->Hide();
	viewer = new gui_panel_viewer( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	viewer->Hide();
	stats = new gui_panel_stats( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	stats->Hide();

	bSizer51->Add( home, 1, wxEXPAND, 5 );
	bSizer51->Add( grade, 1, wxEXPAND, 5 );
	bSizer51->Add( viewer, 1, wxEXPAND, 5 );
	bSizer51->Add( stats, 1, wxEXPAND, 5 );

	this->SetSizer( bSizer51 );
	this->Layout();
	
	this->Centre( wxBOTH );

	// No way of knowing what those are... (which panel do they belong to?)
	home->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onQuickGradeClick ),
		NULL, this );
	grade->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onGradeButtonClick ),
		NULL, this );
	viewer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::onStatsButtonClick ),
		NULL, this );

	// TODO add "done" from stats
}

MainFrame::~MainFrame()
{
}

void MainFrame::onQuickGradeClick( wxCommandEvent& event ) {

	home->Hide();
	grade->Show();
	this->Update();
	this->Refresh();

}

void MainFrame::onGradeButtonClick( wxCommandEvent& event ) {

	// Switch panels
	grade->Hide();
	viewer->Show();
	this->Refresh();
	this->Update();
}


void MainFrame::onStatsButtonClick( wxCommandEvent& event ) {

	// Switch to stats panel
	viewer->Hide();
	stats->Show();
	this->Refresh();
	// Has stats panel compute stats
}