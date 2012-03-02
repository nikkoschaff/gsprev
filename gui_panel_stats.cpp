
#include "gui_panel_stats.h"

///////////////////////////////////////////////////////////////////////////

gui_panel_stats::gui_panel_stats( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* Header;
	Header = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap7 = new wxStaticBitmap( m_scrolledWindow1, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs.jpg.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	Header->Add( m_bitmap7, 0, wxALL, 5 );
	
	
	Header->Add( 0, 0, 1, wxEXPAND, 5 );
	
	button_done = new wxButton( m_scrolledWindow1, wxID_ANY, wxT("Done"), wxDefaultPosition, wxSize( 150,50 ), 0 );
	button_done->SetFont( wxFont( 15, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	Header->Add( button_done, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer28->Add( Header, 0, wxEXPAND, 5 );
	
	wxBoxSizer* stats_holder;
	stats_holder = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Mean:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer24->Add( m_staticText12, 0, wxALL, 5 );
	
	m_textCtrl7 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer24->Add( m_textCtrl7, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Median:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer24->Add( m_staticText13, 0, wxALL, 5 );
	
	m_textCtrl8 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer24->Add( m_textCtrl8, 0, wxALL, 5 );
	
	
	bSizer22->Add( bSizer24, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer26->Add( m_staticText14, 0, wxALL, 5 );
	
	m_textCtrl9 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer26->Add( m_textCtrl9, 0, wxALL, 5 );
	
	m_staticText15 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Frequency: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer26->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrl10 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer26->Add( m_textCtrl10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer22->Add( bSizer26, 1, wxEXPAND, 5 );
	
	
	stats_holder->Add( bSizer22, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	
	stats_holder->Add( bSizer23, 1, wxEXPAND, 5 );
	
	
	bSizer28->Add( stats_holder, 0, wxEXPAND, 5 );
	
	wxBoxSizer* graph_holder;
	graph_holder = new wxBoxSizer( wxVERTICAL );
	
	m_staticText16 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Distribution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	m_staticText16->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	graph_holder->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bitmap6 = new wxStaticBitmap( m_scrolledWindow1, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs.jpg.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	graph_holder->Add( m_bitmap6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer28->Add( graph_holder, 1, wxEXPAND, 5 );
	
	wxBoxSizer* Accuracy_holder;
	Accuracy_holder = new wxBoxSizer( wxVERTICAL );
	
	m_staticText17 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Accuracy:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	m_staticText17->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	Accuracy_holder->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bitmap8 = new wxStaticBitmap( m_scrolledWindow1, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs.jpg.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	Accuracy_holder->Add( m_bitmap8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer28->Add( Accuracy_holder, 0, wxEXPAND, 5 );
	
	wxBoxSizer* norm_dist_holder;
	norm_dist_holder = new wxBoxSizer( wxVERTICAL );
	
	m_staticText18 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Distribution Curve:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	m_staticText18->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	norm_dist_holder->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bitmap9 = new wxStaticBitmap( m_scrolledWindow1, wxID_ANY, wxBitmap( wxT("Visual Studio 2010/Projects/GradeSnapMain/GradeSnapMain/gs.jpg.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	norm_dist_holder->Add( m_bitmap9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer28->Add( norm_dist_holder, 0, wxEXPAND, 5 );
	
	
	m_scrolledWindow1->SetSizer( bSizer28 );
	m_scrolledWindow1->Layout();
	bSizer28->Fit( m_scrolledWindow1 );
	bSizer20->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer20 );
	this->Layout();
	
	// Connect Events
	button_done->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_stats::onDoneButtonClick ), NULL, this );
}

gui_panel_stats::~gui_panel_stats()
{
	// Disconnect Events
	button_done->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( gui_panel_stats::onDoneButtonClick ), NULL, this );
	
}
