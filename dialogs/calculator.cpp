#include "calculator.h"


Calculator::Calculator(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 480))
{
	menubar = new wxMenuBar;
	file = new wxMenu;
	file->Append(wxID_EXIT, wxT("&Quit"));
	menubar->Append(file, wxT("&File"));
	SetMenuBar(menubar);

	wxBitmap exit(wxT("images/exit.png"), wxBITMAP_TYPE_PNG);

	wxToolBar *toolbar = CreateToolBar();
	toolbar->AddTool(wxID_EXIT, wxT("Exit Calculator"), exit);
	toolbar->Realize();

	Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(Calculator::OnQuit));

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(Calculator::OnQuit));
	Centre();
}

void Calculator::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	wxLogDebug(wxT("Calculator Quit."));
	Close(true);
}

