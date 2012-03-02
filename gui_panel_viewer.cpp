
#include "gui_panel_viewer.h"


///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

gui_panel_viewer::gui_panel_viewer( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_bitmap4 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs.jpg.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_bitmap4, 0, wxALL, 5 );
	
				
	fgSizer9->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Selected Test"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer15->Add( m_staticText3, 0, wxALL, 5 );
	
	m_listBox1 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_SINGLE ); 
	bSizer15->Add( m_listBox1, 1, wxALL, 5 );
	
	
	fgSizer9->Add( bSizer15, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer10->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("IMG Selected"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer17->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer19->Add( 0, 0, 1, 0, 5 );
	
	m_button9 = new wxButton( this, wxID_ANY, wxT("Stats"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button9, 0, wxALL, 5 );
	
	
	bSizer17->Add( bSizer19, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	img_test = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs.jpg.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( img_test, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxVERTICAL );
	
	label_students_names = new wxStaticText( this, wxID_ANY, wxT("Student's first and last name"), wxDefaultPosition, wxDefaultSize, 0 );
	label_students_names->Wrap( -1 );
	label_students_names->SetFont( wxFont( 8, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	label_students_names->SetMinSize( wxSize( 100,30 ) );
	
	bSizer171->Add( label_students_names, 0, wxALL, 5 );
	
	name_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( name_input, 0, wxALL, 5 );
	
	label_grade = new wxStaticText( this, wxID_ANY, wxT("Grade:"), wxDefaultPosition, wxDefaultSize, 0 );
	label_grade->Wrap( -1 );
	label_grade->SetFont( wxFont( 8, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer171->Add( label_grade, 0, wxALL, 5 );
	
	grade_output = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer171->Add( grade_output, 0, wxALL, 5 );
	
	
	fgSizer11->Add( bSizer171, 1, wxEXPAND, 5 );
	
	
	bSizer17->Add( fgSizer11, 0, 0, 5 );
	
	
	fgSizer10->Add( bSizer17, 1, 0, 5 );
	
	
	fgSizer9->Add( fgSizer10, 1, wxEXPAND, 5 );
	
	
	bSizer22->Add( fgSizer9, 1, wxEXPAND, 5 );
	
	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	bSizer22->Add( m_gauge1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer22 );
	this->Layout();
	
	// Connect Events
	m_listBox1->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_viewer::onListElementClicked ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_viewer::onStatsButtonClick ), NULL, this );
	name_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onStudentNameTextEnter ), NULL, this );
	grade_output->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onGradeTextEnter ), NULL, this );
}

gui_panel_viewer::~gui_panel_viewer()
{
	// Disconnect Events
	m_listBox1->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_viewer::onListElementClicked ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_viewer::onStatsButtonClick ), NULL, this );
	name_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onStudentNameTextEnter ), NULL, this );
	grade_output->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onGradeTextEnter ), NULL, this );
	
}