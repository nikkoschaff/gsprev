
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

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class gui_panel_home
///////////////////////////////////////////////////////////////////////////////

class gui_panel_home : public wxPanel 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap2;
		wxButton* Quick_Grade;
		wxButton* m_button6;
		wxButton* m_button7;
		wxButton* m_button8;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onQuickGradeClick( wxCommandEvent& event );
		virtual void onAssignmentsButtonClick( wxCommandEvent& event );
		virtual void onStudentsButtonClick( wxCommandEvent& event );
		virtual void onQuestBankButtonClick( wxCommandEvent& event );

		
	
	public:
		
		gui_panel_home( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxTAB_TRAVERSAL ); 
		~gui_panel_home();
	
};


#endif

