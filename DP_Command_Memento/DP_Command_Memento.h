
// DP_Command_Memento.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDP_Command_MementoApp:
// See DP_Command_Memento.cpp for the implementation of this class
//

class CDP_Command_MementoApp : public CWinApp
{
public:
	CDP_Command_MementoApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDP_Command_MementoApp theApp;