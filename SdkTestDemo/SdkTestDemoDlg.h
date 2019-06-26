
// SdkTestDemoDlg.h : ͷ�ļ�
//

#pragma once

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

#include "VideoWnd.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "UCloudRtcEngine.h"

struct tCallMsg
{
	int eventid;
	std::string msg;
};

// �û���Ϣ
struct tUserInfo
{
	std::string mUserid;
};

//����Ϣ
struct tStreamInfo
{
	int mediatype;
	std::string mUserid;
	bool mEnalbevideo;
	bool mEnalbeaudio;
	bool mEnalbedata;
};

// CSdkTestDemoDlg �Ի���
class CSdkTestDemoDlg : public CDialogEx, public CVideoWndCallback, public UCloudRtcEventListener
{
// ����
public:
	CSdkTestDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

	void OnMuteAudio(std::string userid, eUCloudRtcMeidaType mediatype, bool mute);
	void OnMuteVideo(std::string userid, eUCloudRtcMeidaType mediatype, bool mute);
	void OnClose(std::string type, std::string id);

	//UCloudRtcEventListener interface
	virtual void onServerDisconnect();
	virtual void onJoinRoom(int code, const char* msg, const char* uid, const char* roomid);
	virtual void onLeaveRoom(int code, const char* msg, const char* uid, const char* roomid);
	virtual void onRejoining(const char* uid, const char* roomid);
	virtual void onReJoinRoom(const char* uid, const char* roomid);
	virtual void onRemoteUserJoin(const char* uid);
	virtual void onRemoteUserLeave(const char* uid, int reson);
	virtual void onRemotePublish(tUCloudRtcStreamInfo& info);
	virtual void onRemoteUnPublish(tUCloudRtcStreamInfo& info);
	virtual void onLocalPublish(const int code, const char* msg, tUCloudRtcStreamInfo& info);
	virtual void onLocalUnPublish(const int code, const char* msg, tUCloudRtcStreamInfo& info);
	virtual void onSubscribeResult(const int code, const char* msg, tUCloudRtcStreamInfo& info);
	virtual void onUnSubscribeResult(const int code, const char* msg, tUCloudRtcStreamInfo& info);
	virtual void onLocalStreamMuteRsp(const int code, const char* msg,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute);
	virtual void onRemoteStreamMuteRsp(const int code, const char* msg, const char* uid,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute);
	virtual void onRemoteTrackNotify(const char* uid,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute);
	virtual void onError(int code);
	virtual void onKickoff(int code);
	virtual void onRemoteAudioLevel(const char* uid, int volume);
	virtual void onLocalAudioLevel(int volume);
	virtual void onSendRTCStats(tUCloudRtcStreamStats& rtstats);
	virtual void onRemoteRTCStats(tUCloudRtcStreamStats rtstats);

	std::string m_userid; // �Լ��û�id
	std::string m_roomid; // roomid
	//�û��б�
	std::map<std::string, tUserInfo*> m_hashSessions;//userid<---> userinfo
	std::map<std::string, tStreamInfo*> m_streamsmap;//userid+mediatype<---> streaminfo �����б��Ӧ
	std::map<std::string, CVideoWnd*> m_mapRenders; //userid+mediatype<----> videorender
	CVideoWnd *m_localWnd;
	CVideoWnd *m_screenWnd;
	std::list<CVideoWnd*> m_remoteWnds;
	bool m_campub;
	bool m_screenpub;
	bool m_leaveroom;
	bool m_isclose;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum {IDD = IDD_SFU};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	CVideoWnd* CreateVideoWindow(eUCloudRtcMeidaType type, int x, int y, int w, int h);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg HRESULT OnCallBackMsg(WPARAM data, LPARAM lp);
	afx_msg void OnBnClickedButtonJoin();

private:
	void OnJoinRoomHandler(std::string jsonmsg);
	void OnReJoinFailHandler(std::string jsonmsg);
	void OnReJoinRoomHandler(std::string jsonmsg);
	void OnLeaveRoomHandler(std::string jsonmsg);
	void OnPulibshStreamHandler(std::string jsonmsg);
	void OnPulibshCamStreamHandler(std::string jsonmsg);
	void OnPulibshScreenStreamHandler(std::string jsonmsg);
	void OnUnPulibshStreamHandler(std::string jsonmsg);
	void OnUnPulibshStreamScreenHandler(std::string jsonmsg);
	void OnUnPulibshStreamCamHandler(std::string jsonmsg);
	void OnSubStreamHandler(std::string jsonmsg);
	void OnUnSubStreamHandler(std::string jsonmsg);
	void OnStreamStHandler(std::string jsonmsg);
	void OnUserStHandler(std::string jsonmsg);
	void OnServerReconnectingHandler(std::string jsonmsg);
	void OnServerDisconnectHandler(std::string jsonmsg);

	void OnSdkErrorHandler(std::string jsonmsg);
	void OnKickoffHandler(std::string jsonmsg);

	void OnLocalStreamMuteHandler(std::string jsonmsg);
	void OnRemoteStreamMuteHandler(std::string jsonmsg);
	void OnRemoteTrackStNotify(std::string jsonmsg);

	void OnRemoteAudioVolHandler(std::string jsonmsg);
	void OnLocalAudioVolHandler(std::string jsonmsg);

	void OnRemoteStHandler(std::string jsonmsg);
	void OnSendStHandler(std::string jsonmsg);

	// �û��뿪 �ͷ�������Դ
	void ReleaseUserAllRes();
	void SubscribeAllStream();
	void SubscribeStream(int mediatype, std::string uid);
	void UnSubscribeStream(int mediatype, std::string uid);
	void UserLeave(std::string uid);
	void OnLeaveRoom();
	void OnMessageShow(std::string msg);

public:
	afx_msg void OnBnClickedButtonPubC();
	afx_msg void OnBnClickedButtonLeaveroom();
	afx_msg void OnBnClickedButtonPubs();
	afx_msg void OnBnClickedButtonDeviceTest();
	CListBox m_msglist;
	CButton m_videocheck;
	CButton m_audiocheck;
	// ʧ����������
	int m_maxretrynum;
	int m_nowretry;  
	std::string m_roomtoken;
	UCloudRtcEngine* m_rtcengine;
};
