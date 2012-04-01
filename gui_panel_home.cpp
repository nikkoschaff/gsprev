
#include "gui_panel_home.h"


///////////////////////////////////////////////////////////////////////////

gui_panel_home::gui_panel_home( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs_icon.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_bitmap2, 0, wxALL, 5 );
	
	button_quickgrade = new wxButton( this, wxID_ANY, wxT("Quick Grade"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( button_quickgrade, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	bSizer2->Add( fgSizer7, 0, 0, 5 );
	
	button_assignments = new wxButton( this, wxID_ANY, wxT("Assignments"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( button_assignments, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	button_students = new wxButton( this, wxID_ANY, wxT("Students"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( button_students, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	buttons_questbank = new wxButton( this, wxID_ANY, wxT("Question Bank"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( buttons_questbank, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	button_quickgrade->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuickGradeClick ), NULL, this );
	button_assignments->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onAssignmentsButtonClick ), NULL, this );
	button_students->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onStudentsButtonClick ), NULL, this );
	buttons_questbank->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuestBankButtonClick ), NULL, this );
}

gui_panel_home::~gui_panel_home()
{
	// Disconnect Events
	button_quickgrade->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuickGradeClick ), NULL, this );
	button_assignments->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onAssignmentsButtonClick ), NULL, this );
	button_students->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onStudentsButtonClick ), NULL, this );
	buttons_questbank->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuestBankButtonClick ), NULL, this );
	
}

