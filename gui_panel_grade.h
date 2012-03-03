
#ifndef GUI_PANEL_GRADE_H_
#define GUI_PANEL_GRADE_H_


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
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/panel.h>

#include <vector>
#include "GradeSnapModel.h"
#include "DBManager.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class gui_panel_grade
///////////////////////////////////////////////////////////////////////////////
class gui_panel_grade : public wxPanel 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap5;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxTextCtrl* name_input;
		wxTextCtrl* num_quest_input;
		wxStaticText* m_staticText8;
		wxFilePickerCtrl* filePicker;
		wxCheckListBox* panel_grade_listbox;

		
		// Virtual event handlers, overide them in your derived class
		virtual void onNameTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNumQuestionsTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileChanged( wxFileDirPickerEvent& event );
		virtual void onListElementSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCheckListBoxToggled( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGradeButtonClick( wxCommandEvent& event );
		
	
	public:
		
		gui_panel_grade( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxTAB_TRAVERSAL ); 
		~gui_panel_grade();

		wxButton* panel_grade_gradebutton;
};

#endif 