
#include "gui_panel_grade.h"

///////////////////////////////////////////////////////////////////////////


gui_panel_grade::gui_panel_grade( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap5 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs.jpg.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_bitmap5, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Name: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer16->Add( m_staticText9, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Number of questions: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer16->Add( m_staticText10, 0, wxALL, 5 );
	
	
	bSizer14->Add( bSizer16, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	name_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	name_input->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer15->Add( name_input, 0, wxALL, 5 );
	
	num_quest_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	num_quest_input->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer15->Add( num_quest_input, 0, wxALL, 5 );
	
	
	bSizer14->Add( bSizer15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer10->Add( bSizer14, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Select Tests"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	m_staticText8->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer13->Add( m_staticText8, 0, wxALL, 5 );
	
	m_button10 = new wxButton( this, wxID_ANY, wxT("Browse"), wxDefaultPosition, wxSize( 150,40 ), 0 );
	bSizer13->Add( m_button10, 0, wxALL, 5 );
	
	
	bSizer10->Add( bSizer13, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxArrayString m_checkList1Choices;
	m_checkList1 = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 290,250 ), m_checkList1Choices, wxLB_HSCROLL|wxLB_MULTIPLE|wxLB_NEEDED_SB|wxLB_SORT );
	bSizer10->Add( m_checkList1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer19->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer19->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button11 = new wxButton( this, wxID_ANY, wxT("Grade"), wxDefaultPosition, wxSize( 150,40 ), 0 );
	bSizer19->Add( m_button11, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer10->Add( bSizer19, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	// Connect Events
	name_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNameTextEnter ), NULL, this );
	num_quest_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNumQuestionsTextEnter ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onBrowseClick ), NULL, this );
	m_checkList1->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_grade::onListElementSelected ), NULL, this );
	m_checkList1->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( gui_panel_grade::onCheckListBoxToggled ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onGradeButtonClick ), NULL, this );
}

gui_panel_grade::~gui_panel_grade()
{
	// Disconnect Events
	name_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNameTextEnter ), NULL, this );
	num_quest_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNumQuestionsTextEnter ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onBrowseClick ), NULL, this );
	m_checkList1->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_grade::onListElementSelected ), NULL, this );
	m_checkList1->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( gui_panel_grade::onCheckListBoxToggled ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onGradeButtonClick ), NULL, this );
	
}