
#include "gui_panel_stats.h"

///////////////////////////////////////////////////////////////////////////

gui_panel_stats::gui_panel_stats( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	stats_scrolled_window = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	stats_scrolled_window->SetScrollRate( 5, 5 );
	stats_scrolled_window->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* gui_panel_stats_sizer_main;
	gui_panel_stats_sizer_main = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* sizer_header;
	sizer_header = new wxBoxSizer( wxHORIZONTAL );
	
	gs_icon = new wxStaticBitmap( stats_scrolled_window, wxID_ANY, wxBitmap( wxT("../../Tussuad_Be/workspace/Projects/gs_gui/gs_icon.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sizer_header->Add( gs_icon, 0, wxALL, 5 );
	
	
	sizer_header->Add( 0, 0, 1, wxEXPAND, 5 );
	
	button_done = new wxButton( stats_scrolled_window, wxID_ANY, wxT("Done"), wxDefaultPosition, wxSize( 150,50 ), 0 );
	button_done->SetFont( wxFont( 15, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_header->Add( button_done, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	gui_panel_stats_sizer_main->Add( sizer_header, 0, wxEXPAND, 5 );
	
	wxBoxSizer* sizer_stats_holder;
	sizer_stats_holder = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* sizer_stats_holder_organizer;
	sizer_stats_holder_organizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* sizer_label_organizer1;
	sizer_label_organizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText12 = new wxStaticText( stats_scrolled_window, wxID_ANY, wxT("Mean:   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	m_staticText12->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_label_organizer1->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText13 = new wxStaticText( stats_scrolled_window, wxID_ANY, wxT("Median: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_label_organizer1->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText14 = new wxStaticText( stats_scrolled_window, wxID_ANY, wxT("Mode:   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_label_organizer1->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizer_stats_holder_organizer->Add( sizer_label_organizer1, 0, 0, 5 );
	
	wxBoxSizer* sizer_textfield_organizer1;
	sizer_textfield_organizer1 = new wxBoxSizer( wxVERTICAL );
	
	mean_output = new wxTextCtrl( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	sizer_textfield_organizer1->Add( mean_output, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	median_output = new wxTextCtrl( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	sizer_textfield_organizer1->Add( median_output, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	mode_output = new wxTextCtrl( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	sizer_textfield_organizer1->Add( mode_output, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizer_stats_holder_organizer->Add( sizer_textfield_organizer1, 0, 0, 5 );
	
	wxBoxSizer* sizer_label_organizer2;
	sizer_label_organizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText15 = new wxStaticText( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	m_staticText15->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_label_organizer2->Add( m_staticText15, 0, wxALL, 5 );
	
	m_staticText161 = new wxStaticText( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText161->Wrap( -1 );
	m_staticText161->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_label_organizer2->Add( m_staticText161, 0, wxALL, 5 );
	
	Frequency = new wxStaticText( stats_scrolled_window, wxID_ANY, wxT("Frequency: "), wxDefaultPosition, wxDefaultSize, 0 );
	Frequency->Wrap( -1 );
	Frequency->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_label_organizer2->Add( Frequency, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	sizer_stats_holder_organizer->Add( sizer_label_organizer2, 0, 0, 5 );
	
	wxBoxSizer* sizer_textfield_organizer2;
	sizer_textfield_organizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1611 = new wxStaticText( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1611->Wrap( -1 );
	m_staticText1611->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_textfield_organizer2->Add( m_staticText1611, 0, wxALL, 5 );
	
	m_staticText1612 = new wxStaticText( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1612->Wrap( -1 );
	m_staticText1612->SetFont( wxFont( 13, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_textfield_organizer2->Add( m_staticText1612, 0, wxALL, 5 );
	
	frequency_output = new wxTextCtrl( stats_scrolled_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	sizer_textfield_organizer2->Add( frequency_output, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizer_stats_holder_organizer->Add( sizer_textfield_organizer2, 1, wxEXPAND, 5 );
	
	
	sizer_stats_holder->Add( sizer_stats_holder_organizer, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	gui_panel_stats_sizer_main->Add( sizer_stats_holder, 0, wxEXPAND, 5 );
	
	wxBoxSizer* sizer_pie_holder;
	sizer_pie_holder = new wxBoxSizer( wxVERTICAL );
	
	staticText_chart = new wxStaticText( stats_scrolled_window, wxID_ANY, wxT("Chart:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText_chart->Wrap( -1 );
	staticText_chart->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_pie_holder->Add( staticText_chart, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bitmap6 = new wxStaticBitmap( stats_scrolled_window, wxID_ANY, wxBitmap( wxT("gs_pie2.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sizer_pie_holder->Add( m_bitmap6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	gui_panel_stats_sizer_main->Add( sizer_pie_holder, 1, wxEXPAND, 5 );
	
	wxBoxSizer* sizer_accuracy_holder;
	sizer_accuracy_holder = new wxBoxSizer( wxVERTICAL );
	
	staticText_accuracy = new wxStaticText( stats_scrolled_window, wxID_ANY, wxT("Accuracy:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText_accuracy->Wrap( -1 );
	staticText_accuracy->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_accuracy_holder->Add( staticText_accuracy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bitmap8 = new wxStaticBitmap( stats_scrolled_window, wxID_ANY, wxBitmap( wxT("../../Tussuad_Be/workspace/Projects/gs_gui/gs_accuracy.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sizer_accuracy_holder->Add( m_bitmap8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	gui_panel_stats_sizer_main->Add( sizer_accuracy_holder, 0, wxEXPAND, 5 );
	
	wxBoxSizer* sizer_norm_dist_holder;
	sizer_norm_dist_holder = new wxBoxSizer( wxVERTICAL );
	
	staticText_normaldist = new wxStaticText( stats_scrolled_window, wxID_ANY, wxT("Distribution Curve:"), wxDefaultPosition, wxDefaultSize, 0 );
	staticText_normaldist->Wrap( -1 );
	staticText_normaldist->SetFont( wxFont( 20, 74, 90, 90, false, wxT("MS Shell Dlg 2") ) );
	
	sizer_norm_dist_holder->Add( staticText_normaldist, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_bitmap9 = new wxStaticBitmap( stats_scrolled_window, wxID_ANY, wxBitmap( wxT("../../Tussuad_Be/workspace/Projects/gs_gui/gs_distr.gif"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	sizer_norm_dist_holder->Add( m_bitmap9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	gui_panel_stats_sizer_main->Add( sizer_norm_dist_holder, 0, wxEXPAND, 5 );
	
	
	stats_scrolled_window->SetSizer( gui_panel_stats_sizer_main );
	stats_scrolled_window->Layout();
	gui_panel_stats_sizer_main->Fit( stats_scrolled_window );
	bSizer20->Add( stats_scrolled_window, 1, wxEXPAND | wxALL, 5 );
	
	
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
