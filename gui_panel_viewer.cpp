

#include "gui_panel_viewer.h"



///////////////////////////////////////////////////////////////////////////

gui_panel_viewer::gui_panel_viewer( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	gsm = GradeSnapModel();
	gsm.setcurstudentid( gsm.getkeyid() );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	gs_icon = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../../Tussuad_Be/workspace/Projects/gs_gui/gs_icon.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( gs_icon, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Selected Test"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer15->Add( m_staticText3, 0, wxALL, 5 );
	
	panel_viewer_listbox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_ALWAYS_SB|wxLB_SINGLE ); 
	bSizer15->Add( panel_viewer_listbox, 1, wxALL, 5 );
	
	
	bSizer29->Add( bSizer15, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("IMG Selected"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer17->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer19->Add( 0, 0, 1, 0, 5 );
	
	
	bSizer17->Add( bSizer19, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	img_test = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("../../Tussuad_Be/workspace/Projects/gs_gui/gs_test.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( img_test, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	button_stats = new wxButton( this, wxID_ANY, wxT("Stats"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( button_stats, 0, wxALL, 5 );
	
	label_students_names = new wxStaticText( this, wxID_ANY, wxT("Student's first and last name"), wxDefaultPosition, wxDefaultSize, 0 );
	label_students_names->Wrap( -1 );
	label_students_names->SetFont( wxFont( 15, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer31->Add( label_students_names, 0, wxALL, 5 );
	
	name_input = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( name_input, 0, wxALL, 5 );
	
	label_grade = new wxStaticText( this, wxID_ANY, wxT("Grade:"), wxDefaultPosition, wxDefaultSize, 0 );
	label_grade->Wrap( -1 );
	label_grade->SetFont( wxFont( 15, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	bSizer31->Add( label_grade, 0, wxALL, 5 );
	
	grade_output = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer31->Add( grade_output, 0, wxALL, 5 );
	
	
	bSizer171->Add( bSizer31, 1, 0, 5 );
	
	
	bSizer30->Add( bSizer171, 1, wxEXPAND, 5 );
	
	
	bSizer17->Add( bSizer30, 0, 0, 5 );
	
	
	bSizer29->Add( bSizer17, 1, wxEXPAND, 5 );
	
	
	bSizer22->Add( bSizer29, 1, wxEXPAND, 5 );
	
	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	bSizer22->Add( m_gauge1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer22 );
	this->Layout();
	
	// Connect Events
	panel_viewer_listbox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_viewer::onListElementClicked ), NULL, this );
	button_stats->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_viewer::onStatsButtonClick ), NULL, this );
	name_input->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onStudentNameTextEnter ), NULL, this );
	grade_output->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onGradeTextEnter ), NULL, this );
}

gui_panel_viewer::~gui_panel_viewer()
{
	// Disconnect Events
	panel_viewer_listbox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( gui_panel_viewer::onListElementClicked ), NULL, this );
	button_stats->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_viewer::onStatsButtonClick ), NULL, this );
	name_input->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onStudentNameTextEnter ), NULL, this );
	grade_output->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( gui_panel_viewer::onGradeTextEnter ), NULL, this );
	
}

// refresh - currently-selected= display (w/info), populate sidebar list
void gui_panel_viewer::refreshInfo() {


	int curstudentrow = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", gsm.getselcurstudentid(),
		gsm.getassignmentid(), "StudentID", "AssignmentID" ).at( 0 ).c_str() );

	// TODO set image based on selstudentID
	wxString curstudenttest = wxString::FromAscii( DBManager::getDataObjectValue( 
		"LinkerStudentAssignment", curstudentrow, "filename").c_str() );


	// set sel name
	wxString curstudentname = wxString::FromAscii( DBManager::getDataObjectValue(
		"LinkerStudentAssignment", curstudentrow, "name" ).c_str() );
	name_input->SetLabelText( curstudentname );

	// set sel grade

	wxString curstudentgrade = wxString::FromAscii( DBManager::getDataObjectValue( 
		"LinkerStudentAssignment", curstudentrow, "grade" ).c_str() );
	grade_output->SetLabelText( curstudentgrade );


	// set panel_viewer_listbox to fill with studentIDs, with FIRST being keyID
	std::string studentname;
	int keyrow = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", gsm.getkeyid(),
		gsm.getassignmentid(), "StudentID", "AssignmentID" ).at( 0 ).c_str() );
	std::string keyfilename = DBManager::getDataObjectValue( "LinkerStudentAssignment", keyrow, "filename" );
	std::string keyname = gsm.getkeyid() + "-" + keyfilename;
	panel_viewer_listbox->SetString( 0, wxString::FromAscii( keyname.c_str() ) );
	for( unsigned int i = 1; i <gsm.getstudentids().size(); i++ ) {
		// Gets Id from the model, sets it to matching index position in the listbox
		int studentrow = atoi( DBManager::getLinkedValues( "LinkerStudentAssignment", gsm.getstudentids().at( i ),
			gsm.getassignmentid(), "StudentID", "AssignmentID" ).at( 0 ).c_str() );
		std::string filename = DBManager::getDataObjectValue( "LinkerStudentAssignment", studentrow, "filename" );

		studentname = gsm.getstudentids().at( i ) + "-" + filename;
		panel_viewer_listbox->SetString( i, wxString::FromAscii( studentname.c_str() ) );

	}

}

//callback for clicking on listbox/selecting test (calls refresh at the end)
void gui_panel_viewer::onListElementClicked( wxCommandEvent& event ) {


	int sel = panel_viewer_listbox->GetSelection();
	std::string selidstr = panel_viewer_listbox->GetString( sel );

	std::string idstr;
	// Get only the id portions
	int stridx = 0;
	while ( selidstr.at( stridx ) != '-' ) {
		// TODO make sure the comparison operator works
		idstr = idstr + selidstr.at( stridx );
		stridx++;
	}

	int id = atoi( idstr.c_str() );

	gsm.setcurstudentid( id );

	refreshInfo();
}

