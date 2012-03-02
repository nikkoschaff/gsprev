
#include "gui_panel_grade.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

gui_panel_grade::gui_panel_grade( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap5 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../../Tussuad_Be/workspace/Projects/gs_gui/gs_icon.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	
	bSizer14->Add( bSizer15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer10->Add( bSizer14, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Select Tests: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	m_staticText8->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer13->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	filePicker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer13->Add( filePicker, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer10->Add( bSizer13, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxArrayString panel_grade_listboxChoices;
	panel_grade_listbox = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 450,250 ), panel_grade_listboxChoices, wxLB_ALWAYS_SB|wxLB_HSCROLL|wxLB_SINGLE|wxLB_SORT );
	panel_grade_listbox->SetFont( wxFont( 15, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer10->Add( panel_grade_listbox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* sizer_grade_button_holder;
	sizer_grade_button_holder = new wxBoxSizer( wxHORIZONTAL );
	
	
	sizer_grade_button_holder->Add( 0, 0, 1, wxEXPAND, 5 );
	
	panel_grade_gradebutton = new wxButton( this, wxID_ANY, wxT("Grade"), wxDefaultPosition, wxSize( 150,40 ), 0 );
	sizer_grade_button_holder->Add( panel_grade_gradebutton, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizer_grade_button_holder->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer10->Add( sizer_grade_button_holder, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	// Connect Events
	name_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNameTextEnter ), NULL, this );
	num_quest_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNumQuestionsTextEnter ), NULL, this );
	filePicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( gui_panel_grade::OnFileChanged ), NULL, this );
	panel_grade_listbox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_grade::onListElementSelected ), NULL, this );
	panel_grade_listbox->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( gui_panel_grade::onCheckListBoxToggled ), NULL, this );
	panel_grade_gradebutton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onGradeButtonClick ), NULL, this );
}

gui_panel_grade::~gui_panel_grade()
{
	// Disconnect Events
	name_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNameTextEnter ), NULL, this );
	num_quest_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_grade::onNumQuestionsTextEnter ), NULL, this );
	filePicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( gui_panel_grade::OnFileChanged ), NULL, this );
	panel_grade_listbox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_grade::onListElementSelected ), NULL, this );
	panel_grade_listbox->Disconnect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( gui_panel_grade::onCheckListBoxToggled ), NULL, this );
	panel_grade_gradebutton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_grade::onGradeButtonClick ), NULL, this );
	
}