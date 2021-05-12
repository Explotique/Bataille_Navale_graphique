#pragma once
#include "wx/wx.h"
class bateau
{
private:
	int nb;
	wxString nom;
public:
	bateau(int a, wxString n);
	bateau();
	int getnb();
	wxString getnom();
};
