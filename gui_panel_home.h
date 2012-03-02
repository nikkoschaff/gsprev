
#ifndef gui_panel_home_H_
#define gui_panel_home_H_


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
#include <wx/panel.h>
#include <wx/imagjpeg.h>
#include <cassert>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class gui_panel_home
///////////////////////////////////////////////////////////////////////////////
class gui_panel_home : public wxPanel 
{
	private:


	protected:
		wxStaticBitmap* m_bitmap2;

		
		// Virtual event handlers, overide them in your derived class
		virtual void onQuickGradeClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAssignmentsButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onStudentsButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onQuestBankButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		gui_panel_home( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxTAB_TRAVERSAL ); 
		~gui_panel_home();
	
		wxButton* button_quickgrade;
		wxButton* button_assignments;
		wxButton* button_students;
		wxButton* buttons_questbank;	


};


#endif

