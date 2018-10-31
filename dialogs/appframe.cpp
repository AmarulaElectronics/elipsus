#include "appframe.h"


SimpleMenu::SimpleMenu(const wxString& title)
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
      wxCommandEventHandler(SimpleMenu::OnQuit));

  Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
      wxCommandEventHandler(SimpleMenu::OnQuit));
  Centre();

}

void SimpleMenu::OnQuit(wxCommandEvent& WXUNUSED(event))
{
  wxLogDebug(wxT("Application Quit."));
  Close(true);
}

