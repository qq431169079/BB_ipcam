
//T1800.h
//T1800 copyright 2006.04

#ifndef	_T1800_H
#define _T1800_H

#define TMAPI	extern"C"

//Error code
#define T18_ERR_SUCCESS								0//succeed
#define T18_ERR_WAIT_TIMEOUT						1//sdk time out
#define T18_ERR_DSP_ERROR							2//dsp error
#define T18_ERR_INVALID_HANDLE						3//invaild channel handle
#define T18_ERR_INVALID_ARGUMENT					4//invaild parameter
#define T18_ERR_DDRAW_CREATE_FAILED					5//fail to create ddraw surface
#define T18_ERR_DSP_CANNOT_BE_FOUND 				6//dsp can't be found
#define T18_ERR_DSP_IS_RUNNING						7//dsp is open
#define T18_ERR_CANNOT_FIND_IMGFILE					8//can't found img file
#define T18_ERR_NOT_SUPPORT							9//sdk no support
#define T18_ERR_RECEIVE_MSG							10//receive msg error
#define T18_ERR_GET_CHANNELS						11//get total channels error for current dsp
#define T18_ERR_GENERIC                             -1//Generic failure


//Osd
#define MAX_OSDFORMAT_LEN	44
#define T18_OSD_BASE		0x01
#define	T18_OSD_YEAR4		T18_OSD_BASE+0x00
#define T18_OSD_YEAR2		T18_OSD_BASE+0x02
#define T18_OSD_MONTH2		T18_OSD_BASE+0x04
#define T18_OSD_DAY			T18_OSD_BASE+0x06
#define	T18_OSD_HOUR24		T18_OSD_BASE+0x08
#define	T18_OSD_MINUTE		T18_OSD_BASE+0x0a
#define T18_OSD_SECOND		T18_OSD_BASE+0x0c
#define	T18_OSD_WEEK		T18_OSD_BASE+0x0e
#define T18_OSD_WEEK3		T18_OSD_BASE+0x0f
#define T18_OSD_MONTH3		T18_OSD_BASE+0x12
#define	T18_OSD_CWEEK1		T18_OSD_BASE+0x17
#define	T18_OSD_HOUR12		T18_OSD_BASE+0x18

//max support device channel
#define MAX_DEVICES_SUPPORT 64		//max channel

//max Motion Detect alarm rect
#define	MAX_NUM_ALARM_RECT  99

//stream type
#define STREAM_TYPE_NONE    0
#define STREAM_TYPE_VIDEO	1
#define STREAM_TYPE_AUDIO	2
#define STREAM_TYPE_AVSYNC	3

// Stream audio type
#define STREAM_AUDIO_NONE   0
#define STREAM_AUDIO_G711   1
#define STREAM_AUDIO_G726   6

// Video lost mode
#define VIDEO_LOST_MODE_NONE    0
#define VIDEO_LOST_MODE_CHINESE 1
#define VIDEO_LOST_MODE_ENGLISH 2

// YUV format
#define YUV_FORMAT_YV16         0                   // Planar YUV 422
#define YUV_FORMAT_UYVY         1                   // Packed YUV 422
#define YUV_FORMAT_SEMI_YUV422  2                   // Semi-Planar YUV 422
#define YUV_FORMAT_YUV444       3                   // Planar YUV

// Sharp level
#define SHARP_LEVEL_0           0
#define SHARP_LEVEL_1           1

// Sale type
#define SALE_TYPE_CHINA             0x1357
#define SALE_TYPE_OVERSEA           0x2468
#define SALE_TYPE_CUSTOM_HANWANG    0x3000

//video information
typedef struct{
	int Brightness;
	int Contrast;
	int Saturation;
	int Hue;
}VIDEO_INFO, *PVIDEO_INFO;

//Video Standard
typedef enum {
   StandardNone                   = 0x80000000,
   StandardNTSC                   = 0x00000001,
   StandardPAL                    = 0x00000002,
   StandardSECAM                  = 0x00000004,
   Standard720P                   = 0x00000005,
   Standard1080P                  = 0x00000006,
} VideoStandard_t;   

//Vi Format For HD 18304.
typedef enum{
    NotSupportVi = 0,
    P1080_25     = 1,
    P1080_30     = 2,
    P720_25      = 3,
    P720_30      = 4,
}ViStandard_t; 

////////////////////////////////////////////////////////////////////////////////
//VideoPreviewDisplayMode
// ////////////////////////////////////////////////////////////////////////////////
// 
// 
// 通过GDI显示视频。
// 优点：通用性好，适合在远程桌面连接，或没有安装显卡驱动时使用。
// 缺点：效率很低。
#define HB_DISTECH_GDI                 0x1

//通过DirectDraw7显示视频，DirectX8.0之后被Direct3D代替。
//优点：显示效率非常高，能够以很高帧率显示视频。
//缺点：画面可能会有“撕裂(tearing)”现象，不可以用于远程桌面连接。
#define HB_DISTECH_DIRECTDRAW_7        0x2

//通过Direct3D9显示视频。
//优点：显示效率高，最高显示帧率由监视器刷新频率决定，画面没有“撕裂”现象。
//      在Windows Vista/7系统上，可以用于远程桌面连接。
//缺点：需要较多显存。在Windows 2000/XP/2003系统上不可以用于远程桌面连接。
#define HB_DISTECH_DIRECT_3D_9         0x4

//通过Direct3D11显示视频。
//优点：
//缺点：尚未实现。
#define HB_DISTECH_DIRECT_3D_11        0x8

//自动选择合适的显示技术。
#define HB_DISTECH_AUTO                (HB_DISTECH_GDI | HB_DISTECH_DIRECTDRAW_7 \
    | HB_DISTECH_DIRECT_3D_9)

/////////////////////////////////////////////////////////////////////////////////
//Version Info
typedef struct tagVersion{
	ULONG DspVersion,DspBuildNum;
	ULONG DriverVersion,DriverBuildNum;
	ULONG SDKVersion,SDKBuildNum;
}VERSION_INFO,*PVERSION_INFO;

//Video Setting
typedef struct{
	BYTE	Mode;           // 0:cbr 1:vbr
	BYTE	FrameRate;      // PAL:1-25, NTSC:1-30
	BYTE	PictureSize;    // ENCODE_PICTURESIZE
	BYTE	AudioType;      // 0:G.729 1:A-law
	DWORD	VBRQuality;     // vbr
	DWORD	BitRate;        // vbr:MaxBitRate cbr:BitRate
	DWORD	IFrameInterval; // I frame interval
	DWORD	Reserve1;
}ENCODE_SETTINGS,*PENCODE_SETTINGS;

//Encode Info
typedef struct tagFramesStatistics{
	ULONG VideoFrames;
	ULONG AudioFrames;
	ULONG FramesLost;
	ULONG QueueOverflow;
	ULONG CurBps;
}FRAMES_STATISTICS,*PFRAMES_STATISTICS;

//Video Info
typedef struct tagVFramesStatistics{
    ULONG VideoFrames;
    ULONG AudioFrames;
    ULONG CurFps;
}VFRAMES_STATISTICS,*PVFRAMES_STATISTICS;

//File Header
typedef struct _T1800H264_FILE_HEAD_
{
	char	manufacture[8];
	char    reserved[56];
}T1800H264_FILE_HEAD;

// Board information.
typedef struct _BOARD_INFO
{
    char                    pszName[16];        // Device name
    DWORD                   dwTypeId;           // Device type
    DWORD                   dwSaleType;         // Sale type
    DWORD                   dwSerialNumber;     // Serial number
    DWORD                   dwPictureFormat;    // Encode picture format
    BOOL                    bAudio;             // Audio flag

    // Do not access the following members. Reserved for HB18T SDK.
    DWORD                   dwCifD1Flag;        // Picture flag
    BOOL                    bVideoOut;          // Video out flag
    DWORD                   dwChipCount;        // Chip count
    DWORD                   dwChannelCount;     // Channel count
} BOARD_INFO, *PBOARD_INFO;

typedef struct _STREAM_TYPE
{
    DWORD                   dwStreamType;
    DWORD                   dwAudioType;
    DWORD                   Reserved[4];
} STREAM_TYPE, *PSTREAM_TYPE;


#define SUB_ENCODE          0x100000

//Frame Type
typedef enum {
	PktError = 0,
	PktIFrames = 0x0001,
	PktPFrames = 0x0002,
	PktBBPFrames = 0x0004,
	PktAudioFrames = 0x0008,
	PktMotionDetection = 0x00010,
	PktDspStatus = 0x00020,
	PktOrigImage = 0x00040,
	PktSysHeader = 0x00080,
	PktBPFrames = 0x00100,
	PktSFrames = 0x00200
//PktQCifIFrames,
//PktQCifPFrames,
}FrameType_t;


//Video Encode Size
typedef enum {
    ENC_CIF_FORMAT = 0,
    ENC_QCIF_FORMAT = 1,
    ENC_2CIF_FORMAT = 2,
    ENC_4CIF_FORMAT = 3,
    ENC_720P_FORMAT = 4,
    ENC_1080P_FORMAT = 5,
    ENC_CIFQQCIF_FORMAT = 6,
    ENC_CIFCIF_FORMAT = 7,
    ENC_4CIFCIF_FORMAT = 8,
    ENC_4CIFQCIF_FORMAT = 9,
    ENC_DCIF_FORMAT = 10,
    ENC_SQD1_FORMAT = 11,
    ENC_CIFQCIF_FORMAT = 12

}PictureFormat_t;

//Motion Detect Data Header
typedef struct tagMotionData{
	PictureFormat_t PicFormat;
	ULONG HorizeBlocks;
	ULONG VerticalBlocks;
	ULONG BlockSize;
}MOTION_DATA_HEADER, *PMOTION_DATA_HEADER;

//Video Encode Mode
typedef enum {
	brCBR = 0,
	brVBR = 1,
}BitrateControlType_t;

typedef int  (CALLBACK *STREAM_READ_CALLBACK )(ULONG channelNumber, void *context);
typedef void (CALLBACK *IMAGE_STREAM_CALLBACK)(int channelNumber,void *context);
typedef void (CALLBACK *GET_DC_ROUTINE)(HDC hDC, PVOID pDcContext, DWORD dwChannel);

/////////////////////////////////////////////////////////////////////////////////
// Export functions
/////////////////////////////////////////////////////////////////////////////////


// Initialization
TMAPI int __stdcall	T18_SetVideoStandard(HANDLE hChannel, VideoStandard_t VideoStandard);
TMAPI int __stdcall T18_SetVideoDefinition(VideoStandard_t VideoDefinition[]);
TMAPI int __stdcall T18_SetDefaultVideoStandard(VideoStandard_t VideoStandard);
TMAPI int __stdcall T18_InitDSPs();
TMAPI int __stdcall T18_InitDSPsEx( BOOL bShowConsole, BOOL bLogFile );
TMAPI int __stdcall T18_DeInitDSPs();
TMAPI int __stdcall T18_ResetDSP(HANDLE hChannel);
TMAPI HANDLE __stdcall T18_ChannelOpen(int ChannelNum);
TMAPI int __stdcall T18_ChannelClose(HANDLE hChannel);
TMAPI int __stdcall T18_GetBoardNum();
TMAPI int __stdcall T18_GetBoardChannel( int nBoardIndex );
TMAPI int __stdcall T18_SetAutoReset( BOOL bReset );


// Environment Information
TMAPI int __stdcall T18_GetTotalChannels();
TMAPI int __stdcall T18_GetTotalDSPs();
TMAPI int __stdcall T18_GetLastErrorNum(HANDLE hChannel, ULONG *DspError, ULONG *SdkError);
TMAPI int __stdcall T18_GetSDKVersion(PVERSION_INFO VersionInfo);
TMAPI int __stdcall T18_GetBoardInfo(HANDLE hChannel, ULONG *BoardType, UCHAR *SerialNo);
TMAPI int __stdcall T18_GetBoardInfoEx(HANDLE hChannel, PBOARD_INFO pBoardInfo );


// Video & Audio Preview
TMAPI int __stdcall T18_StartVideoPreview(HANDLE hChannel, HWND hWnd, RECT *rect, BOOLEAN bOverlay, int VideoFormat, int FrameRate);
TMAPI int __stdcall T18_StartVideoPreviewEx(HANDLE hChannel, HWND hWnd, RECT *rect, BOOLEAN bOverlay, int VideoFormat, int FrameRate);
TMAPI int __stdcall T18_StopVideoPreview(HANDLE hChannel);
TMAPI int __stdcall	T18_SetOverlayColorKey(COLORREF DestColorKey);
TMAPI int __stdcall T18_UpdateOverlay();
TMAPI int __stdcall T18_ReleaseOverlay();
TMAPI int __stdcall T18_RestoreOverlay();
TMAPI int __stdcall	T18_SetAudioPreview(HANDLE hChannel, BOOL bEnable);
TMAPI int __stdcall	T18_SetAudioPreviewVolume(HANDLE hChannel, DWORD nVolume);
TMAPI int __stdcall	T18_GetRawAudioVolume(HANDLE hChannel, DWORD &nVolume);
TMAPI int __stdcall	T18_GetSoundLevel(HANDLE hChannel);
TMAPI int __stdcall T18_GetVideoSignal(HANDLE hChannel);
TMAPI int __stdcall T18_SetVideoPara(HANDLE hChannel, int nBrightness, int nContrast, int nSaturation, int nHue);
TMAPI int __stdcall T18_GetVideoPara(HANDLE hChannel, VideoStandard_t *VideoStandard, int *Brightness, int *Contrast, int *Saturation, int *Hue);
TMAPI int __stdcall	T18_SetVideoLostMode(int nMode);
TMAPI int __stdcall T18_SetVideoLostModeEx(HANDLE hChannel, int nMode);
TMAPI int __stdcall	T18_SetVideoClip(HANDLE hChannel, int X, int Y);
TMAPI int __stdcall	T18_SetVideoNightFilter(HANDLE hChannel, int nVideoNightFilter);
TMAPI int __stdcall	T18_SetVideoSharp(HANDLE hChannel, int nLevel);
TMAPI int __stdcall T18_SetD1VerticalFilterMode(int nMode);
TMAPI int __stdcall T18_SetPreviewDisplayMode( DWORD dwDisplayMode );


TMAPI int __stdcall	T18_RegisterGetDcCallback(HANDLE hChannel, GET_DC_ROUTINE GetDcCallback, void *Context);

// Encode
TMAPI int __stdcall	T18_RegisterMessageNotifyHandle(HWND hWnd, UINT MessageId);
TMAPI int __stdcall	T18_RegisterStreamReadCallback(STREAM_READ_CALLBACK StreamReadCallback, void *Context);
TMAPI int __stdcall	T18_SetStreamType(HANDLE hChannel, USHORT Type);
TMAPI int __stdcall	T18_SetStreamTypeEx(HANDLE hChannel, PSTREAM_TYPE pStreamType );
TMAPI int __stdcall	T18_GetStreamType(HANDLE hChannel, USHORT *StreamType);
TMAPI int __stdcall	T18_GetStreamTypeEx(HANDLE hChannel, PSTREAM_TYPE pStreamType );
TMAPI int __stdcall	T18_SetEncoderPictureFormat(HANDLE hChannel, PictureFormat_t PictureFormat);
TMAPI int __stdcall	T18_SetAllEncoderPictureFormat(PictureFormat_t *pPictureFormat);
TMAPI int __stdcall	T18_StartVideoCapture(HANDLE hChannel);
TMAPI int __stdcall	T18_StopVideoCapture(HANDLE hChannel);
TMAPI int __stdcall	T18_SetIBPMode(HANDLE hChannel, int KeyFrameIntervals, int BFrames, int PFrames, int FrameRate);
TMAPI int __stdcall T18_SetDefaultQuant(HANDLE hChannel, int IQuantVal, int PQuantVal, int BQuantVal);
TMAPI int __stdcall	T18_SetBitrateControlMode(HANDLE hChannel, BitrateControlType_t brc);
TMAPI int __stdcall	T18_SetupBitrateControl(HANDLE hChannel, ULONG MaxBps);
TMAPI int __stdcall	T18_SetEncodeAudioType(HANDLE hChannel, int nType);
TMAPI int __stdcall	T18_CaptureIFrame(HANDLE hChannel);
TMAPI int __stdcall T18_GetSystemHeader(HANDLE hChannel, UCHAR **pSystemHeader, DWORD *Length);
TMAPI int __stdcall	T18_SetupNotifyThreshold(HANDLE hChannel, int iFramesThreshold);
TMAPI int __stdcall	T18_ReadStreamData(HANDLE hChannel, void *DataBuf, DWORD *Length, int *FrameType);
TMAPI int __stdcall	T18_ReadStreamDataEx(HANDLE hChannel, void *DataBuf, DWORD *pLength, int *FrameType, void** pData264, DWORD* pLengh264);
TMAPI int __stdcall T18_GetFramesStatistics(HANDLE hChannel, PFRAMES_STATISTICS framesStatistics);
TMAPI int __stdcall	T18_SetupSubChannel(HANDLE hChannel, int iSubChannel);
TMAPI int __stdcall	T18_GetSubChannelStreamType(void  *DataBuf, int FrameType);
TMAPI int __stdcall	T18_SetEncoderFormat(HANDLE hChannel, PictureFormat_t PictureFormat);


// Get Picture
TMAPI int __stdcall	T18_GetOriginalImage(HANDLE hChannel, UCHAR *ImageBuf, ULONG *Size, DWORD nPictureType=0);
TMAPI int __stdcall	T18_GetOriginalImageEx(HANDLE hChannel, UCHAR *ImageBuf, ULONG *Size, DWORD nPictureType=0);


// Video Stream
TMAPI int __stdcall	T18_SetImageStream(HANDLE hChannel, BOOL bStart, int fps,int width,int height, unsigned char *imageBuffer);
TMAPI int __stdcall	T18_RegisterImageStreamCallback(IMAGE_STREAM_CALLBACK ImageStreamCallback,void *context);


// Motion Detect
TMAPI int __stdcall	T18_SetupMotionDetection(HANDLE hChannel, RECT *RectList, int iAreas);
TMAPI int __stdcall	T18_AdjustMotionDetectPrecision(HANDLE hChannel, int iGrade, int iFastMotionDetectFps = 0, int iSlowMotionDetectFps = 0);
TMAPI int __stdcall	T18_StartMotionDetection(HANDLE hChannel);
TMAPI int __stdcall	T18_StopMotionDetection(HANDLE hChannel);
TMAPI int __stdcall	T18_MotionAnalyzer(HANDLE hChannel, char *MotionData, int iThreshold, int *iResult);


// Analog output
TMAPI int __stdcall T18_IsSupportVideoOut(int nDspId);
TMAPI int __stdcall T18_StartVideoOut(HANDLE hChannel, int nDspId, int nReserved);
TMAPI int __stdcall T18_StopVideoOut(HANDLE hChannel);
TMAPI int __stdcall T18_StartDataOut( int nDspId );
TMAPI int __stdcall T18_StopDataOut( int nDspId );
TMAPI int __stdcall T18_InputData(int nDspId, LPCVOID pYV12, int nWidth, int nHeight);


// Logo, OSD & Mosaic
TMAPI int __stdcall	T18_SetLogoDisplayMode(HANDLE hChannel, COLORREF ColorKey, BOOL bTranslucent, int nReserve);
TMAPI int __stdcall	T18_SetLogo(HANDLE hChannel, int x, int y, int w, int h, unsigned char *yuv);
TMAPI int __stdcall	T18_StopLogo(HANDLE hChannel);
TMAPI int __stdcall	T18_SetOsdDisplayMode(HANDLE hChannel, int Brightness, int nTransparence, int NOT, int nLine, USHORT **Format);
TMAPI int __stdcall	T18_SetOsd(HANDLE hChannel, BOOL Enable);
TMAPI int __stdcall	T18_SetMosaic(HANDLE hChannel, BOOL Enable, RECT rect);
TMAPI int __stdcall T18_LoadYUV444FromBmpFile(char *FileName, unsigned char *yuv, int BufLen, int *Width, int*Height);
TMAPI int __stdcall T18_LoadYUVFromBmpFile(char *FileName, unsigned char *yuv, int BufLen, int *Width, int *Height);
TMAPI int __stdcall	T18_LoadYUVFromBmpFileEx( char *FileName, unsigned char *pYuv, int* BufLen, int *Width, int *Height, DWORD nYuvType );
TMAPI int __stdcall T18_SaveYUVToBmpFile(char *cFileName, unsigned char *yuv, int Width, int Height, DWORD nYUVType=0);
TMAPI int __stdcall	T18_SaveYUVToBmpFileEx( char *cFileName, unsigned char *pYuv, int nWidth, int nHeight, DWORD nYuvType );


// Hard Disk Management
TMAPI int __stdcall T18_InitDisk(int *nDiskNum);
TMAPI int __stdcall T18_DeInitDisk();
TMAPI int __stdcall T18_TurnOnDisk(int nDiskId);
TMAPI int __stdcall T18_TurnOnDiskEx(char nDiskLabel);
TMAPI int __stdcall T18_TurnOffDisk(int nDiskId);
TMAPI int __stdcall T18_TurnOffDiskEx(char nDiskLabel);
TMAPI int __stdcall T18_GetDiskState(int nDiskId,int *nOnOff);
TMAPI int __stdcall T18_GetDiskStateEx(char nDiskLabel,int *nOnOff);


// Access A/D, D/A register
TMAPI DWORD __stdcall T18_AccessTw2864( HANDLE hChannel, BOOL bWrite, DWORD dwAddress, DWORD dwValue );
TMAPI DWORD __stdcall T18_AccessSaa7121( HANDLE hChannel, BOOL bWrite, DWORD dwAddress, DWORD dwValue );

// Access EEPROM
TMAPI int __stdcall T18_WriteSecData( HANDLE hChannel, char* pData, DWORD Length );
TMAPI int __stdcall T18_ReadSecData( HANDLE hChannel, char *pData, DWORD Length );

// IVA
TMAPI DWORD __stdcall T18_GetIvaFunction( HANDLE hChannel );

TMAPI int __stdcall T18_GetDspInfo( int nDsp, OUT PBOARD_INFO pBoardInfo );
TMAPI int __stdcall T18_ReadMemory( int nDsp, DWORD dwAddress, OUT LPDWORD lpValue );
TMAPI int __stdcall T18_WriteMemory( int nDsp, DWORD dwAddress, DWORD dwValue );

TMAPI int __stdcall T18_ChangeVideoSize( HANDLE hChannel, int size , int nFrameRate );

// VI
TMAPI int __stdcall T18_GetViParameter(HANDLE hChannel, ViStandard_t *pViStandard);

// Comm
TMAPI int __stdcall T18_SetCommState(HANDLE hChannel, LPDCB lpDCB);
TMAPI int __stdcall T18_GetCommState(HANDLE hChannel, LPDCB lpDCB); 
TMAPI int __stdcall T18_WriteCommData(HANDLE hChannel, LPCVOID pBuffer, DWORD dwLength);  

#endif      // end _T1800_H