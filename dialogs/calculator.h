#include <wx/wx.h>
#include <wx/menu.h>

class Calculator : public wxFrame
{
public:
	Calculator(const wxString& title);

	void OnQuit(wxCommandEvent& event);

	wxMenuBar *menubar;
	wxMenu *file;
};
