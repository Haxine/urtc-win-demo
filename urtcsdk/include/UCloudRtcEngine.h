// interfalce desc
#ifndef _UCLOUD_RTC_ENGINE_SDK_H_
#define _UCLOUD_RTC_ENGINE_SDK_H_

#include "UCloudRtcComDefine.h"

class  _EXPORT_API UCloudRtcEventListener
{
public:
	virtual void onServerDisconnect() {}
	//���뷿��ص�
	virtual void onJoinRoom(int code, const char* msg, const char* uid, const char* roomid) {}
	//�뿪����ص�
	virtual void onLeaveRoom(int code, const char* msg, const char* uid, const char* roomid) {}
	//���¼��뷿��ص�
	virtual void onRejoining(const char* uid, const char* roomid) {}
	//���¼��뷿��ɹ��ص�
	virtual void onReJoinRoom(const char* uid, const char* roomid) {}
	//�����������ص�
	virtual void onLocalPublish(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}
	//������ȡ�������ص�
	virtual void onLocalUnPublish(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}
	//Զ���û�����ص�
	virtual void onRemoteUserJoin(const char* uid) {}
	//Զ���û��뿪�ص�
	virtual void onRemoteUserLeave(const char* uid, int reson) {}
	//Զ���������ص�
	virtual void onRemotePublish(tUCloudRtcStreamInfo& info) {}
	//Զ����ȡ�������ص�
	virtual void onRemoteUnPublish(tUCloudRtcStreamInfo& info) {}
	//���Ļص�
	virtual void onSubscribeResult(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}
	//ȡ�����Ļص�
	virtual void onUnSubscribeResult(const int code, const char* msg, tUCloudRtcStreamInfo& info) {}
	//����mute�ص�
	virtual void onLocalStreamMuteRsp(const int code, const char* msg,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute) {}
	//Զ��mute�ص�
	virtual void onRemoteStreamMuteRsp(const int code, const char* msg, const char* uid,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute) {}
	//Զ����Ƶ�������Ƶ��״̬�ص�
	virtual void onRemoteTrackNotify(const char* uid,
		eUCloudRtcMeidaType mediatype, eUCloudRtcTrackType tracktype, bool mute) {}
	//����¼�ƻص�
	virtual void onStartRecord(const int code, const char* msg, tUCloudRtcRecordInfo& info) {}
	//ֹͣ¼�ƻص�
	virtual void onStopRecord(const int code, const char* msg, const char* recordid) {}
	//��������ͳ�ƻص�
	virtual void onSendRTCStats(tUCloudRtcStreamStats& rtstats) {}
	//Զ������ͳ�ƻص�
	virtual void onRemoteRTCStats(tUCloudRtcStreamStats rtstats) {}
	//Զ����Ƶ�����ص�
	virtual void onRemoteAudioLevel(const char* uid, int volume) {}
	//�������ֻص�
	virtual void onNetworkQuality(const char* uid, eUCloudRtcNetworkQuality&rtype, eUCloudRtcQualityType& Quality) {}
	//����״̬�ص�
	virtual void onRtmpStreamingStateChanged(const int 	state, const char* url, int code) {};
	//���Ƹ��»�����ص�
	virtual void onRtmpUpdateMixStreamRes(eUCloudRtmpOpration& cmd,const int code, const char* msg) {};
	//������Ƶ�����ص�
	virtual void onLocalAudioLevel(int volume) {}
	//����֪ͨ
	virtual void onKickoff(int code) {}
	//����ص�
	virtual void onWarning(int warn) {}
	//����ص�
	virtual void onError(int error) {}
};

class _EXPORT_API UCloudRtcEngine
{
public:
	//��������
	static UCloudRtcEngine *sharedInstance(bool bIsInline = true);
	//��������
	static void destroy();
	//��ȡsdk�汾
	static const char *getSdkVersion();
	//ע�����
	virtual void regRtcEventListener(UCloudRtcEventListener* listener) = 0;
	//����sdkģʽ
	virtual int setSdkMode(eUCloudRtcSdkMode mode) = 0;
	//����Ƶ�����
	virtual int setChannelType(eUCloudRtcChannelType roomtype) = 0;
	//���ý�ɫ
	virtual int setStreamRole(eUCloudRtcUserStreamRole role) = 0;
	//������־����
	virtual void setLogLevel(eUCloudRtcLogLevel level) = 0;
	//����key
	virtual void setTokenSecKey(const char* seckey) = 0;
	//�����Զ�����
	virtual int setAutoPublishSubscribe(bool autoPub, bool autoSub) = 0;
	//������Ƶ�Զ�����
	virtual int setAudioOnlyMode(bool audioOnly) = 0;
	//���ñ���
	virtual int setVideoCodec(eUCloudRtcVideoCodec codec) = 0;
	//����rtsp����
	virtual int enableExtendRtspVideocapture(eUCloudRtcMeidaType type, bool enable, const char* rtspurl) = 0;
	//�����ⲿ�ɼ���Ƶ
	virtual int enableExtendVideocapture(bool enable, UCloudRtcExtendVideoCaptureSource* videocapture) = 0;
	//�����ⲿ�ɼ���Ƶ
	virtual int enableExtendAudiocapture(bool enable, UCloudRtcExtendAudioCaptureSource* audiocapture) = 0;
	//��������
	virtual int startAudioMixing(const char* filepath, bool replace, bool loop, float musicvol) = 0;
	//ֹͣ����
	virtual int stopAudioMixing() = 0;
	//ע����Ƶ���ջص�
	virtual void regAudioFrameCallback(UCloudRtcAudioFrameCallback* callback) = 0;
	//ע���豸���֪ͨ�ص�
	virtual void regDeviceChangeCallback(UcloudRtcDeviceChanged* callback) = 0;
	//���뷿��
	virtual int joinChannel(tUCloudRtcAuth& auth) = 0;
	//�뿪����
	virtual int leaveChannel() = 0;
	//��ȡ������Ŀ
	virtual int getDesktopNums() = 0;
	//��ȡ������Ϣ
	virtual int getDesktopInfo(int pos, tUCloudRtcDeskTopInfo& info) = 0;
	//��ȡ������Ŀ
	virtual int getWindowNums() = 0;
	//��ȡ���洰����Ϣ
	virtual int getWindowInfo(int pos, tUCloudRtcDeskTopInfo& info) = 0;
	//���������������
	virtual int setUseDesktopCapture(eUCloudRtcDesktopType desktoptype) = 0;
	//�����������profile
	virtual void setDesktopProfile(eUCloudRtcScreenProfile profile) = 0;
	//��������������
	virtual void setCaptureScreenPagrams(tUCloudRtcScreenPargram& pgram) = 0;
	//���ü��뷿��ǰ�Ƿ�������ͷ
	virtual int muteCamBeforeJoin(bool mute) = 0;
	//���ü��뷿��ǰ�Ƿ�mute mic
	virtual int muteMicBeforeJoin(bool mute) = 0;
	//������Ƶ����
	virtual void setVideoProfile(eUCloudRtcVideoProfile profile, tUCloudVideoConfig& videoconfig) = 0;
	//�л�����ͷ
	virtual int switchCamera(tUCloudRtcDeviceInfo& info) = 0;
	//����
	virtual int publish(eUCloudRtcMeidaType type, bool hasvideo, bool hasaudio) = 0;
	//ȡ������
	virtual int unPublish(eUCloudRtcMeidaType type) = 0;
	//��ʼԤ��
	virtual int startPreview(tUCloudRtcVideoCanvas& view) = 0;
	//ֹͣԤ��
	virtual int stopPreview(tUCloudRtcVideoCanvas& view) = 0;
	//mute�������
	virtual int muteLocalMic(bool mute) = 0;
	//mute������Ƶ
	virtual int muteLocalVideo(bool mute, eUCloudRtcMeidaType streamtype) = 0;
	//����
	virtual int subscribe(tUCloudRtcStreamInfo& info) = 0;
	//ȡ������
	virtual int unSubscribe(tUCloudRtcStreamInfo& info) = 0;
	//����Զ����Ⱦ
	virtual int startRemoteView(tUCloudRtcVideoCanvas& view) = 0;
	//ֹͣԶ����Ⱦ
	virtual int stopRemoteView(tUCloudRtcVideoCanvas& view) = 0;
	//muteԶ����Ƶ
	virtual int muteRemoteAudio(tUCloudRtcMuteSt& info, bool mute) = 0;
	//mute Զ����Ƶ
	virtual int muteRemoteVideo(tUCloudRtcMuteSt& info, bool mute) = 0;
	//����������Ƶ����
	virtual int enableAllAudioPlay(bool enable) = 0;
	//��ʼ¼��
	virtual int startRecord(tUCloudRtcRecordConfig& recordconfig) = 0;
	//ֹͣ¼��
	virtual int stopRecord() = 0;
	//��������ͷ�Ƿ���
	virtual int configLocalCameraPublish(bool enable) = 0;
	//��������ͷ�Ƿ���
	virtual bool isLocalCameraPublishEnabled() = 0;
	//���÷������濪��
	virtual int configLocalScreenPublish(bool enable) = 0;
	//���������Ƿ���
	virtual bool isLocalScreenPublishEnabled() = 0;
	//���ñ�����Ƶ����
	virtual int configLocalAudioPublish(bool enable) = 0;
	//���ط����Ƿ��ֹ
	virtual bool isLocalAudioPublishEnabled() = 0;
	//�Ƿ��Զ�����
	virtual bool isAutoPublish() = 0;
	//�Ƿ��Զ�����
	virtual bool isAutoSubscribe() = 0;
	//�Ƿ���Ƶ
	virtual bool isAudioOnly() = 0;
	//��·����
	virtual int addPublishStreamUrl(const char* url, tUCloudRtcTranscodeConfig *config) = 0;
	//ֹͣ��·����
	virtual int removePublishStreamUrl(const char* url) = 0;
	//������·������������
	virtual int updateRtmpMixStream(eUCloudRtmpOpration cmd, tUCloudRtcRelayStream* streams,int length) = 0;
protected:
	virtual ~UCloudRtcEngine() {}
};

#endif
