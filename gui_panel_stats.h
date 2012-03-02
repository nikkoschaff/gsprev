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
		wxScrolledWindow* stats_scrolled_window;
		wxStaticBitmap* gs_icon;

		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxTextCtrl* mean_output;
		wxTextCtrl* median_output;
		wxTextCtrl* mode_output;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText161;
		wxStaticText* Frequency;
		wxStaticText* m_staticText1611;
		wxStaticText* m_staticText1612;
		wxTextCtrl* frequency_output;
		wxStaticText* staticText_chart;
		wxStaticBitmap* m_bitmap6;
		wxStaticText* staticText_accuracy;
		wxStaticBitmap* m_bitmap8;
		wxStaticText* staticText_normaldist;
		wxStaticBitmap* m_bitmap9;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onDoneButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		gui_panel_stats( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxTAB_TRAVERSAL ); 
		~gui_panel_stats();
		
		wxButton* button_done;
};



#endif