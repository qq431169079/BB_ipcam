﻿
// myipcamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "myipcam.h"
#include "myipcamDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CmyipcamDlg dialog

CmyipcamDlg::CmyipcamDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYIPCAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmyipcamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	// Main interface group
	DDX_Control(pDX, IDC_STATIC_VIDEO, m_s);					// Video and image showing
	DDX_Control(pDX, IDC_EDIT_CS_TAM_NUM, m_CS_Tam_num);		// Hiển thị kết quả độ lẹch tâm bằng số
	DDX_Control(pDX, IDC_EDIT_CS_TAM_TEXT, m_CS_Tam_text);		
	DDX_Control(pDX, IDC_EDIT_CS_HUONG_NUM, m_CS_Huong_num);	// Hiển thị kết quả lệch hướng
	DDX_Control(pDX, IDC_EDIT_CS_HUONG_TEXT, m_CS_Huong_text);
	DDX_Control(pDX, IDC_LIST_RESULT, m_CS_list_result);
	// Main control group
	DDX_Control(pDX, IDC_BUTTON_CS_START, m_CS_start);
	DDX_Control(pDX, IDC_BUTTON_CS_EVALUATION, m_CS_evaluate);
	DDX_Control(pDX, IDC_BUTTON_CS_SAVE, m_CS_save);
	DDX_Control(pDX, IDC_BUTTON_CS_STOP, m_CS_stop);

	// IP camera control group
	DDX_Control(pDX, IDC_IPADDRESS_CAM, m_IP);
	DDX_Control(pDX, IDC_EDIT_USER, m_User);
	DDX_Control(pDX, IDC_EDIT_PASS, m_Pass);
	DDX_Control(pDX, IDC_EDIT_PORT, m_Port);
	DDX_Control(pDX, IDC_BUTTON_CONNECT, m_button_conn);
	DDX_Control(pDX, IDC_BUTTON_PTZ_HOME, m_button_ptz_home);
	DDX_Control(pDX, IDC_BUTTON_PTZ_UP, m_button_ptz_up);
	DDX_Control(pDX, IDC_BUTTON_PTZ_DOWN, m_button_ptz_down);
	DDX_Control(pDX, IDC_BUTTON_PTZ_LEFT, m_button_ptz_left);
	DDX_Control(pDX, IDC_BUTTON_PTZ_RIGHT, m_button_ptz_right);
	DDX_Control(pDX, IDC_BUTTON_PTZ_ZI, m_button_ptz_zoomin);
	DDX_Control(pDX, IDC_BUTTON_PTZ_ZO, m_button_ptz_zoomout);
	DDX_Control(pDX, IDC_BUTTON_PTZ_FP, m_button_ptz_focusin);
	DDX_Control(pDX, IDC_BUTTON_PTZ_FN, m_button_ptz_focusout);
	DDX_Control(pDX, IDC_STATIC_IP, m_label_ip);
	DDX_Control(pDX, IDC_STATIC_IP_PORT, m_label_port);
	DDX_Control(pDX, IDC_STATIC_IP_USER, m_label_user);
	DDX_Control(pDX, IDC_STATIC_IP_PW, m_label_pw);

	// Configuration group
	DDX_Control(pDX, IDC_EDIT_LICENSE, m_License);
	DDX_Control(pDX, IDC_COMBO_GUN_TYPE, m_CS_Gun_type);
	DDX_Control(pDX, IDC_EDIT_SHOOT_NUMBER, m_CS_Shoot_number);
	DDX_Control(pDX, IDC_EDIT_CS_CENTER_X, m_CS_Center_x);
	DDX_Control(pDX, IDC_EDIT_CS_CENTER_Y, m_CS_Center_y);
	DDX_Control(pDX, IDC_EDIT_CS_WIDTH_MM, m_CS_Width_mm);
	DDX_Control(pDX, IDC_EDIT_CS_WIDTH_PIX, m_CS_Width_pix);
	DDX_Control(pDX, IDC_EDIT_CS_PERI_PIX, m_CS_Peri_pix);
	DDX_Control(pDX, IDC_STATIC_CODE, m_label_code);
	DDX_Control(pDX, IDC_STATIC_CENTERX, m_label_centerx);
	DDX_Control(pDX, IDC_STATIC_CENTERY, m_label_centery);
	DDX_Control(pDX, IDC_STATIC_GUNTYPE, m_label_guntype);
	DDX_Control(pDX, IDC_STATIC_SHOOTNUMBER, m_label_shoot);
	DDX_Control(pDX, IDC_STATIC_PERIPIX, m_label_peripix);
	DDX_Control(pDX, IDC_STATIC_WIDTHMM, m_label_widthmm);
	DDX_Control(pDX, IDC_STATIC_WIDTHPIX, m_label_widthpix);
	DDX_Control(pDX, IDC_BUTTON_CS_CENTER, m_button_cs_center);
#ifdef VERSION_2

#elif VERSION_1
	DDX_Control(pDX, IDC_BUTTON_CS_WIDTH, m_button_cs_width);
	DDX_Control(pDX, IDC_BUTTON_CS_PERI, m_button_cs_peri);
#endif // VERSION_2
	DDX_Control(pDX, IDC_BUTTON_CS_CFG_SAVE, m_button_cs_save);
	DDX_Control(pDX, IDC_BUTTON_CS_CFG_CANCEL, m_button_cs_cancel);
	DDX_Control(pDX, IDC_BUTTON_CS_TAGET_CLEAR, m_button_target_clear);
	DDX_Control(pDX, IDC_STATIC_CFG, m_config_group);

	DDX_Control(pDX, IDC_STATIC_TIME, m_CurrentTime);
}

BEGIN_MESSAGE_MAP(CmyipcamDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CmyipcamDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_UP, &CmyipcamDlg::OnBnClickedButtonPtzUp)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_LEFT, &CmyipcamDlg::OnBnClickedButtonPtzLeft)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_DOWN, &CmyipcamDlg::OnBnClickedButtonPtzDown)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_HOME, &CmyipcamDlg::OnBnClickedButtonPtzHome)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_RIGHT, &CmyipcamDlg::OnBnClickedButtonPtzRight)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_ZO, &CmyipcamDlg::OnBnClickedButtonPtzZo)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_ZI, &CmyipcamDlg::OnBnClickedButtonPtzZi)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_FP, &CmyipcamDlg::OnBnClickedButtonPtzFp)
	ON_BN_CLICKED(IDC_BUTTON_PTZ_FN, &CmyipcamDlg::OnBnClickedButtonPtzFn)
	ON_BN_CLICKED(IDC_BUTTON_CS_EVALUATION, &CmyipcamDlg::OnBnClickedButtonCsEvaluation)
	ON_BN_CLICKED(IDC_BUTTON_CS_START, &CmyipcamDlg::OnBnClickedButtonCsStart)

	ON_BN_CLICKED(IDC_BUTTON_CS_CFG_CANCEL, &CmyipcamDlg::OnBnClickedButtonCsCfgCancel)
	ON_BN_CLICKED(IDC_BUTTON_CS_CFG_SAVE, &CmyipcamDlg::OnBnClickedButtonCsCfgSave)
	ON_BN_CLICKED(IDC_BUTTON_CONFIG, &CmyipcamDlg::OnBnClickedButtonConfig)
	ON_BN_CLICKED(IDC_BUTTON_CS_CENTER, &CmyipcamDlg::OnBnClickedButtonCsCenter)
#ifdef VERSION_2

#elif VERSION_1
	ON_BN_CLICKED(IDC_BUTTON_CS_WIDTH, &CmyipcamDlg::OnBnClickedButtonCsWidth)
#endif // VERSION_2
	
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CmyipcamDlg message handlers

BOOL CmyipcamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetWindowPos(NULL, -1, -1, 1440, 850, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	m_s.SetWindowPos(NULL, -1, -1, 800, 600, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);


	m_IP.SetWindowText(_T("192.168.1.209"));
	m_Port.SetWindowText(_T("209"));
	m_User.SetWindowText(_T("admin"));
	m_Pass.SetWindowText(_T("admin"));

	// init camera
	int iInit = HOEM_Cam_Init();				//Initial HOEM_IPCam_SDK
	HOEM_Play_Init();				//Initial HOEM_Play_SDK

	COLORREF cr = RGB(0x14, 0x00, 0x14);
	m_Color = CreateSolidBrush(RGB(0x14, 0x00, 0x14));	//ColorKey
	HOEM_Play_SetUseOverlay(false, cr);	//Set Use Overlay

	HOEM_Play_CreatePlayer();		//Create HOEM_Play_SDK Play Environment
	CenterWindow();

	//HOEM_Play_SetIOnly(0,true);	//Test Play I Frame Only

	m_HWND_video = m_s;				//Record Window HWND
	m_s.GetClientRect(&m_Rect_video);	//Record Window RECT
	//Set PlayBack Window
	HOEM_Play_SetPlayWindow(m_HWND_video, 0, 800, 600);
	//HOEM_Play_SetPlayWindow(m_HWND, 0, m_Rect.right - m_Rect.left, m_Rect.bottom - m_Rect.top);


	// generate active code
	cs_seed_code = ActiveCode(GetSerialDiskC());
	CString str_code;
	str_code.Format(_T("%u"), cs_seed_code);
	m_License.SetWindowText(str_code);

	// add gun type list
	addGunList();
	// read configuration file
	readConfig();

	//Create OpenCV image frame
	cvNamedWindow("opencv_image_frame", 0);
	cvResizeWindow("opencv_image_frame", 800, 600);
	m_HWND_opencv = (HWND)cvGetWindowHandle("opencv_image_frame");

	//cvSetMouseCallback("opencv_image_frame", Interact_opencv, &cs_mode);
	cvSetMouseCallback("opencv_image_frame", Interact_opencv, this);

	// invisible configuration interface
	enableConfigGUI(0);

	// Setup display of list of recent results
	m_CS_list_result.SetWindowPos(NULL, 0, 0, 550, 330, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	setupListResult();

	cmd = DETECT_NN;
	
	// Timer
	CFont *m_pFont = new CFont();
	m_pFont->CreatePointFont(300, _T("Arial"));
	m_CurrentTime.SetWindowPos(0, 0, 0, 200, 100, SWP_NOMOVE | SWP_NOZORDER);
	m_CurrentTime.SetFont(m_pFont, 1);

	SetTimer(TIMER_CLOCK, 200, 0); // for clock
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmyipcamDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmyipcamDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Function for GUI control
void CmyipcamDlg::enableConfigGUI(int enable)
{
	if (enable == 1) // enable all buttons and edit in Config group
	{
		// for ip camera
		m_button_conn.ShowWindow(TRUE);
		m_IP.ShowWindow(TRUE);
		m_button_ptz_home.ShowWindow(TRUE);
		m_button_ptz_up.ShowWindow(TRUE);
		m_button_ptz_down.ShowWindow(TRUE);
		m_button_ptz_left.ShowWindow(TRUE);
		m_button_ptz_right.ShowWindow(TRUE);
		m_button_ptz_zoomin.ShowWindow(TRUE);
		m_button_ptz_zoomout.ShowWindow(TRUE);
		m_button_ptz_focusin.ShowWindow(TRUE);
		m_button_ptz_focusout.ShowWindow(TRUE);
		m_label_ip.ShowWindow(TRUE);
		m_label_port.ShowWindow(TRUE);
		m_label_user.ShowWindow(TRUE);
		m_label_pw.ShowWindow(TRUE);
		m_Port.ShowWindow(TRUE);
		m_User.ShowWindow(TRUE);
		m_Pass.ShowWindow(TRUE);
		// for configuration 
		m_label_code.ShowWindow(TRUE);
		m_License.ShowWindow(TRUE);
		m_label_guntype.ShowWindow(TRUE);
		m_CS_Gun_type.ShowWindow(TRUE);
		m_label_shoot.ShowWindow(TRUE);
		m_CS_Shoot_number.ShowWindow(TRUE);
		m_label_centerx.ShowWindow(TRUE);
		m_CS_Center_x.ShowWindow(TRUE);
		m_label_centery.ShowWindow(TRUE);
		m_CS_Center_y.ShowWindow(TRUE);
		m_label_peripix.ShowWindow(TRUE);
		m_CS_Peri_pix.ShowWindow(TRUE);
		m_label_widthmm.ShowWindow(TRUE);
		m_CS_Width_mm.ShowWindow(TRUE);
		m_label_widthpix.ShowWindow(TRUE);
		m_CS_Width_pix.ShowWindow(TRUE);
		m_button_cs_center.ShowWindow(TRUE);
#ifdef VERSION_2

#elif VERSION_1
		m_button_cs_width.ShowWindow(TRUE);
		m_button_cs_peri.ShowWindow(TRUE);
#endif // VERSION_2
		m_button_cs_save.ShowWindow(TRUE);
		m_button_cs_cancel.ShowWindow(TRUE);
		m_button_target_clear.ShowWindow(TRUE);
		m_config_group.ShowWindow(TRUE);
		// Hide list of recent results
		m_CS_list_result.ShowWindow(FALSE);
		m_CurrentTime.ShowWindow(FALSE);
	}
	if (enable == 0) // disable all buttons and edit in Config group
	{
		// for ip camera
		m_button_conn.ShowWindow(FALSE);
		m_IP.ShowWindow(FALSE);
		m_button_ptz_home.ShowWindow(FALSE);
		m_button_ptz_up.ShowWindow(FALSE);
		m_button_ptz_down.ShowWindow(FALSE);
		m_button_ptz_left.ShowWindow(FALSE);
		m_button_ptz_right.ShowWindow(FALSE);
		m_button_ptz_zoomin.ShowWindow(FALSE);
		m_button_ptz_zoomout.ShowWindow(FALSE);
		m_button_ptz_focusin.ShowWindow(FALSE);
		m_button_ptz_focusout.ShowWindow(FALSE);
		m_label_ip.ShowWindow(FALSE);
		m_label_port.ShowWindow(FALSE);
		m_label_user.ShowWindow(FALSE);
		m_label_pw.ShowWindow(FALSE);
		m_Port.ShowWindow(FALSE);
		m_User.ShowWindow(FALSE);
		m_Pass.ShowWindow(FALSE);
		// for configuration 
		m_label_code.ShowWindow(FALSE);
		m_License.ShowWindow(FALSE);
		m_label_guntype.ShowWindow(FALSE);
		m_CS_Gun_type.ShowWindow(FALSE);
		m_label_shoot.ShowWindow(FALSE);
		m_CS_Shoot_number.ShowWindow(FALSE);
		m_label_centerx.ShowWindow(FALSE);
		m_CS_Center_x.ShowWindow(FALSE);
		m_label_centery.ShowWindow(FALSE);
		m_CS_Center_y.ShowWindow(FALSE);
		m_label_peripix.ShowWindow(FALSE);
		m_CS_Peri_pix.ShowWindow(FALSE);
		m_label_widthmm.ShowWindow(FALSE);
		m_CS_Width_mm.ShowWindow(FALSE);
		m_label_widthpix.ShowWindow(FALSE);
		m_CS_Width_pix.ShowWindow(FALSE);
		m_button_cs_center.ShowWindow(FALSE);
#ifdef VERSION_2

#elif VERSION_1
		m_button_cs_width.ShowWindow(FALSE);
		m_button_cs_peri.ShowWindow(FALSE);
#endif // VERSION_2
		
		m_button_cs_save.ShowWindow(FALSE);
		m_button_cs_cancel.ShowWindow(FALSE);
		m_button_target_clear.ShowWindow(FALSE);
		m_config_group.ShowWindow(FALSE);
		// Show list of recent results
		m_CS_list_result.ShowWindow(TRUE);
		m_CurrentTime.ShowWindow(TRUE);
	}
}

/* Setup list for display the recent results*/
void CmyipcamDlg::setupListResult()
{
	m_CS_list_result.InsertColumn(1, L"Số súng", LVCFMT_LEFT, 100);
	m_CS_list_result.InsertColumn(2, L"Số đạn", LVCFMT_CENTER, 80);
	m_CS_list_result.InsertColumn(3, L"Lệch tầm", LVCFMT_CENTER, 125);
	m_CS_list_result.InsertColumn(4, L"Lệch hướng", LVCFMT_CENTER, 125);
	m_CS_list_result.InsertColumn(4, L"Độ chụm", LVCFMT_CENTER, 120);
}
void CmyipcamDlg::insertListResult()
{

}
/* Generate Active code for License*/
DWORD CmyipcamDlg::ActiveCode(DWORD serialOfC)
{
	DWORD kq;
	DWORD ng, du;
	kq = serialOfC + 100;
	ng = kq / 1000;
	du = kq % 1000;
	kq = du * 543 + ng * 123;
	return kq;
}
DWORD CmyipcamDlg::GetSerialDiskC()
{
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{
	}
	else
	{
		serialNumber = -1;
	}
	return serialNumber;
}



void CmyipcamDlg::OnBnClickedButtonConnect()
{
	
	// TODO: Add your control notification handler code here
	//Connect Ch1 of IP camera
	CStringW cIP, cPort, cUser, cPass;
	m_IP.GetWindowText(cIP);
	m_Port.GetWindowText(cPort);
	m_User.GetWindowText(cUser);
	m_Pass.GetWindowText(cPass);
	Connect_Info cInfo;
	CT2A acIP(cIP); // convert unicode CString to char*
	cInfo.sIP = (char*)(LPCTSTR)acIP.m_psz;
	cInfo.iPort = _wtoi((LPCTSTR)cPort);
	CT2A acUser(cUser);
	cInfo.sUser = (char*)(LPCTSTR)acUser.m_psz;
	CT2A acPass(cPass);
	cInfo.sPass = (char*)(LPCTSTR)acPass.m_psz;
	cInfo.iCh = 0;
	int iRes = HOEM_Cam_Create(&m_hCam, cInfo, EventCallback, (int)this);
	int iType, iVideoChannel, iAudioChannel;
	iRes = HOEM_Cam_GetCamera_TypeChannel(m_hCam, iType, iVideoChannel, iAudioChannel);
	iRes = HOEM_Cam_SetIPCamStreamNum(m_hCam, 0, 0);
	iRes = HOEM_Cam_SetRtspParams(m_hCam, HUDP, "v2");

	iRes = HOEM_Cam_Connect(m_hCam, FrameCallback, (int)this, HIPCam_VIDEO);
	iRes = HOEM_Cam_Connect(m_hCam, FrameCallback, (int)this, HIPCam_AUDIO);
	iRes = HOEM_Cam_StartReceive(m_hCam, HIPCam_VIDEO);
	iRes = HOEM_Cam_StartReceive(m_hCam, HIPCam_AUDIO);
	iRes = HOEM_Cam_GetResolutionSet(m_hCam, 2, m_lWidth, m_lHeight);
#ifdef TEST_MODE
	CString str;
	str.Format(_T("%d"), m_lWidth);
	m_CS_Tam_num.SetWindowText(str);
	str.Format(_T("%d"), m_lHeight);
	m_CS_Huong_num.SetWindowText(str);
#endif // TEST_MODE

	
	//Ch1 Start Play
	HOEM_Play_Play(0);
	
	
}

int CALLBACK CmyipcamDlg::EventCallback(int iContext, HANDLE hCam, unsigned char ucChannel, int iEventNum)
{
	
	CmyipcamDlg * pForm = (CmyipcamDlg*)iContext;
	int iCh = ucChannel;
	if (iEventNum != pForm->m_Status)
	{
		CString sMsg("IPCam ");
		char cBuf[20];
		if (iEventNum == 0)
		{
			_itoa_s(iCh, cBuf, 10);
			sMsg += cBuf;
			sMsg += " is Connect";
			pForm->MessageBox(sMsg, _T("Warning"), MB_OK);
		}
		else if (iEventNum < 0)
		{
			_itoa_s(iCh, cBuf, 10);
			sMsg += cBuf;
			sMsg += " is Unconnect";
			pForm->MessageBox(sMsg, _T("Warning"), MB_OK);
		}
		pForm->m_Status = iEventNum;
	}
	
	return 1;
}

int iCountV = 0;
int iCountA = 0;
int CALLBACK CmyipcamDlg::FrameCallback(int iContext, unsigned char ucChannel, HFrame *pFrame, HVideo_Info VInfo)
{
	
	CmyipcamDlg * pForm = (CmyipcamDlg*)iContext;
	int iCh = ucChannel;

	//Push Frame To Do Live PlayBack
	if (pFrame->iFrameType == 2 || pFrame->iFrameType == 3 || pFrame->iFrameType == 4 || pFrame->iFrameType == 5 || pFrame->iFrameType == 7)
	{
		
		int iRes = HOEM_Play_PushPlayFrame(pForm->m_HWND_video, iCh, pFrame);
	}
	
	
	pForm->m_lWidth = VInfo.iWidth;
	pForm->m_lHeight = VInfo.iHeight;

	return 1;
}

void CmyipcamDlg::OnBnClickedButtonPtzUp()
{
	HOEM_Cam_SetPTZ_Up(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzLeft()
{
	HOEM_Cam_SetPTZ_Left(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzDown()
{
	HOEM_Cam_SetPTZ_Down(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzHome()
{
	HOEM_Cam_SetPTZ_Home(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzRight()
{
	HOEM_Cam_SetPTZ_Right(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzZo()
{
	HOEM_Cam_SetPTZ_ZoomOut(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzZi()
{
	HOEM_Cam_SetPTZ_ZoomIn(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzFp()
{
	HOEM_Cam_SetPTZ_FocusIn(m_hCam);
}

void CmyipcamDlg::OnBnClickedButtonPtzFn()
{
	HOEM_Cam_SetPTZ_FocusOut(m_hCam);
}




/*****************************
 Functions for HCS
 *****************************/
/* Read configuration file*/
int CmyipcamDlg::readConfig()
{
	int faccess_out;
	int x;
	FILE *myFile;
	WCHAR Text[100];
	WCHAR fullFileName[MAX_FILE_PATH];
	WCHAR currentDir[MAX_FILE_PATH];
	GetCurrentDirectory(MAX_FILE_PATH, currentDir);
	wsprintf(fullFileName, L"%s\\%s", currentDir, CONFIGFILE);
#ifdef TEST_MODE
	OutputDebugString(_T("fullFileName "));
	OutputDebugString(fullFileName);
	OutputDebugString(_T("\n"));
#endif // TEST_MODE
	try
	{
		faccess_out = _wfopen_s(&myFile, fullFileName, L"rt+,ccs=UNICODE");
		if (myFile != NULL)
		{
			fwscanf_s(myFile, L"%d%s", &cs_TV10_LechX, &Text,sizeof(Text));
			fwscanf_s(myFile, L"%d%s", &cs_TV10_LechY, &Text, sizeof(Text));
			fwscanf_s(myFile, L"%d%s", &cs_DoRongBia_mm, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_DoRongBia_ps, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_active_code, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_ContourLen, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_SoPhatBan, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_LoaiSung, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_ThoiGian, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_scType, &Text);
			fwscanf_s(myFile, L"%d%s", &cs_IntevalTime, &Text);
			fwscanf_s(myFile, L"%s", &cs_FileName);
#ifdef TEST_MODE
			OutputDebugString(_T("read line "));
			OutputDebugString(Text);
			OutputDebugString(_T("\n"));
#endif // TEST_MODE

			fclose(myFile);
			showConfig();
		}
		else
		{
#ifdef TEST_MODE
			TRACE(_T("Can't open file %s\n"), fullFileName);
			MessageBox(_T("Can't open file"), _T("Error"),
				MB_ICONERROR | MB_OK);
#endif // TEST_MODE
		}
	}
	catch (const std::exception&)
	{
		TRACE(_T("File error %s\n"), fullFileName);
		MessageBox(_T("Can't open file"), _T("Error"),
			MB_ICONERROR | MB_OK);
	}
	// set loại súng trong combobox
	m_CS_Gun_type.SetCurSel(cs_LoaiSung-1);
	
	if (cs_LoaiSung == 18) // danh cho sung 12ly7
	{
		cs_CoDan = (float)1.4;
	}
	else
	{
		cs_CoDan = 1.0;
	}
	cs_CON_LEN_MAX = cs_ContourLen + cs_ContourLenRange;
	cs_CON_LEN_MIN = cs_ContourLen - cs_ContourLenRange;
	cs_BanKinh = (int)(cs_DoRongBia_ps*0.49);
	
	cs_saiso = (int)((cs_active_code - cs_seed_code)%100000);
	cs_saiso = abs(cs_saiso);
	x = rand();
	if (cs_saiso != 0) {
		cs_saiso = 1000 + cs_saiso * (x % 1000);
		MessageBox(_T("Chương trình chưa được đăng ký. Hãy gửi mã chương trình cho chúng tôi!"), _T("Warning"),
			MB_ICONERROR | MB_OK);
	}

	return 0;
}
// show all configuration data on sceen
void CmyipcamDlg::showConfig()
{
	CString str;
	str.Format(_T("%d"), cs_TV10_LechX);
	m_CS_Center_x.SetWindowText(str);
	str.Format(_T("%d"), cs_TV10_LechY);
	m_CS_Center_y.SetWindowText(str);
	str.Format(_T("%d"), cs_DoRongBia_ps);
	m_CS_Width_pix.SetWindowText(str);
	str.Format(_T("%d"), cs_DoRongBia_mm);
	m_CS_Width_mm.SetWindowText(str);
	str.Format(_T("%d"), cs_ContourLen);
	m_CS_Peri_pix.SetWindowText(str);
	str.Format(_T("%d"), cs_SoPhatBan);
	m_CS_Shoot_number.SetWindowText(str);

}

int CmyipcamDlg::addGunList()
{
	const TCHAR* cs_GunType[] = { \
		_T("01 - K54"),\
		_T("02 - K59"),\
		_T("03 - K44"),\
		_T("04 - VZ52/VZ58"),\
		_T("05 - CKC"),\
		_T("06 - K63"),\
		_T("07 - K30"),\
		_T("08 - CBД"),\
		_T("09 - AK"),\
		_T("10 - VZ58TL"),\
		_T("11 - PПД"),\
		_T("12 - PПK"),\
		_T("13 - ДП, ДПM, PП-46"),\
		_T("14 - CГM, K57"),\
		_T("15 - CГ43, K53"),\
		_T("16 - K67"),\
		_T("17 - ПKMC"),\
		_T("18 - PK12ly7") };
	for (int i = 0; i<18; i++)
	{
		m_CS_Gun_type.AddString(cs_GunType[i]);
	}
	return 0;
}

void CmyipcamDlg::OnBnClickedButtonCsCfgCancel()
{
	// When new configuration does not need to be saved, the old configuration in file 
	// need to be re-loaded.
	readConfig();
}

void CmyipcamDlg::OnBnClickedButtonCsCfgSave()
{
	// TODO: Add your control notification handler code here
}

/* capture the first image  */
int CmyipcamDlg::captureImage_F()
{
	// capture current image
	std::string strName = "img_f.bmp";
	if (cs_scType == 2)	// ip cam
	{
		if (HOEM_Play_SnapShot_BMP(0, (char*)strName.c_str(), strName.length()) == PLAY_SNAPSHOT_SUCCESS)
		{
			img_first = cvLoadImage("img_f.bmp", CV_LOAD_IMAGE_COLOR);
		}
	}
	else if (cs_scType == 3) // test images
	{
		cvReleaseImage(&img_first);
		img_first = cvCreateImage(cvGetSize(img_video_test),
			img_video_test->depth,
			img_video_test->nChannels);
		cvCopy(img_video_test, img_first, 0);
	}

	
#ifdef TEST_MODE
	cvShowImage("First image", img_first);
#endif // TEST_MODE

	return 0;
}

/* capture image for evaltuation */
int CmyipcamDlg::captureImage_E()
{
	// capture current image
	std::string strName = "img_e.bmp";
	if (cs_scType == 2)
	{
		if (HOEM_Play_SnapShot_BMP(0, (char*)strName.c_str(), strName.length()) == PLAY_SNAPSHOT_SUCCESS)
		{
			img_evaluate = cvLoadImage("img_e.bmp", CV_LOAD_IMAGE_COLOR);
		}
	}
	else if (cs_scType == 3)
	{
		cvReleaseImage(&img_evaluate);
		img_evaluate = cvCreateImage(cvGetSize(img_video_test),
			img_video_test->depth,
			img_video_test->nChannels);
		cvCopy(img_video_test, img_evaluate, 0);
	}
	// push opencv frame into CStatic
	::SetParent(m_HWND_opencv, GetDlgItem(IDC_STATIC_VIDEO)->m_hWnd);
	// show image on opencv frame
	cvShowImage("opencv_image_frame", img_evaluate);
	
	
	return 0;
}

/* capture image for estimate center point of target*/
int CmyipcamDlg::captureImage_C()
{
	// capture current image
	std::string strName = "img_c.bmp";
	int iRet = 0;
	try
	{
		iRet = HOEM_Play_SnapShot_BMP(0, (char*)strName.c_str(), strName.length());
		if (iRet == PLAY_SNAPSHOT_SUCCESS)
		{
			if (cs_scType == 2)
				img_centerDetect = cvLoadImage("img_c.bmp", CV_LOAD_IMAGE_COLOR);
			else if (cs_scType == 3)
				img_centerDetect = cvLoadImage("..\\Images\\Tag1.jpg", CV_LOAD_IMAGE_COLOR);

			img_temp = cvCreateImage(cvGetSize(img_centerDetect),
				img_centerDetect->depth,
				img_centerDetect->nChannels);
			// push opencv frame into CStatic
			::SetParent(m_HWND_opencv, GetDlgItem(IDC_STATIC_VIDEO)->m_hWnd);
			// show image on opencv frame
			cvShowImage("opencv_image_frame", img_centerDetect);
		}
	}
	catch (const std::exception&)
	{

	}
	

	return 0;
}

/* capture image for estimate width of target*/
int CmyipcamDlg::captureImage_W()
{
	// capture current image
	std::string strName = "img_w.bmp";
	if (HOEM_Play_SnapShot_BMP(0, (char*)strName.c_str(), strName.length()) == PLAY_SNAPSHOT_SUCCESS)
	{
		img_widthDetect = cvLoadImage("img_w.bmp", CV_LOAD_IMAGE_COLOR);
		// push opencv frame into CStatic
		::SetParent(m_HWND_opencv, GetDlgItem(IDC_STATIC_VIDEO)->m_hWnd);
		// show image on opencv frame
		cvShowImage("opencv_image_frame", img_widthDetect);
	}

	return 0;
}

void CmyipcamDlg::Interact_opencv(int event, int x, int y, int flags, void* param)
{
	CvPoint T1, T2;
	int bk2 = 6;
	CmyipcamDlg *dlg = (CmyipcamDlg *)param;

	if (dlg->cs_mode == 0) {
		if (event == CV_EVENT_LBUTTONDOWN)
		{
			cvCircle(dlg->img_evaluate, cvPoint(x, y), bk2, cvScalar(0, 0, 255), 3);
			cvShowImage("opencv_image_frame", dlg->img_evaluate);		
			
		}
		if (event == CV_EVENT_LBUTTONUP)
		{


		}
		if (event == CV_EVENT_MOUSEMOVE)
		{

		}
	}
	/////////////// Detect center, width, peri of target ////////////////
	if (dlg->cs_mode == 1)
	{
		if (event == CV_EVENT_LBUTTONDOWN)
		{
			if (dlg->cmd == DETECT_NN)
			{
				dlg->xm1 = x; dlg->ym1 = y;
				dlg->xm2 = x; dlg->ym2 = y;
				dlg->cmd = LECHTAM_DN1;
			}
			else
			{
				if ((dlg->cmd == LECHTAM_UP1))
				{
					dlg->xm1 = x; dlg->ym1 = y;
					dlg->xm2 = x; dlg->ym2 = y;
					dlg->cmd = LECHTAM_DN2;
				}
			}
		}
		if (event == CV_EVENT_LBUTTONUP)
		{
			if ((dlg->cmd == LECHTAM_DN1) || (dlg->cmd == LECHTAM_MV1))
			{
				dlg->xm2 = x; dlg->ym2 = y;
				dlg->cmd = LECHTAM_UP1;
				cvRectangle(dlg->img_centerDetect, cvPoint(dlg->xm1, dlg->ym1), 
					cvPoint(dlg->xm2, dlg->ym2), cvScalar(0, 0, 185, 0), 2);
				cvShowImage("opencv_image_frame", dlg->img_centerDetect);
				dlg->Detect_LT_Exe();
			}
			if ((dlg->cmd == LECHTAM_DN2))
			{
				dlg->xm2 = x; dlg->ym2 = y;
				dlg->cmd = LECHTAM_UP2;
				cvCircle(dlg->img_centerDetect, cvPoint(dlg->xm2, dlg->ym2), 4, cvScalar(25, 255, 0), 2);
				cvShowImage("opencv_image_frame", dlg->img_centerDetect);
				dlg->Detect_LT_Exe();
			}
			
		}
		if (event == CV_EVENT_MOUSEMOVE)
		{
			if ((dlg->cmd == LECHTAM_DN1) || (dlg->cmd == LECHTAM_MV1))
			{
				dlg->xm2 = x; dlg->ym2 = y;
				dlg->cmd = LECHTAM_MV1;
				cvCopy(dlg->img_centerDetect, dlg->img_temp, 0);
				cvRectangle(dlg->img_temp, cvPoint(dlg->xm1, dlg->ym1), 
					cvPoint(dlg->xm2, dlg->ym2), cvScalar(0, 0, 185, 0), 2);
				cvShowImage("opencv_image_frame", dlg->img_temp);
			}
			
		}
		
		
	}
	

}

void CmyipcamDlg::OnBnClickedButtonConfig()
{
	// TODO: Add your control notification handler code here
	if (m_IP.IsWindowVisible())
	{
		enableConfigGUI(0);
	}
	else
	{
		enableConfigGUI(1);
	}
	
}

/* Methods for Center detection*/
void CmyipcamDlg::OnBnClickedButtonCsCenter()
{
	// stop video
	HOEM_Play_Pause(0);
	KillTimer(TIMER_VIDEO_TEST);
	// capture image and show on Cstatic
	int iRes = captureImage_C();
	cs_mode = 1;
}

int CmyipcamDlg::Detect_LT_Exe()
{
	CString str;
	if (cmd != DETECT_NN)
	{
		switch (cmd)
		{
		case LECHTAM_MV1:
			//Detect_LT_Shn(hDlg);
			break;
		case LECHTAM_UP2:
			// show độ lệch tâm
			cs_TV10_LechX = (int)(xm2 / HesoZoom) - XT.x;
			str.Format(_T("%d"), cs_TV10_LechX);
			m_CS_Center_x.SetWindowText(str);
			cs_TV10_LechY = (int)(ym2 / HesoZoom) - XT.y;
			str.Format(_T("%d"), cs_TV10_LechY);
			m_CS_Center_y.SetWindowText(str);
			// continue play video
			//cvDestroyWindow("Video");
			cmd = DETECT_NN;
			break;
		case LECHTAM_UP1:
			int iRet = detectCenter(xm1, ym1, xm2, ym2, HesoZoom, img_centerDetect
#ifdef VERSION_2
				,&cs_DoRongBia_ps, &cs_ContourLen
#endif // VESION_2
			);
			if (iRet == 1)
			{
				// draw the detected center point
				cvCircle(img_centerDetect, XT, 4, cvScalar(255, 64, 0), 2);
				cvShowImage("opencv_image_frame", img_centerDetect);
#ifdef VERSION_2
				// show the target's width
				str.Format(_T("%d"), (int)(cs_DoRongBia_ps / HesoZoom));
				m_CS_Width_pix.SetWindowText(str);
				// show chu vi bia
				str.Format(_T("%d"), cs_ContourLen);
				m_CS_Peri_pix.SetWindowText(str);
#endif // VESION_2

			}
			else { // redraw request
				cmd = DETECT_NN;
			}
			
			break;
		}
	}
	return 0;
}

#ifdef VERSION_2

#elif VERSION_1

/* Methods for xác định độ rộng bia*/
void CmyipcamDlg::OnBnClickedButtonCsWidth()
{
	// stop video
	HOEM_Play_Pause(0);
	// capture image and show on Cstatic
	int iRes = captureImage_W();
	cs_mode = 2;
}

#endif // VERSION_2

/* bắt đầu bắn*/
void CmyipcamDlg::OnBnClickedButtonCsStart()
{
	int iRet;
	::SetParent(m_HWND_video, GetDlgItem(IDC_STATIC_VIDEO)->m_hWnd);
	cs_mode = -1; // mouse process
	if (cs_scType == 2)	// ip cam
	{
		HOEM_Play_Play(0);
		// capture the first image for comparison
		iRet = captureImage_F();
	}
	else if (cs_scType == 3) // test images
	{
		SetTimer(TIMER_VIDEO_TEST, 1000, 0); // for test video (sequence of sample images)
		SetTimer(TIMER_CAPTURE_FIRST_IMG, 1100, 0); // wait for awhile then capture the first image 
	}
	
	
	
}


/* đánh giá kết quả bắn*/
void CmyipcamDlg::OnBnClickedButtonCsEvaluation()
{
	int iRet;
	// stop video
	HOEM_Play_Pause(0);
	KillTimer(TIMER_VIDEO_TEST);
	// capture image and show on Cstatic 
	iRet = captureImage_E();
	cs_preProcess();
	cs_mode = 0;
}



/* Common methods for HCS*/
int CmyipcamDlg::detectCenter(int xm1, int ym1, int xm2, int ym2, float zoom, IplImage *img
#ifdef VERSION_2
	, int *width, int *cv
#endif // VERSION_2

)
{
	int Nc = 0, maxp = 0;
	CvSeq *mlgc;
	IplImage *imgC;
	//cvReleaseImage(&imgC);
	imgC = cvCreateImage(cvSize(img->width, img->height), 8, 1);
	cvCvtColor(img, imgC, CV_BGR2GRAY);
	cvSmooth(imgC, imgC, CV_GAUSSIAN, 7, 7);
	cvThreshold(imgC, imgC, 128, 255, CV_THRESH_OTSU);
	if ((abs(xm1 - xm2) > 10) && (abs(ym1 - ym2) > 10))
	{
		//1. Đặt vùng xử lý
		if ((xm1 < xm2)&(ym1 < ym2))
			cvSetImageROI(imgC, cvRect((int)(xm1 / zoom), (int)(ym1 / zoom),
				abs((int)(xm2 / zoom) - (int)(xm1 / zoom)),
				abs((int)(ym2 / zoom) - (int)(ym1 / zoom))));
		if ((xm1 < xm2)&(ym2 < ym1))
			cvSetImageROI(imgC, cvRect((int)(xm1 / zoom), (int)(ym2 / zoom),
				abs((int)(xm2 / zoom) - (int)(xm1 / zoom)),
				abs((int)(ym2 / zoom) - (int)(ym1 / zoom))));
		if ((xm2 < xm1)&(ym1 < ym2))
			cvSetImageROI(imgC, cvRect((int)(xm2 / zoom), (int)(ym1 / zoom),
				abs((int)(xm2 / zoom) - (int)(xm1 / zoom)),
				abs((int)(ym2 / zoom) - (int)(ym1 / zoom))));
		if ((xm2 < xm1)&(ym2 < ym1))
			cvSetImageROI(imgC, cvRect((int)(xm2 / zoom), (int)(ym2 / zoom),
				abs((int)(xm2 / zoom) - (int)(xm1 / zoom)),
				abs((int)(ym2 / zoom) - (int)(ym1 / zoom))));

		//2. Xử lý và tìm contourn dài nhất
		CvMemStorage* storage;
		storage = cvCreateMemStorage();
		CvSeq *first_contour = NULL;
		CvSeq *f1;
		Nc = cvFindContours(imgC, storage, &first_contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
		if (Nc > 0)
		{
			for (f1 = first_contour; f1 != NULL; f1 = f1->h_next)
			{
				if ((f1->total > maxp) && ((abs((int)(xm2 / zoom) - (int)(xm1 / zoom)) + abs((int)(ym2 / zoom) - (int)(ym1 / zoom))) * 2 - 15 > f1->total))
				{
					mlgc = f1;
					maxp = f1->total;
#ifdef VERSION_2
					conCenterPointAndWidth(mlgc, &XT, width);
					*cv = mlgc->total;
#elif VERSION_1
					conCenterPoint(mlgc, &XT);
#endif // VERSION_2
				}
			}
			if (xm1 < xm2) {
				XT.x = XT.x + (int)(xm1 / zoom);
			}
			else {
				XT.x = XT.x + (int)(xm2 / zoom);
			}

			if (ym1 < ym2) {
				XT.y = XT.y + (int)(ym1 / zoom);
			}
			else {
				XT.y = XT.y + (int)(ym2 / zoom);
			}

		}
		//cvReleaseImage(&imgC);  //cvResetImageROI(imgC);
		//cvReleaseMemStorage(&storage);
	}
	else {
		return 0;
	}
	return 1;
}
#ifdef VERSION_2
// Tìm tâm điểm và độ rộng ảnh bia
int CmyipcamDlg::conCenterPointAndWidth(CvSeq *mlgc, CvPoint *cvP, int *width)
{
	CvPoint* p;
	double TongX, TongY;
	TongX = 0;
	TongY = 0;
	int min, max;
	for (int i = 0; i<mlgc->total; ++i)
	{
		p = CV_GET_SEQ_ELEM(CvPoint, mlgc, i);
		TongX = TongX + p->x;
		TongY = TongY + p->y;
	}
	cvP->x = (int)(TongX / (mlgc->total) + 0.5);
	cvP->y = (int)(TongY / (mlgc->total) + 0.5);
	// width = max - min
	min = cvP->x;
	max = cvP->x;
	for (int i = 0; i<mlgc->total; ++i)
	{
		p = CV_GET_SEQ_ELEM(CvPoint, mlgc, i);
		if (min > p->x) min = p->x;
		if (max < p->x) max = p->x;
	}
	*width = max - min;
	return 1;
}
#elif VERSION_1

// Tìm điểm trung tâm bằng cách tính tọa độ trung bình của tất cả các điểm biên
int CmyipcamDlg::conCenterPoint(CvSeq *mlgc, CvPoint *cvP)
{
	CvPoint* p;
	double TongX, TongY;
	TongX = 0;
	TongY = 0;
	for (int i = 0; i<mlgc->total; ++i)
	{
		p = CV_GET_SEQ_ELEM(CvPoint, mlgc, i);
		TongX = TongX + p->x;
		TongY = TongY + p->y;
	}
	cvP->x = (int)(TongX / (mlgc->total) + 0.5);
	cvP->y = (int)(TongY / (mlgc->total) + 0.5);
	return 1;
}

#endif // VERSION_2



void CmyipcamDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == TIMER_CLOCK)
	{
		// TODO: Add your message handler code here and/or call default
		CTime CurrentTime = CTime::GetCurrentTime();

		int iHours = CurrentTime.GetHour();
		int iMinutes = CurrentTime.GetMinute();
		int iSeconds = CurrentTime.GetSecond();
		CString strHours, strMinutes, strSeconds;

		if (iHours < 10)
			strHours.Format(_T("0%d"), iHours);
		else
			strHours.Format(_T("%d"), iHours);

		if (iMinutes < 10)
			strMinutes.Format(_T("0%d"), iMinutes);
		else
			strMinutes.Format(_T("%d"), iMinutes);

		if (iSeconds < 10)
			strSeconds.Format(_T("0%d"), iSeconds);
		else
			strSeconds.Format(_T("%d"), iSeconds);
		CString str;
		str.Format(_T("%s:%s:%s"), strHours, strMinutes, strSeconds);
		m_CurrentTime.SetWindowText(str);

		UpdateData(FALSE);
	}
	else if (nIDEvent == TIMER_VIDEO_TEST)
	{
		CString str;
		if (i_img_video_test_count <= 10)
		{
			str.Format(_T("..\\Images\\Tag%d.jpg"), i_img_video_test_count);
			CT2A astr(str);
			img_video_test = cvLoadImage(astr.m_psz, CV_LOAD_IMAGE_COLOR);
			// show image on screen like a video frame
			// push opencv frame into CStatic
			::SetParent(m_HWND_opencv, GetDlgItem(IDC_STATIC_VIDEO)->m_hWnd);
			// show image on opencv frame
			cvShowImage("opencv_image_frame", img_video_test);

			i_img_video_test_count++;
		}
		else {
			i_img_video_test_count = 1;
		}
	}
	else if (nIDEvent == TIMER_CAPTURE_FIRST_IMG) // wait for awhile then capture the first image 
	{
		int iRet = captureImage_F();
		KillTimer(TIMER_CAPTURE_FIRST_IMG);
	}
	CDialogEx::OnTimer(nIDEvent);
}

int CmyipcamDlg::cs_preProcess()
{
	cvReleaseImage(&img_first_preset);
	img_first_preset = cvCreateImage(cvSize(img_first->width, img_first->height), 
		8,
		1);
	img_first_preset_S = cvCreateImage(cvSize(img_first->width, img_first->height),
		8,
		1);
	cvCvtColor(img_first, img_first_preset, CV_BGR2GRAY);
	cvSmooth(img_first_preset, img_first_preset, CV_GAUSSIAN, 5, 5);
	cvThreshold(img_first_preset, img_first_preset_S, 128, 255, CV_THRESH_OTSU);
#ifdef TEST_MODE
	cvShowImage("Nguong1", img_first_preset);
	cvShowImage("Nguong2", img_first_preset_S);
#endif
	return 0;
}


/*
int CmyipcamDlg::cs_resFind()
{
	CvPoint cpKN, cpKO;
	int index, i, j, k, h, Buoc, nCh;
	double kq;

	uchar *ptrKN = (uchar*)imgKN->imageData;
	uchar *ptrKO = (uchar*)imgKO->imageData;
	Buoc = imgKN->widthStep;
	nCh = imgKN->nChannels;
	// I. Xu ly anh imgKN //
	//delete c;
	if (conFind(imgKNS, &c) == 1)
	{
		// So sanh c va stContour
		if ((stContour != NULL) && (c != NULL))
		{
			kq = cvMatchContours(stContour, c, CV_CONTOURS_MATCH_I1);
			if (kq<0.01) // Neu 2 contour nay "giong nhau" -> Tim tam cua contour do
			{
				conCenterPoint(c, &cpKN);
				//conCenterPoint(stContour,&cpKN);
			}
			else return -1;
		}
		else return -1;

	}
	else return -1;
	//cvDrawContours(imgKN,c,CV_RGB(0,0,255),CV_RGB(0,0,255),0,1,8);
	//cvCircle(imgKN,cpKN,10,cvScalar(255,0,0),2);
#ifdef TEST_MODE
	cvShowImage("C1", imgKN);
#endif
	// II. Xu ly anh imgKO //
	//cvCopyImage(imgKO,imgKOS);
	//delete c;
	if (conFind(imgKOS, &c) == 1)
	{
		// So sanh c va stContour
		if ((stContour != NULL) && (c != NULL))
		{
			kq = cvMatchContours(stContour, c, CV_CONTOURS_MATCH_I1);
			if (kq<0.01) // Neu 2 contour nay "giong nhau" -> Tim tam cua contour do
			{
				conCenterPoint(c, &cpKO);
				//conCenterPoint(stContour,&cpKO);
			}
			else return -1;
		}
		else return -1;
	}
	else return -1;
	//cvDrawContours(imgKO,c,CV_RGB(0,0,255),CV_RGB(0,0,255),0,1,8);
	//cvCircle(imgKO,cpKO,10,cvScalar(255,0,0),2);
#ifdef TEST_MODE
	cvShowImage("C2", imgKO);
#endif
	// III. Tru anh:  imgTm = imgKN - imgKO  voi kich Thuoc 2*BanKinh voi tam o (yKO, xKO) 
	cvZero(imgTM);							//III.1 Dua anh imgTM ve 0 truoc khi tinh toan
	if ((abs(cpKO.x - cpKN.x) == 1) || (abs(cpKO.y - cpKN.y) == 1))
	{
		//int t=0; 
		cpKN.x = cpKO.x;
		cpKN.y = cpKO.y;
	}
	for (k = -BanKinh; k <= BanKinh; k++)				//III.2 Tru anh
	{
		for (h = -BanKinh; h <= BanKinh; h++)
		{
			i = cpKO.y + k;
			j = cpKO.x + h;
			if ((i >= 0) && (i<imgKO->height) && (j >= 0) && (j<imgKO->width))
			{
				index = (j)*nCh + (i)*Buoc;
				int gr = ptrKO[index];

				int i1 = cpKN.y + k;
				int j1 = cpKN.x + h;
				if ((i1 >= 0) && (i1<imgKN->height) && (j1 >= 0) && (j1<imgKN->width))
				{
					index = (j1)*nCh + (i1)*Buoc;
					int gr1 = ptrKN[index];

					if (abs(gr1 - gr)>35)  // Nhieu nam trong khoang 0-10.
					{
						ptrTM[index] = GRAY_HIGH_LEVEL;
					}
					else
					{
						ptrTM[index] = GRAY_LOW_LEVEL;
					}
				}
			}
		}
	}
	//cvSmooth( imgTM, imgTM, CV_MEDIAN,5,5);
#ifdef TEST_MODE
	cvShowImage("AnhTru", imgTM);
#endif
	TV10.x = cpKN.x + TV10_LechX;
	TV10.y = cpKN.y + TV10_LechY;

	if (conFindV(imgTM, &c, &c1, &c2, &c3, &c4, &c5) == 1)
	{
		if (getCheckValue(hDlg, IDC_AutoDetect) == 1)
		{
			if (SoPhatBanThuc<SoPhatBan)
			{
				return -1;
			}
		}
		// Tim vet DAM va tinh TRUNG BINH
		//double TongX, TongY;
		//TongX = 0; TongY = 0;
		int SPB = SoPhatBanThuc;

		if (SPB == 6)
		{
			conCenterPoint(c5, &TVDNN[5]);
			SPB = SPB - 1;
		}
		if (SPB == 5)
		{
			conCenterPoint(c4, &TVDNN[4]);
			SPB = SPB - 1;
		}
		if (SPB == 4)
		{
			conCenterPoint(c3, &TVDNN[3]);
			SPB = SPB - 1;
		}
		if (SPB == 3)
		{
			conCenterPoint(c2, &TVDNN[2]);
			SPB = SPB - 1;
		}
		if (SPB == 2)
		{
			conCenterPoint(c1, &TVDNN[1]);
			SPB = SPB - 1;
			//float *radius;
			//CvPoint2D32f *TVDN2D;
			//cvMinEnclosingCircle(c1,TVDN2D,radius);
		}
		if (SPB == 1)
		{
			conCenterPoint(c, &TVDNN[0]);
			SPB = SPB - 1;
		}
		return 1;
	}
	else
	{
		return -1;
	}
}
*/