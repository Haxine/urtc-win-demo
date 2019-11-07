#ifndef _UMEETING_RTCDEFINE_H_
#define _UMEETING_RTCDEFINE_H_

#include <string>
#include <map>
#include <list>

enum RTC_CHANNEL_TYPE {
	RTC_CHANNELTYPE_UCLOUD,
	RTC_CHANNELTYPE_AGORA,
	RTC_CHANNELTYPE_ZEGO
};

struct tRTCAuthInfo
{
	std::string mUserid;
	std::string mRoomid;
	std::string mAppid;
	std::string mToken;
};

struct tRTCRenderView
{
	std::string mUserid;
	int mStreamMtype;//1 camera 2 screen
	void* mVidoview;
	int mRenderMode;
	int mRenderType; //1 gdi 2 dx 
};

struct tRTCStreamInfo
{
	std::string mUserid;
	int mStreamMtype; //1 camera 2 screen
	bool mEnableVideo;
	bool mEnableAudio;
	bool mEnableData;
};

struct tRTCStreamMute
{
	std::string mUserid;
	bool mMute;
};

class CVideoWnd;
//��Ϣ�ṹ
struct tEventMsg
{
	int mEventid;
	std::string mJsonMsg;
};

// �û���Ϣ
struct tUserInfo
{
	std::string mUserid;
};

//����Ϣ
struct tStreamInfo
{
	int mStreamMtype;
	std::string mUserid;
	bool mEnalbevideo;
	bool mEnalbeaudio;
	bool mEnalbedata;
};


struct tRecordConfig
{
	const char* mMainviewuid;
	const char* mBucket;
	const char* mBucketRegion;
	int mProfile;
	int mRecordType;
	int mWatermarkPos;
	int mMainviewmediatype;
};

typedef std::map<std::string, tUserInfo*>::iterator userit;
typedef std::map<std::string, tStreamInfo*>::iterator streamit;
typedef std::map<std::string, CVideoWnd*>::iterator streamrenderit;
typedef std::list<CVideoWnd*>::iterator videowndit;


#endif