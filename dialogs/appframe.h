#include <wx/wx.h>
#include <wx/menu.h>

class AppFrame : public wxFrame
{
public:
	AppFrame(const wxString& title);

	void OnQuit(wxCommandEvent& event);
	void RunCalc(wxCommandEvent& event);

	wxMenuBar *menubar;
	wxMenu *file;
	wxTextCtrl *textctrl;
};
