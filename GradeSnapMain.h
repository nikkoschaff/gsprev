
#ifndef GRADESNAPMAIN_H_
#define GRADESNAPMAIN_H_

#include <wx/wx.h>

#include "GradeSnapModel.h"
#include "DBManager.h"

class MyApp: public wxApp
{
    virtual bool OnInit();
};

 
class MainFrame: public wxFrame
{
public:
 
    MainFrame(const wxString& title, 
           const wxPoint& pos, const wxSize& size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
 
private:

    DECLARE_EVENT_TABLE()

};

enum
{
    ID_Quit = 1,
    ID_About,

};

#endif