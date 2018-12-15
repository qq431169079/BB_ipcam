#ifndef __HOEM_IPCAMDLL_API_H
#define __HOEM_IPCAMDLL_API_H

#include <mmsystem.h>
#include "HIPCAM_DEFINE.H"
#include <set>


#ifndef _WIN32_WCE
	#ifdef HOEM_IPCAMDLL_EXPORTS
		#define HOEM_IPCAMDLL_API extern "C" __declspec(dllexport)
	#else
		#define HOEM_IPCAMDLL_API extern "C" __declspec(dllimport)
	#endif
#else
	#define IPCAMLIB_API extern "C"
#endif


/**
 *  Comment : Get Max Channel Define
 *  Return Value :
 *  Max Channel Define
 */
HOEM_IPCAMDLL_API int HOEM_Cam_GetMaxChannel();

/**
 *  Comment : Initiate the environment
 *  Return Value :
 *  IPCAM_SOCKET_INIT_OK            successful
 *  IPCAM_SOCKET_WSASTARTUP_ER      error when executing WSASTARTUP()
 *  IPCAM_SOCKET_OPEN_CONFIG_ER     IPCamConfig.txt is bad or not existing
 *  IPCAM_SOCKET_CONFIG_PARAM_ER    IPCamConfig.txt parameters are invalid
 */
HOEM_IPCAMDLL_API int HOEM_Cam_Init();

/**
 *  Comment : Deinitiate the environment
 *  Return Value :
 *  IPCAM_OK            successful
 */
HOEM_IPCAMDLL_API int HOEM_Cam_Deinit();

/**
 *  Comment : Create IPCam connection
 *  Return Value :
 *  IPCAM_OK                    successful
 *  IPCAM_IS_NULL               phCam is NULL
 *  IPCAM_PORT_IS_ER            iPort value is invalid ( valid : 0 ~ 65535 )
 *  IPCAM_IS_OVER_MAX_CHANNEL   IPCam is Over Max Channel
 *
 *  Parameter :
 *  hCam     HANDLE's pointer of this IPCam connection 
 *  cInfo    connect information of this connection
 *  peCallback    event callback function
 *  iContext	  specifies a single parameter value passed to the callback function
 */
HOEM_IPCAMDLL_API int HOEM_Cam_Create(HANDLE *hCam, Connect_Info cInfo, HEVENT_CALLBACK peCallback, int iContext);

/**
 *  Comment : Delete IPCam Connection that create by HOEM_Cam_Connect() before
 *  Return Value :
 *  IPCAM_OK            successful
 *  IPCAM_IS_NULL       hCam is NULL
 *
 *  Parameter : 
 *  hCam	HANDLE's pointer of this connection
 */
HOEM_IPCAMDLL_API int HOEM_Cam_Delete(HANDLE *hCam);

/**
 *  Comment : Set Auto Reconnect Enabled|Disabled
 *  Return Value :
 *  IPCAM_OK            successful
 *  IPCAM_IS_NULL       hCam is NULL
 *
 *  Parameter : 
 *  hCam		HANDLE pointer of this connection
 *	bEnabled	true|false
 */
HOEM_IPCAMDLL_API int HOEM_Cam_SetAutoReconnect(HANDLE hCam, bool bEnabled);

/**
 *  Comment : Connect to IPCam
 *  Return Value :
 *  IPCAM_OK            successful
 *  IPCAM_IS_NULL       hCam is NULL
 *  IPCAM_TYPE_IS_ER    eFrameType is invalid ( valid : HIPCam_VIDEO or HIPCam_AUDIO )
 *
 *  Parameter :
 *  hCam		  HANDLE of this connection
 *  pfCallback    frame callback function to receive frame
 *  iContext	  specifies a single parameter value passed to the callback function
 *  eFrameType	  frame type want to receive
 */
HOEM_IPCAMDLL_API int HOEM_Cam_Connect(HANDLE hCam, HFRAME_CALLBACK pfCallback, int iContext, HFRAMETYPE_DLL eFrameType);

/**
 *  Comment : Delete all of IPCam Connections
 *  Return Value :
 *  IPCAM_OK            successful
 */
HOEM_IPCAMDLL_API int HOEM_Cam_CleanAll();

/**
 *  Comment : Set RTSP Parameter
 *  Return Value :
 *  IPCAM_OK            successful
 *	IPCAM_IS_NULL		hCam is NULL
 *	Parameter :
 *	hCam		HANDLE's pointer of this connection
 *	rType		HTCP or HUDP (Default HTCP)
 *	pcUrlPath	Stream Access Name
 *	iUdpPort	UDP Port (range : 1 ~ 65535)
 */
HOEM_IPCAMDLL_API int HOEM_Cam_SetRtspParams(HANDLE hCam, HRTSP_TYPE rType = HTCP, char *pcUrlPath = "", int iUdpPort = 0);

/**
 *  Comment : Get IPCamera Type & Channels
 *  Return Value :
 *  IPCAM_OK            successful
 *	IPCAM_IS_NULL		hCam is NULL
 *	Parameter :
 *	hCam		HANDLE's pointer of this connection
 *	iType		Camera Type
 *	iVideoChannel	Camera Total Video Channels
 *	iAudioChannel	Camera Total Audio Channels
 */
HOEM_IPCAMDLL_API int HOEM_Cam_GetCamera_TypeChannel(HANDLE hCam, int &Type, int &VideoChannel, int &AudioChannel);

/**
 *  Comment : Set IPCamera Stream Channel
 *  Return Value :
 *  IPCAM_OK            successful
 *	IPCAM_IS_NULL		hCam is NULL
 *	Parameter :
 *	hCam		HANDLE's pointer of this connection
 *	iVideoStream	Video Stream Channel : 0 ~ (Total Video Channels-1)	(Default 0)
 *	iAudioStream	Audio Stream Channel : 0 ~ (Total Audio Channels-1)	(Default 0)
 */
HOEM_IPCAMDLL_API int HOEM_Cam_SetIPCamStreamNum(HANDLE hCam, int iVideoStream = 0, int iAudioStream = 0);

/**
 *  Comment : Start to receive Video/Audio data
 *  Return Value :
 *  IPCAM_OK            successful
 *  IPCAM_IS_NULL       hCam is NULL
 *  IPCAM_TYPE_IS_ER    eFrameType is invalid ( valid : HIPCam_VIDEO or HIPCam_AUDIO )
 *
 *  Parameter :
 *  hCam		  HANDLE of this connection
 *  eFrameType	  frame type want to receive
 */
HOEM_IPCAMDLL_API int HOEM_Cam_StartReceive(HANDLE hCam, HFRAMETYPE_DLL eFrameType);

/**
 *  Comment : Pause a thread
 *  Return Value :
 *  IPCAM_OK            successful
 *  IPCAM_IS_NULL       hCam is NULL        
 *  IPCAM_TYPE_IS_ER    eFrameType is invalid ( valid : HIPCam_VIDEO or HIPCam_AUDIO )
 *
 *  Parameter :
 *  hCam          HANDLE of this connection
 *  eFrameType    frame type want to pause receive
 */
HOEM_IPCAMDLL_API int HOEM_Cam_PauseReceive(HANDLE hCam, HFRAMETYPE_DLL eFrameType);

/**
 *  Comment : Continue a thread
 *  Return Value :
 *  IPCAM_OK            successful
 *  IPCAM_IS_NULL       hCam is NULL     
 *  IPCAM_TYPE_IS_ER    eFrameType is invalid ( valid : HIPCam_VIDEO or HIPCam_AUDIO )
 *
 *  Parameter : 
 *  hCam	      HANDLE of this connection
 *  eFrameType    frame type want to continue receive
 */
HOEM_IPCAMDLL_API int HOEM_Cam_ContinueReceive(HANDLE hCam, HFRAMETYPE_DLL eFrameType);

/**
 *  Comment : Obtain IPCam's status
 *  Return Value :
 *  TREU    IPCam is Live
 *  FALSE   IPCam is Failed
 *
 *  Parameter : 
 *  hCam    HANDLE of this connection
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_IsCamLive(HANDLE hCam);

/**
 *  Comment : Obtain IPCam's status
 *  Return Value :
 *  IPCAM_OK                    IPCam is living
 *	IPCAM_IS_NULL				Can't find hCam
 *  IPCAM_IS_FULL               the connections of IPCam is full
 *  IPCAM_USER_OR_PASSWD_IS_ER  unauthorized error
 *  IPCAM_CANT_DETECT_TYPE_ER   can't detect IPCam's type automatically
 *  IPCAM_IS_OVER               IPCam was deleted
 *  IPCAM_IS_UNCONNECTED        connect failed or disconnect
 *
 *  Parameter : 
 *  hCam    HANDLE of this connection
 */
HOEM_IPCAMDLL_API int HOEM_Cam_GetCamStatus(HANDLE hCam);

/**
 *  Comment : Obtain If IPCam Support PTZ
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *
 *  Parameter : 
 *  hCam    HANDLE of this connection
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_IsSupportPTZ(HANDLE hCam);

/**
 *  Comment : Obtain IPCam's Video Config
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *
 *  Parameter : 
 *  hCam			HANDLE of this connection
 *  vConfig			HVideo_Config
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_GetVideo(HANDLE hCam, HVideo_Config *vConfig);

/**
 *  Comment : Set IPCam's Video Config
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *
 *  Parameter : 
 *  hCam			HANDLE of this connection
 *  vConfig			HVideo_Config
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_SetVideo(HANDLE hCam, HVideo_Config vConfig);

/**
 *  Comment : Obtain IPCam's Motion Information
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *
 *  Parameter : 
 *  hCam     HANDLE of this connection
 *  mInfo    pointer to struct HGet_Motion_Info
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_GetMotion(HANDLE hCam, HGet_Motion_Info *mInfo);

/**
 *  Comment : Set IPCam's Motion Information
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *
 *  Parameter : 
 *  hCam     HANDLE of this connection
 *  mInfo    new struct HSet_Motion_Info
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_SetMotion(HANDLE hCam, HSet_Motion_Info mInfo);

/**
 *  Comment : Obtain IPCam's PTZ
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *
 *  Parameter : 
 *  hCam     HANDLE of this connection
 *  mInfo    pointer to struct HPTZ_Info
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_GetPTZ(HANDLE hCam, HPTZ_Info *m_Info);

/**
 *  Comment : Set IPCam's PTZ
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *
 *  Parameter :
 *  hCam		HANDLE of this connection
 *  mInfo		new HPTZ_Info
 *  hType		new HPTZ_MODEL
 *  iID			new deviceid
 *  iBaud		new baudrate
 *  iSpeed		new speed
 *  iPoint		select point
 *  pStr		LPCSTR contain point and name ( example : "1:Door" )
 *	iStrLength	pStr's Length 
 */                                             
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Param(HANDLE hCam, HPTZ_Info m_Info);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Up(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Down(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Left(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Right(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_UpLeft(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_UpRight(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_DownLeft(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_DownRight(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Home(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_ZoomIn(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_ZoomOut(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_FocusIn(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_FocusOut(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_IrisOpen(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_IrisClose(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_AutoScan(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_StopScan(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Type(HANDLE hCam, HPTZ_MODEL hType);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Deviceid(HANDLE hCam, int iID);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Baudrate(HANDLE hCam, int iBaud);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Speed(HANDLE hCam, int iSpeed);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Point(HANDLE hCam, int iPoint);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Preset(HANDLE hCam, char * pStr, int iStrLength);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Remove(HANDLE hCam, char * pStr, int iStrLength);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Move(HANDLE hCam, PTZOSCInfo Info);

/**
 *  Comment : Execute CGI
 *  Return Value :
 *  TRUE    Success
 *  FALSE   Failed
 *	Parameter :
 *	hCam		HANDLE of this connection
 *	pCmd		CGI Command Pointer
 *	pRecvStr	CGI Result Buffer
 *	pBufSize	Result Length
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_Execute_CGI(HANDLE hCam, char* pCmd, char* pRecvStr, unsigned long &pBufSize);

/**
 *  Comment : Get H264 Frame
 *  Return Value :
 *  TRUE		Get H264 Frame Success
 *  FALSE		iCh is Error
 *	Parameter :
 *	pFrame		Pointer of HFrame
 */

HOEM_IPCAMDLL_API bool HOEM_Cam_GetH264Frame(HFrame *pFrame);

/**
 *  Comment : Get MPEG4 Frame
 *  Return Value :
 *  TRUE		Get MPEG4 Frame Success
 *  FALSE		iCh is Error
 *	Parameter :
 *	pFrame		Pointer of HFrame
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_GetMPEG4Frame(HFrame *pFrame);

/**
 *  Comment : Ask Recently System Frame
 *  Return Value :
 *  HFrmae's Pointer(User should delete this frame buffer by HOEM_Cam_DeleteFrame after use)
 *	NULL	if not get System Frame
 *	Parameter :
 *	hCam		HANDLE of this connection
 */

HOEM_IPCAMDLL_API HFrame* HOEM_Cam_AskSystemFrame(HANDLE hCam);

/**
 *  Comment : Delete frame buffer receive from HOEM_Cam_AskSystemFrame
 *  Return Value :
 *	True		delete success
 *  False		delete failed
 *	Parameter :
 *	pFrame		HFrame's pointer
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_DeleteFrame(HFrame *pFrame);

/**
 *  Comment : Get Specific Resolution's Width & Height
 *  Return Value :
 *	True		Success
 *  False		Failed
 *	Parameter :
 *	iMode		Resolution Mode
 *	iWidth		Resolution Width
 *	iHeight		Resolution Height
 */
HOEM_IPCAMDLL_API bool HOEM_Cam_GetResolutionSet(HANDLE hCam, int iMode, int &iWidth, int &iHeight);

/**
 *  Comment : Set two way Audio ON/OFF
 *  Return Value :
 *	IPCAM_IS_NULL
 *	IPCAM_2WAYAUDIO_OK						
 *	IPCAM_2WAYAUDIO_LINE_BUSY               
 *  IPCAM_2WAYAUDIO_LINE_CONNECT_ER         
 *  IPCAM_2WAYAUDIO_LINE_REQUEST_ER         
 *  IPCAM_2WAYAUDIO_SEND_HEADER_ER          
 *  IPCAM_2WAYAUDIO_SEND_DATA_ER            
 *  IPCAM_2WAYAUDIO_SOCKET_ER               
 *	Parameter :
 *	hCam		HANDLE of this connection
 *	bEnable		TRUE  : ON
 *				FALSE : OFF
 */
HOEM_IPCAMDLL_API int HOEM_Cam_Set2WayAudio(HANDLE hCam, bool bEnable);

/**
 *  Comment : Initial Send Audio Wave In
 *  Return Value :   
 *	IPCAM_IS_NULL			
 *	IPCAM_2WAYAUDIO_OK
 *	IPCAM_2WAYAUDIO_LINE_BUSY               
 *  IPCAM_2WAYAUDIO_LINE_CONNECT_ER         
 *  IPCAM_2WAYAUDIO_LINE_REQUEST_ER         
 *  IPCAM_2WAYAUDIO_SEND_HEADER_ER          
 *  IPCAM_2WAYAUDIO_SEND_DATA_ER            
 *  IPCAM_2WAYAUDIO_SOCKET_ER              
 *	Parameter :
 *	hCam		HANDLE of this connection
 *	pwfSrc		WAVEFORMATEX's pointer
 */
HOEM_IPCAMDLL_API int HOEM_Cam_AudioIn_Init(HANDLE hCam, WAVEFORMATEX *pwfSrc);

/**
 *  Comment : Send Audio Wave In
 *  Return Value :            
 *	IPCAM_IS_NULL         	
 *	IPCAM_2WAYAUDIO_OK
 *  IPCAM_2WAYAUDIO_SEND_HEADER_ER          
 *  IPCAM_2WAYAUDIO_SEND_DATA_ER               
 *	Parameter :
 *	hCam		HANDLE of this connection
 *	pAudioData	WAVEHDR's lpData
 *	iDataLen	length of pAudioData
 */
HOEM_IPCAMDLL_API int HOEM_Cam_SendAudioIn(HANDLE hCam, char *pAudioData, int iLenData);

/**
 *  Comment : Deinitial Send Audio Wave In
 *  Return Value :    
 *	IPCAM_IS_NULL         	
 *	IPCAM_2WAYAUDIO_OK                             
 *	Parameter :
 *	hCam		HANDLE of this connection
 */
HOEM_IPCAMDLL_API int HOEM_Cam_AudioIn_Deinit(HANDLE hCam);

HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_UpStart(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_DownStart(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_LeftStart(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_RightStart(HANDLE hCam);
HOEM_IPCAMDLL_API bool HOEM_Cam_SetPTZ_Stop(HANDLE hCam);


#endif