
// myipcam.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#define TEST_MODE
//#define VERSION_1
#define VERSION_2
// We should be note that this project only work in Release mode
// Due to security policy of windows, in debug mode, we can not access file by fwscanf_s !

// CmyipcamApp:
// See myipcam.cpp for the implementation of this class
//

class CmyipcamApp : public CWinApp
{
public:
	CmyipcamApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CmyipcamApp theApp;

//Khai bao dinh nghia 
#define MAX_FILE_PATH 100
#define CONFIGFILE L"cauhinh_unicode.txt"
#define GRAY_LOW_LEVEL 0
#define GRAY_HIGH_LEVEL 255

#define DETECT_NN 0

#define CHUVI_DN  101
#define CHUVI_UP  102
#define CHUVI_MV  103

#define DORONG_DN 201
#define DORONG_UP 202
#define DORONG_MV 203

#define LECHTAM_DN1 301
#define LECHTAM_UP1 302
#define LECHTAM_DN2 303
#define LECHTAM_UP2 304
#define LECHTAM_MV1 305

#define KETQUA_ADD 5
#define KETQUA_DEL 6

#define VETDAN_ADD 7
#define VETDAN_DEL 8
#define VETDAN_END 9

#define TIMER_CLOCK 1
#define TIMER_VIDEO_TEST 2
#define TIMER_CAPTURE_FIRST_IMG 3