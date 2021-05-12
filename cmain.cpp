#include "cmain.h"
#include "bateau.h"

wxBEGIN_EVENT_TABLE(cmain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked1)
EVT_BUTTON(10002, OnButtonClicked2)
wxEND_EVENT_TABLE()

cmain::cmain() : wxFrame(nullptr, wxID_ANY, "onelonecoder.com", wxPoint(30, 30), wxSize(1400, 800))
{
	bateau Porte_Avions(5, "Porte_Avions"), croiseur(4, "croiseur"), contre_torpilleur1(3, "contre_torpilleur1"), contre_torpilleur2(3, "contre_torpilleur2"), torpilleur(2, "torpilleur");
	bateau l1[5];
	l1[0] = Porte_Avions;
	l1[1] = croiseur;
	l1[2] = contre_torpilleur1;
	l1[3] = contre_torpilleur2;
	l1[4] = torpilleur;
	bateau CUIRASSE(4, "CUIRASSE"), CROISEUR1(3, "CROISEUR1"), CROISEUR2(3, "CROISEUR2"), TORPILLEUR1(2, "TORPILLEUR1"), TORPILLEUR2(2, "TORPILLEUR2"), TORPILLEUR3(2, "TORPILLEUR3"), SOUS_MARIN1(1, "SOUS_MARIN1"), SOUS_MARIN2(1, "SOUS_MARIN2"), SOUS_MARIN3(1, "SOUS_MARIN3"), SOUS_MARIN4(1, "SOUS_MARIN4");
	bateau l2[10];
	l2[0] = CUIRASSE;
	l2[1] = CROISEUR1;
	l2[2] = CROISEUR2;
	l2[3] = TORPILLEUR1;
	l2[4] = TORPILLEUR2;
	l2[5] = TORPILLEUR3;
	l2[6] = SOUS_MARIN1;
	l2[7] = SOUS_MARIN2;
	l2[8] = SOUS_MARIN3;
	l2[9] = SOUS_MARIN4;

	btn = new wxButton*[nFieldWidth * nFieldHeight];
	nField = new int [nFieldWidth * nFieldHeight];
	btn2 = new wxButton*[nFieldWidth * nFieldHeight];
	nField2 = new int[nFieldWidth * nFieldHeight];
	wxPanel* wesst = new wxPanel(this, wxID_ANY, wxPoint(575, 100), wxSize(350, 500));
	wxPanel* tahtjoueur1 = new wxPanel(this, wxID_ANY, wxPoint(10, 620), wxSize(500, 150));
	wxPanel* tahtjoueur2 = new wxPanel(this, wxID_ANY, wxPoint(995, 620), wxSize(500, 150));
	wxPanel* panel1 = new wxPanel(this, wxID_ANY, wxPoint(10, 100), wxSize(500, 500));
	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxPoint(995, 100), wxSize(500, 500));



	wxGridSizer *grid1 = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	wxGridSizer *grid2 = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y*nFieldHeight + x] = new wxButton(panel1, 10000 + (y * nFieldWidth + x));
			grid1->Add(btn[y* nFieldWidth + x], 1, wxEXPAND | wxALL);
			btn2[y*nFieldHeight + x] = new wxButton(panel2, 10000 + (y * nFieldWidth + x));
			grid2->Add(btn2[y* nFieldWidth + x], 2, wxEXPAND | wxALL);
			btn[y*nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::OnButtonClicked1, this);
			btn2[y*nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::OnButtonClicked2, this);
			nField[y*nFieldWidth + x] = 0;
			nField2[y*nFieldWidth + x] = 0;
		}
	}
	panel1->SetSizer(grid1);
	panel2->SetSizer(grid2);
	panel1->Layout();
	panel2->Layout();





}




cmain::~cmain()
{

}
void cmain::OnButtonClicked1(wxCommandEvent &evt)
{  
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldWidth;
	if (bFirstClick)
	{
		int mines = 30;
		while (mines)
		{
			int rx = rand() % nFieldWidth;
			int ry = rand() % nFieldHeight;
			if (nField[rx* nFieldWidth + rx] == 0 && rx != x && ry != y)
			{
				nField[ry * nFieldWidth + rx] = -1;
				mines--;
			}
		}
		bFirstClick = false;
	}
	btn[y*nFieldWidth + x]->Enable(false);
	if (nField[y*nFieldWidth + x] == -1)
	{
		wxMessageBox("BOOOOOOOOOOM GAME OVER");
		bFirstClick = true;
		for(x=0;x<nFieldWidth;x++)
			for (y = 0; y < nFieldHeight; y++)
			{
				nField[y*nFieldWidth + x] = 0;
				btn[y*nFieldWidth + x]->SetLabel("");
				btn[y*nFieldWidth + x]->Enable(true);

			}

	}
	else
	{
		int mine_count = 0;
		for(int i=-1;i<2;i++)
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < nFieldWidth && y + j < nFieldHeight)
				{
					if (nField[(y + j) * nFieldWidth + (x + i)] == -1)
						mine_count++;
				}
			}
		if (mine_count > 0)
		{
			btn[y*nFieldWidth + x]->SetLabel(std::to_string(mine_count));
		}
	}
	evt.Skip();
}
void cmain::OnButtonClicked2(wxCommandEvent &evt)
{
	int x2 = (evt.GetId() - 10000) % nFieldWidth;
	int y2 = (evt.GetId() - 10000) / nFieldWidth;
	if (bFirstClick2)
	{
		int mines2 = 30;
		while (mines2)
		{
			int rx2 = rand() % nFieldWidth;
			int ry2 = rand() % nFieldHeight;
			if (nField2[rx2* nFieldWidth + rx2] == 0 && rx2 != x2 && ry2 != y2)
			{
				nField2[ry2 * nFieldWidth + rx2] = -1;
				mines2--;
			}
		}
		bFirstClick2 = false;
	}
	btn2[y2*nFieldWidth + x2]->Enable(false);
	if (nField2[y2*nFieldWidth + x2] == -1)
	{
		wxMessageBox("BOOOOOOOOOOM GAME OVER");
		bFirstClick2 = true;
		for (x2 = 0; x2 < nFieldWidth; x2++)
			for (y2 = 0; y2 < nFieldHeight; y2++)
			{
				nField2[y2*nFieldWidth + x2] = 0;
				btn2[y2*nFieldWidth + x2]->SetLabel("");
				btn2[y2*nFieldWidth + x2]->Enable(true);

			}

	}
	else
	{
		int mine_count2 = 0;
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				if (x2 + i >= 0 && x2 + i < nFieldWidth && y2 + j < nFieldHeight)
				{
					if (nField2[(y2 + j) * nFieldWidth + (x2 + i)] == -1)
						mine_count2++;
				}
			}
		if (mine_count2 > 0)
		{
			btn2[y2*nFieldWidth + x2]->SetLabel(std::to_string(mine_count2));
		}
	}
	evt.Skip();
}