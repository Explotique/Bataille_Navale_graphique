#pragma once
#include "wx/wx.h"
class cmain : public wxFrame
{
public:
	cmain();
	~cmain();
public:
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn;
	wxButton** btn2;
	int *nField;
	int *nField2;
	bool bFirstClick = true;
	bool bFirstClick2 = true;

void OnButtonClicked1(wxCommandEvent &evt);
void OnButtonClicked2(wxCommandEvent &evt);
	wxDECLARE_EVENT_TABLE();
};

