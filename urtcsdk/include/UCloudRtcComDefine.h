#ifndef _UCLOUD_RTC_SDKENGINE_COMMONDEFINE_H_
#define _UCLOUD_RTC_SDKENGINE_COMMONDEFINE_H_

#ifdef _EXPORT
#define _EXPORT_API __declspec(dllexport)
#define _EXPORT_API_C extern "C" __declspec(dllexport)
#else
#define _EXPORT_API __declspec(dllimport)
#define _EXPORT_API_C  extern "C" __declspec(dllimport)
#endif

#define  C_API extern "C"
#define MAX_DEVICE_ID_LENGTH 128 
#define MAX_WINDOWS_TILE_LEN 256 

//�豸��Ϣ
typedef struct {
	char mDeviceName[MAX_DEVICE_ID_LENGTH];
	char mDeviceId[MAX_DEVICE_ID_LENGTH];
}tUCloudRtcDeviceInfo;

//ý������
typedef struct {
	bool mVideoEnable;
	bool mAudioEnable;
}tUCloudRtcMediaConfig;

//��������
typedef struct
{
	long mScreenindex;
	int  mXpos;
	int mYpos;
	int mWidth;
	int mHeight;
}tUCloudRtcScreenPargram;

//��������
typedef enum {
	UCLOUD_RTC_DESKTOPTYPE_SCREEN = 1,
	UCLOUD_RTC_DESKTOPTYPE_WINDOW
}eUCloudRtcDesktopType;

//���洰����Ϣ
typedef struct
{
	eUCloudRtcDesktopType mType;
	int mDesktopId;
	char mDesktopTitle[MAX_WINDOWS_TILE_LEN];
}tUCloudRtcDeskTopInfo;

//�������
typedef enum {
	UCLOUD_RTC_TRACKTYPE_AUDIO = 1,
	UCLOUD_RTC_TRACKTYPE_VIDEO 
}eUCloudRtcTrackType;

//ý������
typedef enum {
	UCLOUD_RTC_MEDIATYPE_NONE = 0,
	UCLOUD_RTC_MEDIATYPE_VIDEO = 1,
	UCLOUD_RTC_MEDIATYPE_SCREEN = 2
}eUCloudRtcMeidaType;

//����Ϣ
typedef struct {
	const char* mUserId;
	const char* mStreamId;
	bool mEnableVideo;
	bool mEnableAudio;
	bool mEnableData;
	eUCloudRtcMeidaType mStreamMtype;
}tUCloudRtcStreamInfo;

//mute ״̬
typedef struct {
	const char* mUserId;
	const char* mStreamId;
	bool mMute;
	eUCloudRtcMeidaType mStreamMtype;
}tUCloudRtcMuteSt;

//¼�Ƶ�profile
typedef enum {
	UCLOUD_RTC_RECORDPROFILE_SD = 1, 
	UCLOUD_RTC_RECORDPROFILE_HD, 
	UCLOUD_RTC_RECORDPROFILE_HDPLUS, 
}eUCloudRtcRecordProfile;

//¼������
typedef enum {
	UCLOUD_RTC_RECORDTYPE_AUDIOONLY = 1, 
	UCLOUD_RTC_RECORDTYPE_AUDIOVIDEO
}eUCloudRtcRecordType;

//ˮӡλ��
typedef enum {
	UCLOUD_RTC_WATERMARKPOS_LEFTTOP = 1,
	UCLOUD_RTC_WATERMARKPOS_LEFTBOTTOM,
	UCLOUD_RTC_WATERMARKPOS_RIGHTTOP,
	UCLOUD_RTC_WATERMARKPOS_RIGHTBOTTOM
}eUCloudRtcWaterMarkPos;

//ˮӡ����
typedef enum {
	UCLOUD_RTC_WATERMARK_TYPE_NONE = 0,
	UCLOUD_RTC_WATERMARK_TYPE_TIME = 1,
	UCLOUD_RTC_WATERMARK_TYPE_PIC,
	UCLOUD_RTC_WATERMARK_TYPE_TEXT,
}eUCloudRtcWaterMarkType;

//��Ⱦ����
typedef enum {
	UCLOUD_RTC_RENDER_MODE_DEFAULT = 0, //default full
	UCLOUD_RTC_RENDER_MODE_FIT = 1, 
	UCLOUD_RTC_RENDER_MODE_FILL = 2 
} eUCloudRtcRenderMode;

//��Ⱦ����
typedef enum {
	UCLOUD_RTC_RENDER_TYPE_GDI = 1,
	UCLOUD_RTC_RENDER_TYPE_D3D = 2,
	UCLOUD_RTC_RENDER_TYPE_EXTEND = 3,
} eUCloudRtcRenderType;

//��־����
typedef enum {
	UCLOUD_RTC_LOG_LEVEL_DEBUG,
	UCLOUD_RTC_LOG_LEVEL_INFO,
	UCLOUD_RTC_LOG_LEVEL_WARN,
	UCLOUD_RTC_LOG_LEVEL_ERROR,
	UCLOUD_RTC_LOG_LEVEL_NONE,
} eUCloudRtcLogLevel;

//��Ƶprofile
typedef enum {
	UCLOUD_RTC_VIDEO_PROFILE_NONE = -1, 
	UCLOUD_RTC_VIDEO_PROFILE_320_180 = 1,
	UCLOUD_RTC_VIDEO_PROFILE_320_240 = 2,
	UCLOUD_RTC_VIDEO_PROFILE_640_360 = 3,
	UCLOUD_RTC_VIDEO_PROFILE_640_480 = 4,
	UCLOUD_RTC_VIDEO_PROFILE_1280_720 = 5,
	UCLOUD_RTC_VIDEO_PROFILE_1920_1080 = 6
} eUCloudRtcVideoProfile;

//����profile
typedef enum {
	UCLOUD_RTC_SCREEN_PROFILE_LOW = 1,
	UCLOUD_RTC_SCREEN_PROFILE_MIDDLE = 2,
	UCLOUD_RTC_SCREEN_PROFILE_HIGH = 3,
	UCLOUD_RTC_SCREEN_PROFILE_HIGH_PLUS = 4
} eUCloudRtcScreenProfile;

//Ӧ������
typedef enum {
	UCLOUD_RTC_CHANNEL_TYPE_COMMUNICATION,
	UCLOUD_RTC_CHANNEL_TYPE_BROADCAST
}eUCloudRtcChannelType;

//Ȩ������
typedef enum {
	UCLOUD_RTC_USER_STREAM_ROLE_PUB, // up
	UCLOUD_RTC_USER_STREAM_ROLE_SUB,// down
	UCLOUD_RTC_USER_STREAM_ROLE_BOTH //both
} eUCloudRtcUserStreamRole;

//SDK ģʽ
typedef enum {
	UCLOUD_RTC_SDK_MODE_NORMAL, 
	UCLOUD_RTC_SDK_MODE_TRIVAL, 
} eUCloudRtcSdkMode;

//��Ƶ��������
typedef enum {
	UCLOUD_RTC_CODEC_VP8 = 1, //default
	UCLOUD_RTC_CODEC_H264 
} eUCloudRtcVideoCodec;

//��Ƶ��������
typedef enum {
	UCLOUD_RTC_CODEC_OPUS = 1, //default
} eUCloudRtcAudioCodec;

//FRAME ����
typedef enum {
	UCLOUD_RTC_VIDEO_FRAME_TYPE_I420 = 1,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_RGB24,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_BGR24,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_RGBA,
	UCLOUD_RTC_VIDEO_FRAME_TYPE_ARGB,
}eUCloudRtcVideoFrameType;

//��������������
typedef enum {
	UCLOUD_RTC_NETWORK_TX = 1,  //����
	UCLOUD_RTC_NETWORK_RX = 2,  //����
}eUCloudRtcNetworkQuality;

//��������
typedef enum {
	UCLOUD_RTC_QUALITY_UNKNOWN = 0, //δ֪
	UCLOUD_RTC_QUALITY_DOWN = 1,  //�ܻ�
	UCLOUD_RTC_QUALITY_BAD = 2,  //��ǿ�ܹ�ͨ����˳��
	UCLOUD_RTC_QUALITY_POOR =  3, //�û����۸�����覴õ���Ӱ�칵ͨ
	UCLOUD_RTC_QUALITY_GOOD = 4, // �û����۸о��� excellent ���
	UCLOUD_RTC_QUALITY_EXCELLENT = 5, //������������
}eUCloudRtcQualityType;

//rtmp״̬
typedef enum {
	RTMP_STREAM_PUBLISH_STATE_IDLE , //����δ��ʼ��ֹͣ  
	RTMP_STREAM_PUBLISH_STATE_RUNNING,  //��������
	RTMP_STREAM_PUBLISH_STATE_FAILURE , //����ʧ�� ���code
	RTMP_STREAM_PUBLISH_STATE_STOPFAILURE, //ֹͣ����ʧ�� ���code
	RTMP_STREAM_PUBLISH_STATE_EXCEPTIONSTOP, //�쳣ֹͣ����(������ʱֹͣ)
}eUCloudRtmpState;

// ��Ⱦ����
typedef struct
{
	void* mVideoView;
	const char* mUserId;
	const char* mStreamId;
	eUCloudRtcMeidaType mStreamMtype;
	eUCloudRtcRenderMode mRenderMode;
	eUCloudRtcRenderType mRenderType;
	eUCloudRtcVideoFrameType mVideoFrameType; //when extend render this decide callback frametype
}tUCloudRtcVideoCanvas;

//��Ȩ��Ϣ
typedef struct
{
	const char* mAppId;
	const char* mRoomId;
	const char* mUserId;
	const char* mUserToken;
}tUCloudRtcAuth;

//����Ϣ
typedef struct {
	const char* mUserId;
	const char* mStreamId;
	int mStreamMtype;
	int mTracktype; // 1 audio 2 video
	int mAudioBitrate = 0;     // audio bitrate,unit:bps
	int mVideoBitrate = 0;
	int mVideoWidth = 0;     // video width
	int mVideoHeight = 0;     // video height
	int mVideoFrameRate = 0;     // video frames per secon
	float mPacketLostRate = 0.0f;
}tUCloudRtcStreamStats;

//¼����Ϣ
typedef struct {
	const char* mRecordId;
	const char* mFileName;
	const char* mRegion;
	const char* mBucket;
	const char* mRoomid;
}tUCloudRtcRecordInfo;

//��Ƶ֡��Ϣ
typedef struct {
	const char* mUserId;
	const char* mStreamId;
	void* mAudioData;
	int mBytePerSimple;
	int mSimpleRate;
	int mChannels;
	int mNumSimples;
}tUCloudRtcAudioFrame;

//��Ƶ֡��Ϣ
typedef struct {
	unsigned char* mDataBuf;
	int mWidth;
	int mHeight;
	eUCloudRtcVideoFrameType mVideoType;
}tUCloudRtcVideoFrame;

//��Ƶ��Ϣ����
typedef struct {
	int mWidth;
	int mHeight;
	int mFrameRate;
}tUCloudVideoConfig;

//��������ɫ����
typedef struct  {
	int mRed;
	int mGreen;
	int mBlue;
}tUCloudBackgroundColor;

//��Ƶ��������
typedef enum {
	UCLOUD_QUALITY_CB = 0, //CB
	UCLOUD_QUALITY_B,
	UCLOUD_QUALITY_M,
	UCLOUD_QUALITY_E,
	UCLOUD_QUALITY_H
}eUCloudRtcQualityLevel;

//ת�ƻ�����������
typedef enum {
	RTMP_STREAM_ADD,	 //���
	RTMP_STREAM_REMOVE,  //ɾ��
}eUCloudRtmpOpration;

//ת�Ƶ���
typedef struct UCloudRtcRelayStream {
	const char* mUid;
	eUCloudRtcMeidaType mType;
	UCloudRtcRelayStream() {
		mUid = nullptr;
		mType = UCLOUD_RTC_MEDIATYPE_NONE;
	}
}tUCloudRtcRelayStream;

//ת�ƻ�����������
typedef enum {
	MIX_LAYOUT_OLD,      //����֮ǰģ��
	MIX_LAYOUT_FLOW,	 //��ʽ����
	MIX_LAYOUT_TEACH,			 //���β���
	MIX_LAYOUT_CUSTOM,    //�Զ���
	MIX_LAYOUT_ADAPTION1, //����Ӧģ��1
	MIX_LAYOUT_ADAPTION2, //����Ӧģ��2
}eUCloudMixLayout;

//ת������
typedef struct UCloudRtcTranscodeConfig {
	tUCloudBackgroundColor mbgColor;  //����ɫ
	int mFramerate; //֡��
	int mBitrate;   //����
	const char*  mMainViewUid; //�����˵�uid
	int mMainviewType; //�����˷��õ�������
	int mWidth;  //����ֱ��ʿ��
	int mHeight; //����ֱ��ʸ߶�
	eUCloudMixLayout mLayout; // 1.��ʽ���� 2.����ģʽ 3.�Զ��岼�� 4.ģ������Ӧ1 5.ģ������Ӧ2
	const char*  mStyle; //mLayout=3 ʱ�Զ���������
	int mLenth;
	tUCloudRtcRelayStream *mStreams; //�������û�
	int mStreamslength; //����
	UCloudRtcTranscodeConfig()
	{
		mLayout = MIX_LAYOUT_TEACH;
		mMainViewUid = nullptr;
		mStreams = nullptr;
		mStyle = nullptr;
		mStreamslength = 0;
	}
}tUCloudRtcTranscodeConfig;

//¼����Ϣ
typedef struct UCloudRtcRecordConfig {
	const char* mMainviewuid;   //¼�Ƶ������û�id
	const char* mBucket;        //�洢bucket
	const char* mBucketRegion;  //�洢region
	eUCloudRtcRecordProfile mProfile;  //¼��profile
	eUCloudRtcRecordType mRecordType;  //¼������
	eUCloudRtcWaterMarkPos mWatermarkPos;  //ˮӡλ��
	eUCloudRtcMeidaType mMainviewmediatype;  //������ý������

	eUCloudRtcWaterMarkType mWaterMarkType;   //ˮӡ����
	const char* mWatermarkUrl;		//ˮӡurl  ΪͼƬˮӡʱ
	bool mIsaverage;				//�Ƿ���� (true .��ʽ���֣�false:����ģʽ)
	int mMixerTemplateType;			//ģ������

	//�°�¼����������
	tUCloudRtcRelayStream *mStreams; //�������û�
	int mStreamslength; //�������û�����
	int mLayout; // 0.ȡ����mIsaverage 1.��ʽ���� 2.����ģʽ 3.�Զ��岼�� 4.ģ������Ӧ1 5.ģ������Ӧ2


	UCloudRtcRecordConfig() {
		mWatermarkUrl = nullptr;
		mMainviewuid = nullptr;
		mBucket = nullptr;
		mBucketRegion = nullptr;
		mStreams = nullptr;
		mLayout = MIX_LAYOUT_OLD;
	}
}tUCloudRtcRecordConfig;
//�豸��λص�
class _EXPORT_API UcloudRtcDeviceChanged
{
public:
	virtual void onInterfaceArrival(const char* dccname, int len) {}
	virtual void onInterfaceRemoved(const char* dccname, int len) {}
	virtual void onInterfaceChangeValue(const char* dccname, int len) {}
	virtual ~UcloudRtcDeviceChanged() {}
};

//��Ƶ�����ص�
class  _EXPORT_API UCloudRtcAudioFrameCallback
{
public:
	virtual void onLocalAudioFrame(tUCloudRtcAudioFrame* audioframe) {}
	virtual void onRemoteMixAudioFrame(tUCloudRtcAudioFrame* audioframe) {}
};

//�ⲿ��ƵԴ
class  _EXPORT_API UCloudRtcExtendAudioCaptureSource
{
public:
	virtual ~UCloudRtcExtendAudioCaptureSource() {}
	virtual  bool doCaptureAudioFrame(tUCloudRtcAudioFrame* audioframe) = 0;
};

//�ⲿ��ƵԴ
class  _EXPORT_API UCloudRtcExtendVideoCaptureSource
{
public:
	virtual  bool doCaptureVideoFrame(tUCloudRtcVideoFrame* videoframe) = 0;
};

//��Ƶ�����ص�
class _EXPORT_API UCloudRtcVideoFrameObserver 
{
public:
	virtual  void onCaptureFrame(unsigned char* videoframe, int buflen) = 0;
};

//�ⲿ��Ⱦ
class _EXPORT_API UCloudRtcExtendVideoRender
{
public:
	virtual  void onRemoteFrame(const tUCloudRtcVideoFrame* videoframe) = 0;
};

#endif

