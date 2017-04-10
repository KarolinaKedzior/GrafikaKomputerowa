//---------------------------------------------------------------------------
//
// Name:        deformacjeApp.h
// Author:      Natalia Aleksandra
// Created:     2017-01-07 14:54:28
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __DEFORMACJEFRMApp_h__
#define __DEFORMACJEFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class deformacjeFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
