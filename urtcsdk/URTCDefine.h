#ifndef _UMEETING_URTCDEFINE_H_
#define _UMEETING_URTCDEFINE_H_

#include <string>
#include <map>
#include <list>

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

typedef std::map<std::string, tUserInfo*>::iterator userit;
typedef std::map<std::string, tStreamInfo*>::iterator streamit;
typedef std::map<std::string, std::string>::iterator userstreammapit;
typedef std::map<std::string, CVideoWnd*>::iterator streamrenderit;
typedef std::list<CVideoWnd*>::iterator videowndit;

#define  TEST_APP_ID "URtc-h4r1txxy"
#define  TEST_SECKEY "9129304dbf8c5c4bf68d70824462409f"

#endif