
///-----------------------------------------------------------------
///
/// @file      deformacjeFrm.h
/// @author    Natalia Aleksandra
/// Created:   2017-01-07 14:54:28
/// @section   DESCRIPTION
///            deformacjeFrm class declaration
///
///------------------------------------------------------------------

#ifndef __DEFORMACJEFRM_H__
#define __DEFORMACJEFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/textctrl.h>
#include <wx/scrolbar.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef deformacjeFrm_STYLE
#define deformacjeFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Matrix4;

class deformacjeFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		Matrix4 RotateZ(double alpha);
		Matrix4 RotateX(double alpha);
		Matrix4 RotateY(double alpha);
		Matrix4 norma(double z);
		Matrix4 scale(double Sx,double Sy, double Sz);
		Matrix4 SkewX(double a,double b);
		Matrix4 Shift3D(double Tx, double Ty,double Tz);
		Matrix4 ToWindow(double xmax, double ymax);
		Matrix4 To2D();
		
	public:
		deformacjeFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("deformacje"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = deformacjeFrm_STYLE);
		virtual ~deformacjeFrm();
		void WxButton3Click(wxCommandEvent& event);
		void WxEdit1Enter(wxCommandEvent& event);
		void WxButton3Click0(wxCommandEvent& event);
		
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxBoxSizer *WxBoxSizer10;
		wxTextCtrl *WxEdit4;
		wxTextCtrl *WxEdit3;
		wxStaticText *WxStaticText8;
		wxStaticBoxSizer *WxStaticBoxSizer2;
		wxScrollBar *WxScrollBar6;
		wxStaticText *WxStaticText7;
		wxBoxSizer *WxBoxSizer9;
		wxScrollBar *WxScrollBar5;
		wxStaticText *WxStaticText6;
		wxBoxSizer *WxBoxSizer8;
		wxScrollBar *WxScrollBar4;
		wxStaticText *WxStaticText5;
		wxBoxSizer *WxBoxSizer7;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit1;
		wxStaticText *WxStaticText4;
		wxBoxSizer *WxBoxSizer6;
		wxScrollBar *WxScrollBar3;
		wxStaticText *WxStaticText3;
		wxBoxSizer *WxBoxSizer5;
		wxScrollBar *WxScrollBar2;
		wxStaticText *WxStaticText2;
		wxBoxSizer *WxBoxSizer4;
		wxScrollBar *WxScrollBar1;
		wxStaticText *WxStaticText1;
		wxBoxSizer *WxBoxSizer3;
		wxButton *WxButton1;
		wxBoxSizer *WxBoxSizer2;
		wxPanel *WxPanel1;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		void Load(wxCommandEvent& event);
		void Saving(wxCommandEvent& event);
		void Zapamietaj(wxCommandEvent& event);
		void Reset(wxCommandEvent& event);
		
		void WxEdit1E(wxCommandEvent& event);
		void WxEdit2E(wxCommandEvent& event);
		void WxEdit3E(wxCommandEvent& event);
		void WxEdit4E(wxCommandEvent& event);
		void UpdateDrawing(wxUpdateUIEvent& event);
		void drawing(bool print = true);
		void RotationX(wxScrollEvent& event);
		void RotationY(wxScrollEvent& event);
		void RotationZ(wxScrollEvent& event);
		void ScrollThumbRelease1(wxScrollEvent& event);
		void SkewX(wxScrollEvent& event);
		void SkewY(wxScrollEvent& event);
		void Beczka(int value);
		void BarrelPincushion(wxScrollEvent& event);
		void interpolate(wxImage &ImgIn);
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTON3 = 1047,
			ID_WXBUTTON2 = 1046,
			ID_WXEDIT4 = 1040,
			ID_WXEDIT3 = 1039,
			ID_WXSTATICTEXT8 = 1038,
			ID_WXSCROLLBAR6 = 1029,
			ID_WXSTATICTEXT7 = 1028,
			ID_WXSCROLLBAR5 = 1025,
			ID_WXSTATICTEXT6 = 1024,
			ID_WXSCROLLBAR4 = 1022,
			ID_WXSTATICTEXT5 = 1021,
			ID_WXEDIT2 = 1019,
			ID_WXEDIT1 = 1018,
			ID_WXSTATICTEXT4 = 1017,
			ID_WXSCROLLBAR3 = 1015,
			ID_WXSTATICTEXT3 = 1014,
			ID_WXSCROLLBAR2 = 1012,
			ID_WXSTATICTEXT2 = 1011,
			ID_WXSCROLLBAR1 = 1009,
			ID_WXSTATICTEXT1 = 1008,
			ID_WXBUTTON1 = 1005,
			ID_WXPANEL1 = 1003,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		wxImage img;
		wxImage Img_Cpy;
		wxImage Img_Org;
		wxClientDC *dc;
		int *xPoint;
		int *yPoint; 
		int *xPointB;
		int *yPointB; 
		bool **tab;
		int option;
		int width, height;
		
};

#endif
