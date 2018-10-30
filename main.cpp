#include <wx/wx.h>
#include <wx/log.h> 
#include "wx/image.h"
#include "wx/splash.h"

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

		wxImage::AddHandler(new wxPNGHandler);

		wxBitmap bitmap;
		bitmap.LoadFile(wxT("splash.png"), wxBITMAP_TYPE_PNG);

		new wxSplashScreen(bitmap,
                wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                6000, simple, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                wxSIMPLE_BORDER|wxSTAY_ON_TOP);

		wxYield();

		simple->Show(true);
		wxLogDebug(wxT("App Init Success!"));
		return true;
	}
};

wxIMPLEMENT_APP(MyApp);
