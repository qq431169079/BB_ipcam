
#ifndef HIPCAM_DEFINE
#define HIPCAM_DEFINE

enum HFRAMETYPE_DLL { HIPCam_VIDEO , HIPCam_AUDIO, HIPCam_EVENT,__FRAMETYPE_BOUNDARY = 0xFFFFFFFF };
enum HAUDIOTYPE_DLL { HAT_PCM, HAT_ULOW_ADPCM, HAT_IMA_ADPCM, HAT_MPEG1_L2, HAT_MPEG1_L3, HAT_MS_ADPCM,
					  HAT_IP_IMA_ADPCM, HINVALID_AUDIO_TYPE__=0xffffffff};

enum HPTZ_MODEL { HPTZ_NONE=0,
                  HPTZ_HPT_11A,
                  HPTZ_Panasonic_CS850,
                  HPTZ_DynaColor_D,
                  HLilin_PIH_7600,
                  HPTZ_PELCO_D,
                  HPTZ_PELCO_P,
                  HPTZ_DMP_15H1,
                  HPTZ_HLC_860, 
				  HPTZ_HLC_870,
                  __PTZTYPE_BOUNDARY=0xFFFFFFFF
                    };
enum HRTSP_TYPE{ HTCP, HUDP, __INVALID_RTSPTYPE = 0xFFFFFFFF };

enum HDecode_Type{HDTYPE_RGB32, HDTYPE_YUV422};

struct Connect_Info{
	char* sIP;
	int iPort;
	char* sUser;
	char* sPass;
	int iCh;
};

struct HFrame{
    int iFrameType;	/**FrameType
						2 : I
						3 : P
						4 : B
						5 : AUDIO
						6 : MOTION
						7 : SYSTEM
						9 : ALARM
					**/
    int iDataLen;
    char* cFrameData;
    FILETIME ftFrameTime;
};

struct HVideo_Config{
    int     iResolution;
 				/**	0 : QCIF
 					1 : CIF
 					2 : VGA
 					3 : D1  
				**/
	int		iQuality;
				/** 0 : Low
					1 : Medium
					2 : Standard
					3 : High
					4 : Best
				**/
    int     iFps;
				/**	NTSC	3 ~ 30
					PAL		3 ~ 25
				**/
    int     iMode;
				/**	1 : MPEG4
					2 : JPEG
				**/
    int     iFormat;
				/**	1 : NTSC
					2 : PAL
				**/
};

struct HGet_Motion_Info{
    bool    bEnabled[3];
    RECT    rArea[3];
    int     iSensitivity[3];
    int     iSenMinValue;
    int     iSenMaxValue;
};                       

struct HSet_Motion_Info{
    bool    bEnabled[3];
    RECT    rArea[3];
    int     iSensitivity[3];
};

struct HPTZ_Info{
	HPTZ_MODEL iPTZType;
    int iDeviceID;
    int iBaudRate;
    int iSpeed;
    char* sPointName[10];
};

struct HVideo_Info{

	// System information
	ULONG	uSystemType;

	// Video information
	ULONG	uVideoType;/**
					   0 : JPEG
					   4 : MPEG4
					   5 : H264
					   **/
	int iWidth;
	int iHeight;
	double	dFrameRate;
	
	// Audio information
	int		iAudioType;
	int		iAudioChannel;
	int		iAudioSampleRate;
	int		iAudioBitRate;
	int		iAudioFrameSize;
};

struct PTZOSCInfo
{
    int iWidth;
    int iHeight;
    int iX;
    int iY;

    PTZOSCInfo(){}
    PTZOSCInfo(int _iW, int _iH, int _iX, int _iY):iWidth(_iW), iHeight(_iH), iX(_iX), iY(_iY)
    {
    }
};

typedef int (CALLBACK * HFRAME_CALLBACK)(int iContext, unsigned char ucChannel, HFrame *pFrame, HVideo_Info VInfo);

/**
 *  iEventNum :
 *  IPCAM_OK                    IPCam is living
 *  IPCAM_IS_FULL               the connections of IPCam is full
 *  IPCAM_USER_OR_PASSWD_IS_ER  unauthorized error
 *  IPCAM_CANT_DETECT_TYPE_ER   can't detect IPCam's type automatically
 *  IPCAM_IS_OVER               IPCam was deleted
 *  IPCAM_IS_UNCONNECTED        connect failed or disconnect
 */
typedef int (CALLBACK * HEVENT_CALLBACK)(int iContext, HANDLE hCam, unsigned char ucChannel, int iEventNum);

#endif