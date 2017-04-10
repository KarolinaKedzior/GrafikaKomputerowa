///-----------------------------------------------------------------
///
/// @file      deformacjeFrm.cpp
/// @author    Natalia Aleksandra
/// Created:   2017-01-07 14:54:28
/// @section   DESCRIPTION
///            deformacjeFrm class implementation
///
///------------------------------------------------------------------

#include "deformacjeFrm.h"
#include <wx/dcbuffer.h>
#include <wx/wfstream.h>
#include <vector>
#include "bibl.h"

double deg = M_PI/180.0;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// deformacjeFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(deformacjeFrm,wxFrame)
	////Manual Code Start
	//	EVT_UPDATE_UI(ID_WXPANEL1,deformacjeFrm::UpdateDrawing)
	EVT_BUTTON(ID_WXBUTTON1,deformacjeFrm::Load)
	EVT_BUTTON(ID_WXBUTTON3,deformacjeFrm::Saving)
	EVT_BUTTON(ID_WXBUTTON2,deformacjeFrm::Zapamietaj)
	//	EVT_COMMAND_SCROLL_THUMBRELEASE(ID_WXSCROLLBAR1,deformacjeFrm::ScrollThumbRelease1)
	//	EVT_COMMAND_SCROLL_THUMBRELEASE(ID_WXSCROLLBAR2,deformacjeFrm::ScrollThumbRelease1)
	//EVT_COMMAND_SCROLL_THUMBRELEASE(ID_WXSCROLLBAR3,deformacjeFrm::ScrollThumbRelease1)
	//	EVT_COMMAND_SCROLL_THUMBRELEASE(ID_WXSCROLLBAR4,deformacjeFrm::ScrollThumbRelease1)
	//	EVT_COMMAND_SCROLL_THUMBRELEASE(ID_WXSCROLLBAR5,deformacjeFrm::ScrollThumbRelease1)
	//EVT_COMMAND_SCROLL_THUMBRELEASE(ID_WXSCROLLBAR6,deformacjeFrm::ScrollThumbRelease1)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR1,deformacjeFrm::RotationZ)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR2,deformacjeFrm::RotationX)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR3,deformacjeFrm::RotationY)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR4,deformacjeFrm::SkewX)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR5,deformacjeFrm::SkewY)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR6,deformacjeFrm::BarrelPincushion)
	EVT_TEXT_ENTER(ID_WXEDIT1,deformacjeFrm::WxEdit1E)
	EVT_TEXT_ENTER(ID_WXEDIT2,deformacjeFrm::WxEdit2E)
	EVT_TEXT_ENTER(ID_WXEDIT3,deformacjeFrm::WxEdit3E)
	EVT_TEXT_ENTER(ID_WXEDIT4,deformacjeFrm::WxEdit4E)
	EVT_CLOSE(deformacjeFrm::OnClose)
	////Manual Code End
	
	EVT_CLOSE(deformacjeFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

deformacjeFrm::deformacjeFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	wxInitAllImageHandlers();
	CreateGUIControls();   
}

deformacjeFrm::~deformacjeFrm()
{
}

void deformacjeFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(5, 53), wxSize(400, 400));
	WxBoxSizer1->Add(WxPanel1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Wczytaj"), wxPoint(145, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxBoxSizer2->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Obrót prostopadle:                   "), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxBoxSizer3->Add(WxStaticText1, 0, wxALIGN_LEFT | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(130, 6), wxSize(150, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_RIGHT | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Obrót poziomo:                      "), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText2"));
	WxBoxSizer4->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(127, 6), wxSize(150, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer4->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Obrót pionowo:                      "), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText3"));
	WxBoxSizer5->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(128, 6), wxSize(150, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer5->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("Œrodek obrotu prostopad³ego: (0,0)"), wxPoint(5, 2), wxDefaultSize, 0, _("WxStaticText4"));
	WxBoxSizer6->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 2);

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("0"), wxPoint(2, 25), wxSize(100, 19), 0, wxDefaultValidator, _("WxEdit1"));
	WxEdit1->SetMaxLength(5);
	WxBoxSizer6->Add(WxEdit1, 0, wxALIGN_CENTER | wxALL, 2);

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("0"), wxPoint(2, 48), wxSize(100, 19), 0, wxDefaultValidator, _("WxEdit2"));
	WxBoxSizer6->Add(WxEdit2, 0, wxALIGN_CENTER | wxALL, 2);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("Przechylenie poziomo:                       "), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText5"));
	WxBoxSizer7->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar4 = new wxScrollBar(this, ID_WXSCROLLBAR4, wxPoint(168, 6), wxSize(150, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar4"));
	WxScrollBar4->Enable(false);
	WxBoxSizer7->Add(WxScrollBar4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("Przechylenie pionowo:                       "), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText6"));
	WxBoxSizer8->Add(WxStaticText6, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar5 = new wxScrollBar(this, ID_WXSCROLLBAR5, wxPoint(166, 6), wxSize(150, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar5"));
	WxScrollBar5->Enable(false);
	WxBoxSizer8->Add(WxScrollBar5, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer9, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, _("P\B wsp. korekty:                               "), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText7"));
	WxBoxSizer9->Add(WxStaticText7, 0, wxALIGN_LEFT | wxALL, 5);

	WxScrollBar6 = new wxScrollBar(this, ID_WXSCROLLBAR6, wxPoint(200, 6), wxSize(150, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar6"));
	WxScrollBar6->Enable(false);
	WxBoxSizer9->Add(WxScrollBar6, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer2_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _(""));
	WxStaticBoxSizer2 = new wxStaticBoxSizer(WxStaticBoxSizer2_StaticBoxObj, wxVERTICAL);
	WxBoxSizer2->Add(WxStaticBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, _("Œrodek dystorsji:  "), wxPoint(7, 17), wxDefaultSize, 0, _("WxStaticText8"));
	WxStaticBoxSizer2->Add(WxStaticText8, 0, wxALIGN_CENTER | wxALL, 2);

	WxEdit3 = new wxTextCtrl(this, ID_WXEDIT3, _("0"), wxPoint(19, 41), wxSize(70, 19), 0, wxDefaultValidator, _("WxEdit3"));
	WxStaticBoxSizer2->Add(WxEdit3, 0, wxALIGN_CENTER | wxALL, 3);

	WxEdit4 = new wxTextCtrl(this, ID_WXEDIT4, _("0"), wxPoint(19, 66), wxSize(70, 19), 0, wxDefaultValidator, _("WxEdit4"));
	WxStaticBoxSizer2->Add(WxEdit4, 0, wxALIGN_CENTER | wxALL, 3);

	WxBoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer10, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton2 = new wxButton(this, ID_WXBUTTON2, _("Zapamiêtaj"), wxPoint(5, 5), wxSize(70, 25), 0, wxDefaultValidator, _("WxButton2"));
	WxBoxSizer10->Add(WxButton2, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton3 = new wxButton(this, ID_WXBUTTON3, _("Zapisz"), wxPoint(31, 15), wxSize(70, 25), 0, wxDefaultValidator, _("WxButton3"));
	WxBoxSizer10->Add(WxButton3, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("deformacje"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	dc = new wxClientDC(WxPanel1);
    WxScrollBar1->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar1->Enable(true);
	WxScrollBar2->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar2->Enable(true);
	WxScrollBar3->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar3->Enable(true);
	
	WxScrollBar4->SetScrollbar(0, 1, 721, 1,true);
	WxScrollBar4->Enable(true);
	WxScrollBar4->SetThumbPosition(360);
	
	WxScrollBar5->SetScrollbar(0, 1, 721, 1,true);
	WxScrollBar5->Enable(true);
	WxScrollBar5->SetThumbPosition(360);
	WxScrollBar6->SetScrollbar(0, 1, 130, 1,true);
	WxScrollBar6->Enable(true);
	WxScrollBar6->SetThumbPosition(65);
	xPoint = new int;
	yPoint = new int;
	xPointB = new int;
	yPointB = new int;
	option = 0;
}

void deformacjeFrm::OnClose(wxCloseEvent& event)
{
	//delete xPoint;
	//delete yPoint;
    Destroy();
}

void deformacjeFrm::Load(wxCommandEvent& event){

	wxFileDialog dialog(this, _("Zaladuj obrazek"), "", "", "JPEG files (*.jpg)|*.jpg", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (dialog.ShowModal() == wxID_CANCEL) {
		return; 
	}
	wxFileInputStream input_stream(dialog.GetPath());
	if (!input_stream.IsOk() ) {
		wxLogError("Nie mozna zaladowa obrazka");
	} else {
		Img_Org.LoadFile(input_stream, wxBITMAP_TYPE_JPEG);
		width = Img_Org.GetWidth();
		height = Img_Org.GetHeight();
		
		img = Img_Org.Copy();
		img.Rescale(WxPanel1->GetSize().x, WxPanel1->GetSize().y);
		Img_Cpy = img.Copy();
	    
        wxBufferedDC dc2(&(*dc));
        dc2.DrawBitmap( wxBitmap(Img_Cpy), 0,0,(true) );
        (*xPoint)= 0.0;//(Img_Cpy.GetWidth()/2.0);
	    (*yPoint)= 0.0;//(Img_Cpy.GetHeight()/2.0);
        wxString str;
        str = "Œrodek obrotu z: (";
        str << (*xPoint);
        str <<", " << (*yPoint) << ")";
         WxStaticText4->SetLabel(str);
         
         /* srodek beczki */
         (*xPointB)= 0.0;//(Img_Cpy.GetWidth()/2.0);
	     (*yPointB)= 0.0;//(Img_Cpy.GetHeight()/2.0);

        str = "Œrodek deformacji P\B: (";
        str << (*xPointB);
        str <<", " << (*yPointB) << ")";
         WxStaticText8->SetLabel(str);
	     
	}
	
}

void deformacjeFrm::Saving(wxCommandEvent& event){

	if(img.Ok()) {
		wxImage::AddHandler(new wxPNGHandler);
		wxFileDialog dialog(this, _("Zapisz obrazek"), "", "", "JPEG (*.jpg)|*.jpg", wxFD_SAVE);
		int arg = dialog.ShowModal();
		if (arg == wxID_CANCEL){
			return;
		} else if (arg == wxID_OK) {
            Img_Org.SaveFile(dialog.GetPath(), wxBITMAP_TYPE_JPEG);
	        Img_Cpy = img.Copy();
		} else {
			wxMessageBox("Zapis nie powiód³ sie!");
		}
	}
    
}

Matrix4 deformacjeFrm::RotateZ(double alpha)
{
    Matrix4 temp;
    temp.data[0][0] =  temp.data[1][1] = cos(alpha);
    temp.data[0][1] = -sin(alpha);
    temp.data[1][0] = sin(alpha);
    temp.data[2][2] = 1;
    return temp;
}

Matrix4 deformacjeFrm::RotateX(double alpha) {	
   Matrix4 temp;
   temp.data[0][0] = 1.0;
   temp.data[1][1] =  temp.data[2][2] = cos(alpha);
   temp.data[1][2] = -sin(alpha);
   temp.data[2][1] = sin(alpha);
   return temp;
}
Matrix4 deformacjeFrm::RotateY(double alpha) {	
   Matrix4 temp;
   temp.data[0][0] = temp.data[2][2] = cos(alpha);
   temp.data[2][0] = -sin(alpha);
   temp.data[0][2] = sin(alpha);
   temp.data[1][1] = 1.0;
   return temp;
}	


Matrix4 deformacjeFrm::norma(double z){
   Matrix4 tmp;
   tmp.data[0][0] = 1.0/z;
   tmp.data[1][1] = 1.0/z; 
   tmp.data[3][3] = 1.0/z;
   return tmp;
}

Matrix4 deformacjeFrm::scale(double Sx,double Sy, double Sz){
   Matrix4 tmp;
   tmp.data[0][0] = Sx;
   tmp.data[1][1] = Sy;
   tmp.data[2][2] = Sz;
   return tmp;
} 

Matrix4 deformacjeFrm::SkewX(double a,double b){
   Matrix4 tmp;
   tmp.data[0][0] = tmp.data[1][1] = tmp.data[2][2] = 1;
   tmp.data[1][0] = b;
   tmp.data[0][1] = a;

   return tmp;
}

Matrix4 deformacjeFrm::Shift3D(double Tx, double Ty,double Tz) 
{
    Matrix4 shift;
    shift.data[0][0] = 1.0;
    shift.data[0][3] = Tx ;
    shift.data[1][1] = 1.0;
    shift.data[1][3] = Ty;
    shift.data[2][2] = 1.0;
    shift.data[2][3] = Tz ;
    return shift;
}

Matrix4  deformacjeFrm::ToWindow(double xmax, double ymax){
    Matrix4 t1,t2;
    t1.data[0][0] = 1;
    t1.data[1][1] = 1;
    t1.data[0][3] = xmax/2.0; // przesuwamyc calosc na srodek okna (w/2, h/2);
    t1.data[1][3] = ymax/2.0;
    return t1;
}

/**rzutowanie  z 3D na 2D 
 * d - odleglosc kamery od obrazu
 */
Matrix4 deformacjeFrm::To2D() {
	
    Matrix4 tmp;
	tmp.data[0][0] = 1.0;
    tmp.data[1][1] = 1.0;
    tmp.data[3][2] = 0; // 1.0/ d -> 0 , bo d->inf 
    tmp.data[3][3] = 1.0 ;
	return tmp;
}
/*
void deformacjeFrm::UpdateDrawing(wxUpdateUIEvent& event){
    if(img.Ok()){
         wxString str;
         str<< "Obrót z:  " ;
         str << (WxScrollBar1->GetThumbPosition());
         WxStaticText4->SetLabel(str);
         
	}
}
*/
void deformacjeFrm::drawing(bool print){
    
      wxBufferedDC dc2(&(*dc));
    if(print){
        Img_Cpy = img.Copy();
    }
    else{
        Img_Cpy = Img_Org.Copy();
    }
	//Img_Cpy.Rescale(WxPanel1->GetSize().x, WxPanel1->GetSize().y);

    
    int w = Img_Cpy.GetWidth();
    int h = Img_Cpy.GetHeight();
         
    wxImage tmp = wxImage(w,h);

    tab = new bool*[w];
    for(int i =0 ; i< w; i++){
        tab[i] = new bool[h];
        for(int j =0 ; j< h; j++){
        tab[i][j] = false;
    }
    }
    

if(option ==1){
Matrix4 T1 =  ToWindow( w, h);
Matrix4 M1= To2D() * Shift3D(0,0,0); // dowolne wartosci?
Matrix4 M2 = M1 * SkewX( (WxScrollBar4->GetThumbPosition()-360.0)*deg,(WxScrollBar5->GetThumbPosition()-360.0)*deg)* Shift3D((*xPoint),-(*yPoint),0)* RotateX(WxScrollBar2->GetThumbPosition()*deg);
M2 = M2 * RotateY(WxScrollBar3->GetThumbPosition()*deg); //value*deg/100....
M2 = M2 * RotateZ(WxScrollBar1->GetThumbPosition()*deg); 
M2 = M2 * Shift3D( -(*xPoint),(*yPoint),0)*scale(1,1,1); // wartosci > 0


Vector4 a1, b1;
int x1,y1;
for(int i =0 ; i < w ; i++){
    for(int j =0 ; j < h; j++){
        int r = Img_Cpy.GetRed(i,j);
        int g = Img_Cpy.GetGreen(i,j);
        int b = Img_Cpy.GetBlue(i,j);      
        a1.Set(i- (w/2),j -(h/2),0);
        b1= M2*a1; 
        b1 = norma(b1.data[3])*b1; 
        b1 = T1*b1; 
        x1 = b1.GetX();
        y1 = b1.GetY();
        if( x1>0 && x1 < w && y1 < h && y1 > 0){
         tmp.SetRGB(x1,y1, r,g,b);
         tab[x1][y1] = true;
        }
    }
}
   interpolate(tmp);
   Img_Cpy = tmp;
   //dc2.DrawBitmap( wxBitmap(Img_Cpy), 0,0,(true) );
}
   
   if( option == 2){ 
   Beczka(WxScrollBar6->GetThumbPosition());
   interpolate(Img_Cpy);  
   
 }
 
   if(print){
        dc2.DrawBitmap( wxBitmap(Img_Cpy), 0,0,(true) );
   }
        
    for(int i =0 ; i< w; i++){
        delete[] tab[i];
    }
    delete[] tab;
 
 
}


void deformacjeFrm::interpolate(wxImage &ImgIn){
    
wxImage tmp = ImgIn.Copy();
int w = ImgIn.GetWidth();
int h = ImgIn.GetHeight();
int m = 9; // rozmiar maski
double r;
double rtmp = 0;
int r2,g2,b2;
int beg,beg2,end,end2;
/*szukamy kazdego pixela nieznanego */
for(int i=0; i<w; ++i){
  for(int j=0; j<h; j++){    
      /** dzura */      
      if(tab[i][j] == false){
       /**r - maksymalna odleglosc miedzy pikselem znanym i nieznanym */
       r = sqrt( pow( w,2) + pow(h, 2));
       /** warunki brzegowe */
       if(i<m){
            beg = 0;
            end = i + m;
       }
      else if(i>w-m){
            end = w;
            beg = i-m;
       }else{
             beg = i-m;
             end = i+m;
       }
       if(j<m){
            beg2 = 0;
            end2 = j + m;
       }
      else if(j>h-m){
            end2 = h;
            beg2 = j-m;
       }else{
             beg2 = j-m;
             end2 = j+m;
       }
       /** dla nieznanego piksela szukamy najblizszego s¹siada w zakresie 5 pikseli*/
       for(int i2 =beg; i2< end ; i2++){
         for(int j2 =beg2; j2< end2; j2++){
          if(tab[i2][j2]){           
              rtmp = sqrt(pow(i2 - i, 2) + pow(j2 - j, 2) );
              if( rtmp < r){
              r2 = tmp.GetRed(i2,j2);
              g2 = tmp.GetGreen(i2,j2);
              b2 = tmp.GetBlue(i2,j2);  
              r = rtmp;
              ImgIn.SetRGB(i,j, r2, g2, b2);}
          }
        }}
      }
    }}

}

void deformacjeFrm::Beczka(int value)
{
int w = Img_Cpy.GetWidth();
int h = Img_Cpy.GetHeight();
wxImage tmp = wxImage(w,h);
double kd1 = (value-65.0)/10000000.0;
double oldX, oldY, newX, newY;
for (int i = 0; i < w; i++){
   for (int j = 0; j < h; j++){
            oldX = i - w/2.0; 
            oldY = j - h/2.0; // do œrodka wspó³rzêdnych
            
        
            
            double ru =sqrt(pow((oldX-(*xPointB)), 2) + pow(oldY-(*yPointB), 2));
            newX = oldX/(1.0 + kd1* pow(ru,2) ) ;
            newY = oldY/(1.0 + kd1* pow(ru,2) ) ;
            
        
            
            newX += w/2.0;
            newY += h/2.0; 
           
            if( newX >=0 &&  newX <= w-1 && newY <= h-1 && newY >= 0){
            int r = Img_Cpy.GetRed(i,j);
            int g = Img_Cpy.GetGreen(i,j);
            int b = Img_Cpy.GetBlue(i,j);
            tmp.SetRGB(newX,newY, r,g,b);
            tab[(int)newX][(int)newY] = true;
            }
        }
    }
    Img_Cpy = tmp;    
}
/*
void deformacjeFrm::ScrollThumbRelease1(wxScrollEvent& event)
{
 if(img.Ok()){
	drawing();
 }
}
*/
void deformacjeFrm::RotationX(wxScrollEvent& event){
 option = 1;
 wxString str;
 str<< "Obrót poziom:  " ;
 str << (WxScrollBar2->GetThumbPosition());
 WxStaticText2->SetLabel(str);
  if(img.Ok()){
	drawing();
}

}

void deformacjeFrm::RotationY(wxScrollEvent& event){
    option = 1;
    wxString str;
    str<< "Obrót pion: " ;
    str << (WxScrollBar3->GetThumbPosition());
    WxStaticText3->SetLabel(str);
      if(img.Ok()){
	drawing();
}
}

void deformacjeFrm::RotationZ(wxScrollEvent& event){
    option = 1;
    wxString str;
    str<< "Obrót prostopadle: " ;
    str << (WxScrollBar1->GetThumbPosition());
    WxStaticText1->SetLabel(str);
      if(img.Ok()){
	drawing();
}

}

void deformacjeFrm::SkewX(wxScrollEvent& event){
    option = 1;
    wxString str;
    str<< "Przechylenie poziomo:  " ;
    str << (WxScrollBar4->GetThumbPosition()-360.0);
    WxStaticText5->SetLabel(str);
      if(img.Ok()){
	drawing();
}
}

void deformacjeFrm::SkewY(wxScrollEvent& event){
    option = 1;
    wxString str;
    str<< "Przechylenie pionowo:  " ;
    str << (WxScrollBar5->GetThumbPosition()-360.0);
    WxStaticText6->SetLabel(str);
      if(img.Ok()){
	drawing();
}
}

void deformacjeFrm::BarrelPincushion(wxScrollEvent& event){
    
    option = 2;
    wxString str;
    str<< "Poduszka/Beczka :   " ;
    str << ( (WxScrollBar6->GetThumbPosition() -65.0)/8000000.0 );
    WxStaticText7->SetLabel(str);
      if(img.Ok()){
	drawing();
    }
}

/*

	EVT_UPDATE_UI(ID_WXPANEL1,deformacjeFrm::UpdateDrawing)
	EVT_BUTTON(ID_WXBUTTON1,deformacjeFrm::Load)
	EVT_BUTTON(ID_WXBUTTON2,deformacjeFrm::Saving)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR1,deformacjeFrm::RotationZ)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR2,deformacjeFrm::RotationX)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR3,deformacjeFrm::RotationY)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR4,deformacjeFrm::SkewX)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR5,deformacjeFrm::SkewY)
	EVT_COMMAND_SCROLL(ID_WXSCROLLBAR6,deformacjeFrm::BarrelPincushion)
	
	*/
	
	 /*option = 1;
 wxString str;
 str<< "Obrót y:  " ;
 str << (WxScrollBar2->GetThumbPosition());
 WxStaticText2->SetLabel(str);*/

/*
 * WxScrollBar1ScrollThumbRelease
 */

/*
 * WxButton3Click
 */
void deformacjeFrm::Zapamietaj(wxCommandEvent& event)
{
      if(Img_Cpy.Ok()){
	img = Img_Cpy.Copy();
	
	drawing(false);
	Img_Org = Img_Cpy.Copy();
    }
	
	
}


/*
 * WxEdit1Enter
 */
void deformacjeFrm::WxEdit1E(wxCommandEvent& event)
{
    wxString str;
    str  = WxEdit1->GetLineText(0);
    (*xPoint) = wxAtoi(str);
    str = "Œrodek obrotu prostopad³ego: (";
    str << ((*xPoint));
    str <<", " << (*yPoint) << ")";
    WxStaticText4->SetLabel(str);
}

void deformacjeFrm::WxEdit2E(wxCommandEvent& event)
{
    wxString str;
    str  = WxEdit2->GetLineText(0);
    (*yPoint) = wxAtoi(str);
    str = "Œrodek obrotu prostopad³ego: (";
    str << (*xPoint);
    str <<", " << (*yPoint) << ")";
    WxStaticText4->SetLabel(str);
}

void deformacjeFrm::WxEdit3E(wxCommandEvent& event)
{
    wxString str;
    str  = WxEdit3->GetLineText(0);
    (*xPointB) = wxAtoi(str);
    str = "Œrodek dystorsji: (";
    str << ((*xPointB));
    str <<", " << (*yPointB) << ")";
    WxStaticText8->SetLabel(str);
}

void deformacjeFrm::WxEdit4E(wxCommandEvent& event)
{
    wxString str;
    str  = WxEdit4->GetLineText(0);
    (*yPointB) = wxAtoi(str);
    
    str = "Œrodek dystorsji: (";
    str << (*xPointB);
    str <<", " << (*yPointB) << ")";
    WxStaticText8->SetLabel(str);
    (*yPointB) = -(*yPointB);
}

