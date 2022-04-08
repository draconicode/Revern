#pragma once
#include "wx/wx.h"
class cMain : public wxFrame
{
public:
	cMain();
	void OnExitClicked(wxCommandEvent& WXUNUSED);
	~cMain();

public:
	wxMenuBar* menuBar;
	wxMenu* menuFile;
};

