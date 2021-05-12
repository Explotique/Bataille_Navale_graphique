#pragma once
#include "wx/wx.h"
#include "cmain.h"
class cApp : public wxApp
{
private:
	cmain* m_frame1 = nullptr;
public :
	virtual bool OnInit();
};

