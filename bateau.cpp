#include "bateau.h"
#include "wx/wx.h"
bateau::bateau(int a, wxString n) {
	nb = a;
	nom = n;
}
bateau::bateau() {};
int bateau:: getnb() { return nb; }
wxString bateau::getnom()
{
	return nom;
}