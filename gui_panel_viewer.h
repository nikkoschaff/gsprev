
#ifndef GUI_PANEL_VIEWER_H_
#define GUI_PANEL_VIEWER_H_


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
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/gauge.h>
#include <wx/panel.h>
#include <wx/imagjpeg.h>

#include "DBManager.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class gui_panel_viewer
///////////////////////////////////////////////////////////////////////////////
class gui_panel_viewer : public wxPanel 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap4;
		wxStaticText* m_staticText3;
		wxListBox* m_listBox1;
		wxStaticText* m_staticText2;
		wxButton* m_button9;
		wxStaticBitmap* img_test;
		wxStaticText* label_students_names;
		wxTextCtrl* name_input;
		wxStaticText* label_grade;
		wxTextCtrl* grade_output;
		wxGauge* m_gauge1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onListElementClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onStatsButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onStudentNameTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGradeTextEnter( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		gui_panel_viewer( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxTAB_TRAVERSAL ); 
		~gui_panel_viewer();
	
};

#endif