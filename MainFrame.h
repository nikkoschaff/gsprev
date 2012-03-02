
#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/imagjpeg.h>


#include "gui_panel_home.h"
#include "gui_panel_grade.h"
#include "gui_panel_viewer.h"
#include "gui_panel_stats.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel5;
		gui_panel_home* home;
		gui_panel_grade* grade;
		gui_panel_viewer* viewer;
		gui_panel_stats* stats;
	
	public:
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GradeSnap"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainFrame();
	
		// Goes from home screen to quick grade
		virtual void onQuickGradeClick( wxCommandEvent& event );

		// Goes from quick grade to viewer (after grading in the panel)
		virtual void onGradeButtonClick( wxCommandEvent& event );

		// Switches to stats panel and has it compute stats
		virtual void onStatsButtonClick( wxCommandEvent& event );

};

#endif // MainFrame.h
