#ifndef __HOEM_PLAYDLL_API_H
#define __HOEM_PLAYDLL_API_H

#include "HIPCAM_DEFINE.H"

#ifndef _WIN32_WCE
	#ifdef HOEM_PLAYDLL_EXPORTS
		#define HOEM_PLAYDLL_API extern "C" __declspec(dllexport)
	#else
		#define HOEM_PLAYDLL_API extern "C" __declspec(dllimport)
	#endif
#else
	#define PLAYLIB_API extern "C"
#endif


/**
 *  Comment : Get Max Channel Define
 *  Return Value :
 *  Max Channel Define
 */
HOEM_PLAYDLL_API int HOEM_Play_GetMaxChannel();

/**
 *  Comment : Initiate the DLL
 */
HOEM_PLAYDLL_API void HOEM_Play_Init();

/**
 *  Comment : Deinitiate the DLL
 */
HOEM_PLAYDLL_API void HOEM_Play_Deinit();

/**
 *  Comment : Set If Use Overlay & ColorKey
 *		Initial of the DLL is use Overlay and ColorKey is RGB(0x14,0x00,0x14)
 *	Parameter :
 *	bUseOverlay		Use Overlay or Not
 *	ColorRef		ColorKey
 */
HOEM_PLAYDLL_API void HOEM_Play_SetUseOverlay(bool bUseOverlay, COLORREF ColorRef);

/**
 *  Comment : Initiate the Play Environment
 */
HOEM_PLAYDLL_API void HOEM_Play_CreatePlayer();

/**
 *  Comment : Deinitiate the Play Environment
 */
HOEM_PLAYDLL_API void HOEM_Play_DestoryPlayer();

/**
 *  Comment : Build PlayBack Object and Set Play Window
 *  Return Value :
 *	iCh					Set PlayBack Object Success
 *  PLAY_CHANNEL_ER		iCh is Error
 *	Parameter :
 *	hwnd		Handle to a Window
 *  iCh			Play Channel
 *	iWidth		Window Width
 *	iHeight		Window Height
 */
HOEM_PLAYDLL_API int HOEM_Play_SetPlayWindow(HWND hwnd, int iCh, int iWidth, int iHeight);

/**
 *  Comment : Release PlayBack Object
 *  Return Value :
 *	iCh					Set PlayBack Object Success
 *  PLAY_CHANNEL_ER		iCh is Error
 *	Parameter :
 *  iCh			Play Channel
 */
HOEM_PLAYDLL_API int HOEM_Play_ReleasePlayWindow(int iCh);

/**
 *  Comment : Push Frame to Play
 *  Return Value :
 *  PLAY_PUSH_FRAME_SUCCESS		Push Frame Success
 *  PLAY_PUSH_FRAME_FAILED		Push Frame Failed
 *	PLAY_NOT_PLAY_AUDIO			This Channel Not Play Audio Frame
 *  PLAY_BUFFER_IS_FULL			Buffer is FULL
 *	PLAY_PUSH_FRAME_NOT_I		Play Need I Frame
 *  PLAY_CHANNEL_ER				iCh is Error or Not Set Play Obj Yet
 *	Parameter :
 *	hwnd		Handle to a Window
 *  iCh			Play Channel
 *	pFrame		Pointer of HFrame
 */
HOEM_PLAYDLL_API int HOEM_Play_PushPlayFrame(HWND hwnd, int iCh, HFrame *pFrame);

/**
 *  Comment : Play Channel
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API void HOEM_Play_Play(int iCh);

/**
 *  Comment : Stop Channel
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API void HOEM_Play_Stop(int iCh);

/**
 *  Comment : Pause Channel
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API void HOEM_Play_Pause(int iCh);

/**
 *  Comment : Step Channel
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API void HOEM_Play_Step(int iCh);

/**
 *  Comment : Get MPEG4 Frame
 *  Return Value :
 *  PLAY_GET_MPEG4_SUCCESS		Get MPEG4 Frame Success
 *  PLAY_CHANNEL_ER				iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	pFrame		Pointer of HFrame
 */
HOEM_PLAYDLL_API int HOEM_Play_GetMPEG4Frame(int iCh, HFrame *pFrame);

/**
 *  Comment : Set Window Size
 *  Return Value :
 *  PLAY_SET_WINDOW_SIZE_SUCCESS	Set Window Size Success
 *  PLAY_CHANNEL_ER					iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	iWidth		Window Width
 *	iHeight		Window Height
 */
HOEM_PLAYDLL_API int HOEM_Play_SetWindowSize(int iCh, int iWidth, int iHeight);

/**
 *  Comment : Get Frame Buffer Max Size
 *  Return Value :
 *  int					Buffer Size
 *  PLAY_CHANNEL_ER		iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API int HOEM_Play_GetBufSize(int iCh);

/**
 *  Comment : Set Frame Buffer Max Size
 *  Return Value :
 *  PLAY_SET_BUFFER_SIZE_SUCCESS	Set Buffer Size Success
 *  PLAY_CHANNEL_ER					iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	iSize		Buffer Size
 */
HOEM_PLAYDLL_API int HOEM_Play_SetBufSize(int iCh, int iSize);

/**
 *  Comment : Get Channel Play Audio
 *  Return Value :
 *  TRUE				The Channel Play Audio
 *  FALSE				The Channel Do Not Play Audio
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API bool HOEM_Play_GetPlayAudio(int iCh);

/**
 *  Comment : Set Channel Play Audio
 *  Return Value :
 *  PLAY_SET_PLAY_AUDIO_SUCCESS		Set Play Audio Success
 *  PLAY_CHANNEL_ER					iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	bPlay		Play Audio
 */
HOEM_PLAYDLL_API int HOEM_Play_SetPlayAudio(int iCh, bool bPlay);

/**
 *  Comment : Save SnapShot to BMP File
 *  Return Value :
 *  PLAY_SNAPSHOT_SUCCESS		SnapShot Success
 *  PLAY_CHANNEL_ER				iCh is Error
 *	Parameter :
 *	iCh				Play Channel
 *	sName			File Name
 *	iNameLength		sName's Length
 */
HOEM_PLAYDLL_API int HOEM_Play_SnapShot_BMP(int iCh, char * sName, int iNameLength);

/**
 *  Comment : Save SnapShot to JPG File
 *  Return Value :
 *  PLAY_SNAPSHOT_SUCCESS		SnapShot Success
 *  PLAY_CHANNEL_ER				iCh is Error
 *	Parameter :
 *	iCh				Play Channel
 *	sName			File Name
 *	iNameLength		sName's Length
 */
HOEM_PLAYDLL_API int HOEM_Play_SnapShot_JPG(int iCh, char * sName, int iNameLength);

/**
 *  Comment : Get Frame Play Time
 *  Return Value :
 *  PLAY_GETPLAYTIME_SUCCESS	Get Play Time Success
 *  PLAY_CHANNEL_ER				iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	stPlayTime	Reference of SYSTEMTIME
 */
HOEM_PLAYDLL_API int HOEM_Play_GetPlayTime(int iCh, SYSTEMTIME &stPlayTime);

/**
 *  Comment : Get MPEG4 Decode Frame
 *  Return Value :
 *  PLAY_GET_DECODE_SUCCESS		Get Decode Frame Success
 *	PLAY_GET_DECODE_EMPTY		Decode Frame List is Empty
 *	PLAY_GET_DECODE_FAIL		Decode Fail
 *  PLAY_CHANNEL_ER				iCh is Error
 *	PLAY_GET_DECODE_TYPE_ER		Decode_Type is Error
 *	Parameter :
 *	DT			Decode_Type
 *	iCh			Play Channel
 *	FrameList	List Contain HFrame's Pointer Begin From a GOP's I Frame to the Frame Want to Decode
 *	iListSize	Number of Frame's Pointer in FrameList
 *	pBuf		Pointer of char's Pointer(User should delete this buffer by HOEM_Play_DeleteDecodeFrameData after use)
 *	lWidth		Frame Width
 *	lHeight		Frame Height
 *	stTime		Frame System Time
 */
HOEM_PLAYDLL_API int HOEM_Play_GetDecodeFrame(HDecode_Type DT, 
											  int iCh,
											  HFrame **FrameList,
											  int iListSize,
											  char **pBuf, 
											  unsigned long &lWidth, 
											  unsigned long &lHeight, 
											  SYSTEMTIME &stTime);

/**
 *  Comment : Get H264 Decode Frame
 *  Return Value :
 *  PLAY_GET_DECODE_SUCCESS		Get Decode Frame Success
 *	PLAY_GET_DECODE_EMPTY		Decode Frame List is Empty
 *	PLAY_GET_DECODE_FAIL		Decode Fail
 *  PLAY_CHANNEL_ER				iCh is Error
 *	PLAY_GET_DECODE_TYPE_ER		Decode_Type is Error
 *	Parameter :
 *	DT			Decode_Type
 *	iCh			Play Channel
 *	FrameList	List Contain HFrame's Pointer Begin From a GOP's I Frame to the Frame Want to Decode
 *	iListSize	Number of Frame's Pointer in FrameList
 *	pBuf		Pointer of char's Pointer(User should delete this buffer by HOEM_Play_DeleteDecodeFrameData after use)
 *	lWidth		Frame Width
 *	lHeight		Frame Height
 *	stTime		Frame System Time
 */
HOEM_PLAYDLL_API int HOEM_Play_GetDecodeFrame_264(HDecode_Type DT, 
											  int iCh,
											  HFrame **FrameList,
											  int iListSize,
											  char **pBuf, 
											  unsigned long &lWidth, 
											  unsigned long &lHeight, 
											  SYSTEMTIME &stTime);

/**
 *  Comment : Use this function to delete decode Frame Data receive from HOEM_Play_GetDecodeFrame or HOEM_Play_GetDecodeFrame_264
 *  Return Value :
 *  true		delete Success
 *  false		delete Failed
 *	Parameter :
 *	pBuf		Pointer of char's Pointer
 */
HOEM_PLAYDLL_API bool HOEM_Play_DeleteDecodeFrameData(char **pBuf);

/**
 *  Comment : Save Frame To AVI
 *  Return Value :
 *	PLAY_SAVEAVI_SUCCESS			Save AVI Success
 *  PLAY_AVI_BEGIN_ER				Start Frame is Not System Frame
 *  PLAY_CHANNEL_ER					iCh is Error
 *	Parameter :
 *	iCh				Play Channel
 *	sPath			Storage path
 *	iPathLength		sPath's Length
 *	FrameList		List Contain HFrame's Pointer(First Frame Must be System Frame)
 *	iListSize		Number of Frame's Pointer in FrameList
 */
HOEM_PLAYDLL_API int HOEM_Play_SaveToAVI(int iCh, char * sPath, int iPathLength, HFrame **FrameList, int iListSize);

/**
 *  Comment : Get Play I Only
 *  Return Value :
 *  TRUE		This Channel Play I Only
 *	FALSE		This Channel Not Play I Only
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API bool HOEM_Play_GetIOnly(int iCh);

/**
 *  Comment : Set Play I Only
 *  Return Value :
 *  PLAY_SET_PLAY_IONLY_SUCCESS		Set Play Audio Success
 *  PLAY_CHANNEL_ER					iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	bIOnly		Play I Only
 */
HOEM_PLAYDLL_API int HOEM_Play_SetIOnly(int iCh, bool bIOnly);

/**
 *  Comment : Get SnapShot BMP Memory. Return value is BMP's memory length when success.
 *  Return Value :
 *  PLAY_CHANNEL_ER					iCh is Error
 *	PLAY_GET_SNAPSHOT_FAILED		Can't get Bitmap
 *	PLAY_GET_SNAPSHOT_SIZE_SMALL	pBuf's size is too small
 *	Parameter :
 *	iCh			Play Channel
 *	pBuf		Memory Buffer Pointer
 *	uiBufSize	(Set uiBufSize as pBuf's length before use this 
				function)
 */
HOEM_PLAYDLL_API int HOEM_Play_SnapShotToMemory_BMP(int iCh, char *pBuf, unsigned int &uiBufSize);

/**
 *  Comment : Use HVideo_Info to initial audio convert module.
 *  Return Value :
 *  PLAY_CHANNEL_ER					iCh is Error
 *	PLAY_CONVERT_AUDIO_SUCCESS		Initial Success
 *	PLAY_CONVERT_AUDIO_FAILED		Initial failed
 *	Parameter :
 *	iCh			Play Channel
 *	VInfo		HVideo_Info of this channel
 */
HOEM_PLAYDLL_API int HOEM_Play_AudioConvert_Init(int iCh, HVideo_Info VInfo);

/**
 *  Comment : Convert audio type to WAVE_FORMAT_PCM.
 *  Return Value :
 *	> 0								Convert Data Length
 *  PLAY_CHANNEL_ER					iCh is Error
 *	PLAY_CONVERT_AUDIO_FAILED		Convert failed
 *	Parameter :
 *	iCh				Play Channel
 *	pAudioFrame		Audio Frame Pointer(this frame should change by HOEM_Cam_GetMPEG4Frame after receive from FrameCallback)
 *	pBuf			Memory Buffer Pointer(Buffer size must greater than  [19200 * 4] Bytes)
 */
HOEM_PLAYDLL_API int HOEM_Play_ConvertAudioData(int iCh, HFrame *pAudioFrame, BYTE *pBuf);

/**
 *  Comment : Finish audio convert module.
 *  Return Value :
 *  PLAY_CHANNEL_ER					iCh is Error
 *	PLAY_CONVERT_AUDIO_SUCCESS		Deinitial Success
 *	Parameter :
 *	iCh			Play Channel
 *	VInfo		HVideo_Info of this channel
 */
HOEM_PLAYDLL_API int HOEM_Play_AudioConvert_Deinit(int iCh);

/**
 *  Comment : Get channel video flip
 *  Return Value :
 *  TRUE		Video Flip
 *	FALSE		Video Not Flip
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API bool HOEM_Play_GetVideoFlip(int iCh);

/**
 *  Comment : Set Channel video flip
 *  Return Value :
 *  PLAY_SET_VIDEO_FLIP_SUCCESS		Set Video Flip Success
 *  PLAY_CHANNEL_ER					iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	bFlip		Video Flip
 */
HOEM_PLAYDLL_API int HOEM_Play_SetVideoFlip(int iCh, bool bFlip);

/**
 *  Comment : Get channel video mirror
 *  Return Value :
 *  TRUE		Video Mirror
 *	FALSE		Video Not Mirror
 *	Parameter :
 *	iCh			Play Channel
 */
HOEM_PLAYDLL_API bool HOEM_Play_GetVideoMirror(int iCh);

/**
 *  Comment : Set Channel video mirror
 *  Return Value :
 *  PLAY_SET_VIDEO_MIRROR_SUCCESS		Set Video Mirror Success
 *  PLAY_CHANNEL_ER						iCh is Error
 *	Parameter :
 *	iCh			Play Channel
 *	bMirror		Video Mirror
 */
HOEM_PLAYDLL_API int HOEM_Play_SetVideoMirror(int iCh, bool bMirror);

/**
 *  Comment : Open AVI File
 *  Return Value :
 *	PLAY_OPEN_AVI_SUCCESS
 *	PLAY_OPEN_AVI_FAILED
 *	PLAY_OPEN_AVI_NEED_SYSTEM_FRAME
 *	Parameter :
 *	pFileName		AVI File Name
 *	pSystemFrame	Need System Frame to Setup AVI File
 */
HOEM_PLAYDLL_API int HOEM_Play_AVI_Open(char *pFileName, HFrame *pSystemFrame);

/**
 *  Comment : Save AVI File
 *  Return Value :
 *	PLAY_SAVE_AVI_SUCCESS
 *	PLAY_SAVE_AVI_FAILED
 *	Parameter :
 *	pFrame		HFrame to Save AVI
 */
HOEM_PLAYDLL_API int HOEM_Play_AVI_Save(HFrame *pFrame);

/**
 *  Comment : Close AVI File
 *  Return Value :
 *	PLAY_CLOSE_AVI_SUCCESS
 *	PLAY_CLOSE_AVI_FAILED
 */
HOEM_PLAYDLL_API int HOEM_Play_AVI_Close();

/**
 *  Comment : Show OSD
 *  Return Value :
 *  PLAY_SET_OSD_SUCCESS		Set OSD Success
 *  PLAY_CHANNEL_ER				iCh is Error
 *  Parameter :
 *	iCh			PlayChannel
 *	OSD			OSD String
 *	PositionX	Coordinate X
 *	PositionY	Coordinate Y
 *	CharHeight	Character Height
 *	Bold		Character Bold
 *	Italic		Character Italic
 *	ColorR		Red Color(0~255)
 *	ColorG		Green Color(0~255)
 *	ColorB		Blue Color(0~255)
 */
HOEM_PLAYDLL_API int HOEM_Play_SetOSD(int iCh, LPCTSTR OSD, int PositionX, int PositionY,
									  int CharHeight, bool Bold, bool Italic, int ColorR, int ColorG, int ColorB);

/**
 *  Comment : Close OSD
 *  Return Value :
 *  PLAY_SET_OSD_SUCCESS		Set OSD Success
 *  PLAY_CHANNEL_ER				iCh is Error
 *  Parameter :
 *	iCh			PlayChannel
 */
HOEM_PLAYDLL_API int HOEM_Play_CloseOSD(int iCh);


/**
 *  Comment : Set Full Screen Play Window(this API will hide other windows)
 *  Return Value :
 *	iCh					Set Full Screen Success
 *  PLAY_CHANNEL_ER		iCh is Error
 *	Parameter :
 *	hwnd		Handle to a Window
 *  iCh			Play Channel
 *	iWidth		Window Width
 *	iHeight		Window Height
 *	bFull		true:enable full window		false:disable full window
 */
HOEM_PLAYDLL_API int HOEM_Play_SetFullScreenWindow(HWND hwnd, int iCh, int iWidth, int iHeight, bool bFull);

/**
 *  Comment : Set Channel Encryption Key
 *  Return Value : 
 *	iCh					Set Encryption Key Success
 *  PLAY_CHANNEL_ER		iCh is Error                        
 *	Parameter :
 *  iCh				Play Channel
 *	bEnableEncrypt	Enable | Disable Encryption
 *	pEncrypt		Encryption Key
 */
HOEM_PLAYDLL_API int HOEM_Play_Set_EncryptKey(int iCh, bool bEnable, char *pEncrypt="");

#endif
