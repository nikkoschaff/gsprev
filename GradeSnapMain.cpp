
#include <wx/wx.h>
#include "GradeSnapMain.h"


 
IMPLEMENT_APP(BasicApplication)
 
bool BasicApplication::OnInit()
{
	BasicFrame *frame = new BasicFrame(_T("GradeSnap"), 50, 50, 450, 300);
 
	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
}
 
BasicFrame::BasicFrame( const wxChar *title, int xpos, int ypos, int width, int height)
: wxFrame( (wxFrame*) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height) )
{
}
 
BasicFrame::~BasicFrame()
{
}
