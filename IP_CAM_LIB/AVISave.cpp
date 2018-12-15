
#include "stdafx.h"

#include "AVISave.h"

//*************************** AVIFileSave Class ***************************//
//---------------------------------------------------------------------------

// bool FileCreate = true:Create a new File / false:Open File For Append
// bool WithAudio  = true:With Audio Stream / false:Without Audio Stream
bool AVIFileSave::OpenAviFile(const char *filename, bool bFileCreate, bool bWithAudio, HVideo_Info VInfo, int iCh)
{
    m_iType = VInfo.uVideoType;

	int lVideoWidth = abs(VInfo.iWidth);
	int lVideoHeight = abs(VInfo.iHeight);

	bool bSetFormat;

    AVIFileInit();
    if(bFileCreate)
    {
        hr = AVIFileOpen(&pfile, filename, OF_WRITE|OF_CREATE, NULL);
        if(hr!=AVIERR_OK)
        {
                err=true; AVIFileExit();
                MessageBox(NULL,"AVIFileOpen[Create] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;
        }
        pVStream = 0;
        pAStream = 0;
        err = false;
        bSetFormat = true;
    }
    else
    {
        hr = AVIFileOpen(&pfile, filename, OF_READWRITE, NULL);
        if(hr!=AVIERR_OK)
        {
                err=true; AVIFileExit();
				MessageBox(NULL,"AVIFileOpen[Append] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;
        }
        bSetFormat = false;
    }

    if(bSetFormat == true)                                //Create Video Stream File
    {
 		memset(&VStreamInfo, 0, sizeof(VStreamInfo));
        VStreamInfo.fccType               = streamtypeVIDEO;
		if (m_iType == 4)
			VStreamInfo.fccHandler = mmioFOURCC('D','I','V','X');
		else if (m_iType == 5)
			VStreamInfo.fccHandler = mmioFOURCC('H','2','6','4');
		else if (m_iType == 0)
			VStreamInfo.fccHandler = mmioFOURCC('M','J','P','G');				
        //VStreamInfo.fccHandler            = (m_iType == 4)?mmioFOURCC('D','I','V','X'):mmioFOURCC('H','2','6','4');
        VStreamInfo.dwFlags               = 0;
        VStreamInfo.dwCaps                = 0;
        VStreamInfo.wPriority             = 0;
        VStreamInfo.wLanguage             = 0;
        VStreamInfo.dwScale               = 1;
        VStreamInfo.dwRate                = VInfo.dFrameRate;
        VStreamInfo.dwStart               = 0;
        VStreamInfo.dwLength              = 0;
        VStreamInfo.dwInitialFrames       = 0;
        VStreamInfo.dwSuggestedBufferSize = 0;
        VStreamInfo.dwQuality             = 0xFFFFFFFF;
        VStreamInfo.dwSampleSize          = 0;
        SetRect(&VStreamInfo.rcFrame, 0, 0, lVideoWidth, lVideoHeight);

        hr = AVIFileCreateStream(pfile, &pVStream, &VStreamInfo);
        if (hr!=AVIERR_OK)
        {
                err=true;
                MessageBox(NULL,"AVIFileCreateStream[Video] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;
        }

		memset(&sBitmapInfo, 0, sizeof(sBitmapInfo));
        sBitmapInfo.biSize          = sizeof(BITMAPINFOHEADER);
        sBitmapInfo.biWidth         = lVideoWidth;
        sBitmapInfo.biHeight        = lVideoHeight;
        sBitmapInfo.biPlanes        = 1;
        sBitmapInfo.biBitCount      = 24;
		if (m_iType == 4)
			sBitmapInfo.biCompression = mmioFOURCC('D','I','V','X');
		else if (m_iType == 5)
			sBitmapInfo.biCompression = mmioFOURCC('H','2','6','4');
		else if (m_iType == 0)
			sBitmapInfo.biCompression = mmioFOURCC('M','J','P','G');
        //sBitmapInfo.biCompression   = (m_iType == 4)?mmioFOURCC('D','I','V','X'):mmioFOURCC('H','2','6','4');
        sBitmapInfo.biSizeImage     = lVideoWidth * lVideoHeight * 3;
        sBitmapInfo.biXPelsPerMeter = 0;
        sBitmapInfo.biYPelsPerMeter = 0;
        sBitmapInfo.biClrUsed       = 0;
        sBitmapInfo.biClrImportant  = 0;

        hr = AVIStreamSetFormat(pVStream, 0, &sBitmapInfo, sizeof(sBitmapInfo));
        if (hr!=AVIERR_OK)
        {
                err=true;
                MessageBox(NULL,"AVIStreamSetFormat[Video] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;

        }
    }


    if(bSetFormat == true && bWithAudio == true)           //Create Audio Stream File
    {
		//Initial Audio Convert Module
		int iRes = HOEM_Play_AudioConvert_Init(iCh, VInfo);

		memset(&AStreamInfo, 0, sizeof(AStreamInfo));
        AStreamInfo.fccType               = streamtypeAUDIO;
        AStreamInfo.fccHandler            = 0;
        AStreamInfo.dwFlags               = 0;
        AStreamInfo.dwCaps                = 0;
        AStreamInfo.wPriority             = 0;
        AStreamInfo.wLanguage             = 0;
        AStreamInfo.dwScale               = 1;
        AStreamInfo.dwRate                = VInfo.iAudioSampleRate;
        AStreamInfo.dwStart               = 0;
        AStreamInfo.dwLength              = VInfo.iAudioFrameSize;
        AStreamInfo.dwInitialFrames       = 0;
        AStreamInfo.dwSuggestedBufferSize = VInfo.iAudioFrameSize;
        AStreamInfo.dwQuality             = 0;
        AStreamInfo.dwSampleSize          = VInfo.iAudioSampleRate;
        
        SetRect(&AStreamInfo.rcFrame, 0, 0, 0, 0);

        hr = AVIFileCreateStream(pfile, &pAStream, &AStreamInfo);
        if (hr!=AVIERR_OK)
        {
                err=true;
                MessageBox(NULL,"AVIFileCreateStream[Audio] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;
        }

		WAVEFORMATEX sWAVEFORMATEX;
		memset(&sWAVEFORMATEX, 0, sizeof(sWAVEFORMATEX));
		sWAVEFORMATEX.wFormatTag = WAVE_FORMAT_PCM;
	    sWAVEFORMATEX.nChannels = 2;         
	    sWAVEFORMATEX.wBitsPerSample = 16; 
	    sWAVEFORMATEX.nSamplesPerSec = VInfo.iAudioSampleRate;//hardcoded for now 48k sample rate
	    sWAVEFORMATEX.nBlockAlign = sWAVEFORMATEX.wBitsPerSample * sWAVEFORMATEX.nChannels / 8;
	    sWAVEFORMATEX.nAvgBytesPerSec = sWAVEFORMATEX.nSamplesPerSec * sWAVEFORMATEX.nBlockAlign;//* 2 channel * 2bytes per channel
	    sWAVEFORMATEX.cbSize = 0;


        hr = AVIStreamSetFormat(pAStream, 0, &sWAVEFORMATEX, sizeof(sWAVEFORMATEX));
        if (hr!=AVIERR_OK)
        {
                err=true;
                MessageBox(NULL,"AVIStreamSetFormat[Audio] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;
        }
    }

    return true;
}
//---------------------------------------------------------------------------

// bool FrameType  = true:Save Audio Frame / false:Save Video Frame
bool AVIFileSave::SaveFrame(bool FrameType, int iCount, HFrame *pFrameData, int iCh)
{
	if(err == true) return false;

    if(FrameType == false)                 //Video Frame
    {
        if(pFrameData->iFrameType == 2)   //I Frame
        {
            hr = AVIStreamWrite(pVStream, iCount, 1, (void *)pFrameData->cFrameData, pFrameData->iDataLen, AVIIF_KEYFRAME, NULL, NULL);
            if (hr!=AVIERR_OK)
            {
                err=true;
                MessageBox(NULL,"AVIStreamWrite[I-frame] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;
            }
        }
        else                               //P or B Frame
        {
            hr = AVIStreamWrite(pVStream, iCount, 1, (void *)pFrameData->cFrameData, pFrameData->iDataLen, 0, NULL, NULL);
            if (hr!=AVIERR_OK)
            {
                err=true;
                MessageBox(NULL,"AVIStreamWrite[P,B-frame] Error", "Warning", MB_OK|MB_ICONERROR);
                return false;
            }
        }
    }
    else                                   //Audio Frame
    {
		//Convert Audio to PCM Format
		int iLen = HOEM_Play_ConvertAudioData(iCh, pFrameData, m_AudioData);

		if(iLen > 0)
		{
			hr = AVIStreamWrite(pAStream, iCount, 1, (void *)m_AudioData, iLen, AVIIF_KEYFRAME, NULL, NULL);
			if (hr!=AVIERR_OK)
			{
					err=true;
					MessageBox(NULL,"AVIStreamWrite[Audio-frame] Error", "Warning", MB_OK|MB_ICONERROR);
					return false;
			}
		}
		else
			return false;
    }
    return true;
}
//---------------------------------------------------------------------------

bool AVIFileSave::CloseFile(int iCh)
{
	//Deinitial Audio Convert Module
	HOEM_Play_AudioConvert_Deinit(iCh);

    if (pVStream != 0) AVIStreamRelease(pVStream); pVStream=0;
    if (pAStream != 0) AVIStreamRelease(pAStream); pAStream=0;
    if (pfile    != 0) AVIFileRelease(pfile);      pfile=0;
    AVIFileExit();
    return true;
}
//---------------------------------------------------------------------------


