#include <wx/wx.h>
#include <wx/log.h> 
#include "wx/image.h"
#include "wx/splash.h"

#include "dialogs/appframe.h"

class MyApp : public wxApp
{
public:
	bool OnInit()
	{
		AppFrame *appframe = new AppFrame(wxT("Elipsus v1.0.0"));

		wxImage::AddHandler(new wxPNGHandler);

		wxBitmap bitmap;
		bitmap.LoadFile(wxT("images/splash.png"), wxBITMAP_TYPE_PNG);

		new wxSplashScreen(bitmap,
                wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                6000, appframe, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                wxSIMPLE_BORDER|wxSTAY_ON_TOP);

		wxYield();

		wxLogDebug(wxT("Splash Screen Shown"));

		appframe->Show(true);

		wxLogDebug(wxT("Main App Frame Shown"));

		return true;
	}
};

wxIMPLEMENT_APP(MyApp);
