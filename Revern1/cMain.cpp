#include "cMain.h"
#include "resource.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Revern", wxPoint(1000,700),wxSize(1000, 512))
{
	menuBar = new wxMenuBar();
	menuFile = new wxMenu();
	menuOpen = new wxMenu();
	fileDialog = new wxFileDialog(this, "Choose files", wxEmptyString, wxEmptyString, wxString::FromAscii(wxFileSelectorDefaultWildcardStr), 
		wxFD_DEFAULT_STYLE | wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE, wxPoint(100,100), wxDefaultSize, wxString("File chooser"));
	fileDialog->Centre(wxBOTH);

	mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	mainPanel->SetBackgroundColour(wxColour(30, 30, 38, 255));

	sizer = new wxBoxSizer(wxHORIZONTAL);
	mainPanelSizer = new wxFlexGridSizer(2,2,4,10);
	currentSizer = new wxBoxSizer(wxVERTICAL);
	resultSizer = new wxBoxSizer(wxVERTICAL);

	currentPanel = new wxScrolledWindow(this, wxID_ANY);
	resultPanel = new wxScrolledWindow(this, wxID_ANY);
	currentPanel->SetSizer(currentSizer);
	currentPanel->SetScrollbar(wxVERTICAL, 0, 24, 50, true);
	currentPanel->Layout();
	resultPanel->SetSizer(resultSizer);
	resultPanel->Layout();

	mainPanel->SetSizer(mainPanelSizer);

	sizer->Add(mainPanel, 1, wxALL | wxEXPAND, 0);
	sizer->Add(currentPanel, 2, wxALL | wxEXPAND, 0);
	sizer->Add(resultPanel, 2, wxALL | wxEXPAND, 0);

	menuFile->Append(rvID_OPEN, wxT("&Add Files"));
	menuFile->Append(rvID_CLEAR_AND_OPEN, wxT("&Clear and Add files"));
	menuFile->Append(wxID_EXIT, wxT("&Exit"));

	menuBar->Append(menuFile, wxT("&File"));

	replaceStaticText = new wxStaticText(mainPanel, wxID_ANY, wxString("Replace.."), wxPoint(10,10));
	replaceStaticText->SetForegroundColour(*wxWHITE);
	replaceWithStaticText = new wxStaticText(mainPanel, wxID_ANY, wxString("With.."), wxPoint(60, 10));
	replaceWithStaticText->SetForegroundColour(*wxWHITE);
	replaceTextCtrl = new wxTextCtrl(mainPanel, wxID_ANY, wxEmptyString, wxPoint(10, 20));
	replaceWithTextCtrl = new wxTextCtrl(mainPanel, wxID_ANY, wxEmptyString, wxPoint(60, 20));

	mainPanelSizer->Add(replaceStaticText);
	mainPanelSizer->Add(replaceWithStaticText);
	mainPanelSizer->Add(replaceTextCtrl);
	mainPanelSizer->Add(replaceWithTextCtrl);

	

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(cMain::OnExitClicked));
	Connect(rvID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(cMain::OnOpenClicked));
	Connect(rvID_CLEAR_AND_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(cMain::OnClearAndOpenClicked));

	SetMinSize(wxSize(1000, 512));
	SetMenuBar(menuBar);
	SetBackgroundColour(wxColour(20, 20, 24, 255));
	SetSizer(sizer);
	Layout();
	Centre(wxBOTH);
}

void cMain::OnExitClicked(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

void cMain::OnOpenClicked(wxCommandEvent& WXUNUSED(event)) { 
	
	OpenFileDialog();
}

void cMain::OnClearAndOpenClicked(wxCommandEvent& WXUNUSED(event))
{
	currentSizer->Clear();
	OpenFileDialog();
}

void cMain::OpenFileDialog() {
	if (fileDialog->ShowModal() == wxID_OK) {
		wxArrayString files;
		fileDialog->GetFilenames(files);
		int id = 0;
		for (auto& var : files)
		{
			wxStaticText* text = new wxStaticText(currentPanel, id, var);
			text->SetForegroundColour(wxColour(255,255,255,255));
			currentSizer->Add(text, 1, wxALL | wxEXPAND, 0);
			id++;
		}
		currentPanel->Layout();
		currentPanel->SetVirtualSize(wxSize(200, 16 * files.size()));
		currentPanel->SetScrollRate(1, 16);
	}
}

cMain::~cMain()
{
}

