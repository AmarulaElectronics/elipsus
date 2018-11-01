#include "appframe.h"


AppFrame::AppFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 480))
{
	menubar = new wxMenuBar;
	file = new wxMenu;
	file->Append(wxID_EXIT, wxT("&Quit"));
	menubar->Append(file, wxT("&File"));
	SetMenuBar(menubar);

	wxBitmap exit(wxT("images/exit.png"), wxBITMAP_TYPE_PNG);

	wxToolBar *toolbar = CreateToolBar();
	toolbar->AddTool(wxID_EXIT, wxT("Exit application"), exit);
	toolbar->Realize();

	Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(AppFrame::OnQuit));

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(AppFrame::OnQuit));
	Centre();

	textctrl = new wxTextCtrl(this, -1, wxT(""), wxPoint(-1, -1),
                wxSize(250, 150), wxTE_MULTILINE);
}

void AppFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	wxLogDebug(wxT("Application Quit."));
	Close(true);
}

