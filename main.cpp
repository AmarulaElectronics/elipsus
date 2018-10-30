#include <wx/wx.h>
#include <wx/log.h> 

class Simple : public wxFrame
{
public:
    Simple(const wxString& title)
		: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
	{
		Centre();
	}
};

class MyApp : public wxApp
{
public:
	bool OnInit()
	{
		Simple *simple = new Simple(wxT("Elipsus 1.0.0"));
		simple->Show(true);
		wxLogDebug(wxT("App Init Success!"));
		return true;
	}
};

wxIMPLEMENT_APP(MyApp);
