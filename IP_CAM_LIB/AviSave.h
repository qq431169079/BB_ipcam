 
#include "HOEM_IPCam_SDK.h"
#include "HOEM_Play_SDK.h"
#include "Vfw.h"

class AVIFileSave
{
    public:
        bool OpenAviFile(const char *filename, bool bFileCreate, bool bWithAudio, HVideo_Info VInfo, int iCh);
        bool SaveFrame(bool FrameType, int iCount, HFrame *FrameData, int iCh);
        bool CloseFile(int iCh);

		BYTE m_AudioData[19200 * 4];

    private:
        IAVIFile *pfile;
        AVISTREAMINFO VStreamInfo, AStreamInfo;
        PAVISTREAM pVStream, pAStream;
        BITMAPINFOHEADER sBitmapInfo;
        bool err;
        HRESULT hr;
		int m_iType;
};