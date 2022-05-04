#pragma once
#include "wx/wx.h"
#define rvID_CLEAR_AND_OPEN 0
#define rvID_OPEN 1
class cMain : public wxFrame
{
public:
	cMain();
	void OnExitClicked(wxCommandEvent& WXUNUSED);
	void OnOpenClicked(wxCommandEvent& WXUNUSED);
	void OnClearAndOpenClicked(wxCommandEvent& WXUNUSED);
	void OpenFileDialog();
	~cMain();


public:
	wxMenuBar* menuBar;
	wxMenu* menuFile;
	wxPanel* mainPanel;
	wxBoxSizer* sizer;
	wxFlexGridSizer* mainPanelSizer;
	wxBoxSizer* currentSizer;
	wxBoxSizer* resultSizer;
	wxScrolledWindow* currentPanel;
	wxScrolledWindow* resultPanel;
	wxMenu* menuOpen;
	wxFileDialog* fileDialog;
	wxTextCtrl* replaceTextCtrl;
	wxTextCtrl* replaceWithTextCtrl;

	wxStaticText* replaceStaticText;
	wxStaticText* replaceWithStaticText;
};

