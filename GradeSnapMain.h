

#ifndef GRADESNAPMAIN_H_
#define GRADESNAPMAIN_H_

#include "GradeSnapModel.h"
#include "DBManager.h"

class BasicApplication : public wxApp
{
public:
	virtual bool OnInit();
};
 
class BasicFrame : public wxFrame
{
public:
	BasicFrame( const wxChar *title, int xpos, int ypos, int width, int height );
	~BasicFrame();
};

#endif