#include "cApp.h"
#include "resource.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit(){
	m_frame1 = new cMain();
	m_frame1->SetIcon(wxICON(IDI_ICON1));
	m_frame1->Show();
	return true;
}
