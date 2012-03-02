#ifndef GUI_PANEL_STATS_H_
#define GUI_PANEL_STATS_H_


#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/scrolwin.h>
#include <wx/panel.h>
#include <wx/imagjpeg.h>

#include "DBManager.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class gui_panel_stats
///////////////////////////////////////////////////////////////////////////////
class gui_panel_stats : public wxPanel 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow1;
		wxStaticBitmap* m_bitmap7;
		wxButton* button_done;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCtrl7;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textCtrl8;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_textCtrl9;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_textCtrl10;
		wxStaticText* m_staticText16;
		wxStaticBitmap* m_bitmap6;
		wxStaticText* m_staticText17;
		wxStaticBitmap* m_bitmap8;
		wxStaticText* m_staticText18;
		wxStaticBitmap* m_bitmap9;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onDoneButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		gui_panel_stats( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxTAB_TRAVERSAL ); 
		~gui_panel_stats();
	
};


#endif