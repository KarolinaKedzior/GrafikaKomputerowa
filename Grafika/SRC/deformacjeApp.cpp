//---------------------------------------------------------------------------
//
// Name:        deformacjeApp.cpp
// Author:      Natalia Aleksandra
// Created:     2017-01-07 14:54:28
// Description: 
//
//---------------------------------------------------------------------------

#include "deformacjeApp.h"
#include "deformacjeFrm.h"

IMPLEMENT_APP(deformacjeFrmApp)

bool deformacjeFrmApp::OnInit()
{
    deformacjeFrm* frame = new deformacjeFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int deformacjeFrmApp::OnExit()
{
	return 0;
}
