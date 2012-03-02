
#include "gui_panel_home.h"


///////////////////////////////////////////////////////////////////////////

gui_panel_home::gui_panel_home( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("gs.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_bitmap2, 0, wxALL, 5 );
	
	Quick_Grade = new wxButton( this, wxID_ANY, wxT("Quick Grade"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( Quick_Grade, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	bSizer2->Add( fgSizer7, 0, 0, 5 );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Assignments"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( m_button6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Students"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( m_button7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button8 = new wxButton( this, wxID_ANY, wxT("Question Bank"), wxDefaultPosition, wxSize( 250,80 ), 0 );
	bSizer2->Add( m_button8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	Quick_Grade->Connect( Quick_Grade->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuickGradeClick ), NULL, this );
	m_button6->Connect( m_button6->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onAssignmentsButtonClick ), NULL, this );
	m_button7->Connect( m_button7->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onStudentsButtonClick ), NULL, this );
	m_button8->Connect( m_button8->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuestBankButtonClick ), NULL, this );
}

gui_panel_home::~gui_panel_home()
{
	// Disconnect Events
	Quick_Grade->Disconnect( Quick_Grade->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuickGradeClick ), NULL, this );
	m_button6->Disconnect(  m_button6->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onAssignmentsButtonClick ), NULL, this );
	m_button7->Disconnect(m_button7->GetId(),  wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onStudentsButtonClick ), NULL, this );
	m_button8->Disconnect( m_button8->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_home::onQuestBankButtonClick ), NULL, this );
	
}


void gui_panel_home::onQuickGradeClick( wxCommandEvent& event ) {

	if( event.GetId() == Quick_Grade->GetId() ) {
		event.Skip();
	} else {
		event.StopPropagation();
	}
}

void gui_panel_home::onAssignmentsButtonClick( wxCommandEvent& event ) {
	if( event.GetId() == m_button6->GetId() ) {
		event.Skip();
	} else {
		event.StopPropagation();
	}
}

void gui_panel_home::onStudentsButtonClick( wxCommandEvent& event ) {
	if( event.GetId() == m_button7->GetId() ) {
		event.Skip();
	} else {
		event.StopPropagation();
	}
}

void gui_panel_home::onQuestBankButtonClick( wxCommandEvent& event ) {
	if( event.GetId() == m_button8->GetId() ) {
		event.Skip();
	} else {
		event.StopPropagation();
	}
}