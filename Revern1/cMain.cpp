#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Revern", wxPoint(1000,700),wxSize(800, 512))
{
	this->SetBackgroundColour(wxColour(20, 20, 24, 255));
	menuBar = new wxMenuBar();
	menuFile = new wxMenu();

	menuFile->Append(wxID_EXIT, wxT("&Exit"));
	menuBar->Append(menuFile, wxT("&File"));

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(cMain::OnExitClicked));

	SetMenuBar(menuBar);
	

}

void cMain::OnExitClicked(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

cMain::~cMain()
{
}

