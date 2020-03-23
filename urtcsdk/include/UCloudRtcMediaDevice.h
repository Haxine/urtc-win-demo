#ifndef _UCLOUD_RTC_MEDIA_DEVICE_CPP_H_
#define _UCLOUD_RTC_MEDIA_DEVICE_CPP_H_
#include "UCloudRTCComDefine.h"

class  _EXPORT_API UCloudRtcAudioLevelListener
{
public:
	virtual void onMicAudioLevel(int volume) {}
};

class _EXPORT_API UCloudRtcMediaDevice {
public:
	static UCloudRtcMediaDevice *sharedInstance();
	static void destory();

	//��ʼ����Ƶģ��
	virtual int InitAudioMoudle() =0;
	//�ͷ���Ƶģ��
	virtual int UnInitAudioMoudle() = 0;
	//��ʼ����Ƶģ��
	virtual int InitVideoMoudle() = 0;
	//�ͷ���Ƶģ��
	virtual int UnInitVideoMoudle() = 0;
	//��ȡ����ͷ��Ŀ
	virtual int getCamNums() = 0;
	//��ȡ¼���豸��Ŀ
	virtual int getRecordDevNums() = 0;
	//��ȡ�����豸��Ŀ
	virtual int getPlayoutDevNums() = 0;
	//��ȡ����ͷ��Ϣ
	virtual int getVideoDevInfo(int index, tUCloudRtcDeviceInfo* info) = 0;
	//��ȡ¼���豸��Ϣ
	virtual int getRecordDevInfo(int index, tUCloudRtcDeviceInfo* info) = 0;
	//��ȡ�����豸��Ϣ
	virtual int getPlayoutDevInfo(int index, tUCloudRtcDeviceInfo* info) = 0;
	//��ȡ��ǰ����ͷ
	virtual int getCurCamDev(tUCloudRtcDeviceInfo* info) = 0;
	//��ȡ��ǰ¼���豸
	virtual int getCurRecordDev(tUCloudRtcDeviceInfo* info) = 0;
	//��ȡ��ǰ�����豸
	virtual int getCurPlayoutDev(tUCloudRtcDeviceInfo* info) = 0;
	//������Ƶ�豸��Ϣ
	virtual int setVideoDevice(tUCloudRtcDeviceInfo* info) = 0;
	//����¼���豸��Ϣ
	virtual int setRecordDevice(tUCloudRtcDeviceInfo* info) = 0;
	//���ò����豸��Ϣ
	virtual int setPlayoutDevice(tUCloudRtcDeviceInfo* info) = 0;
	//��ȡ��������
	virtual int getPlaybackDeviceVolume(int *volume) = 0;
	virtual int setPlaybackDeviceVolume(int volume) = 0;
	//��ȡ¼������
	virtual int getRecordingDeviceVolume(int *volume) = 0;
	virtual int setRecordingDeviceVolume(int volume) = 0;
	//����cam����
	virtual int startCamTest(const char deviceId[MAX_DEVICE_ID_LENGTH], 
		eUCloudRtcVideoProfile profile,
		void* hwnd) = 0;
	//ֹͣ����ͷ����
	virtual int stopCamTest() = 0;
	//����¼������
	virtual int startRecordingDeviceTest(UCloudRtcAudioLevelListener* audiolevel) = 0;
	//ֹͣ¼������
	virtual int stopRecordingDeviceTest() = 0;
	//���������豸����
	virtual int startPlaybackDeviceTest(const char* testAudioFilePath) = 0;
	//ֹͣ�����豸����
	virtual int stopPlaybackDeviceTest() = 0;
	//��������ͷCapture����
	virtual int startCaptureFrame(eUCloudRtcVideoProfile profile,
		UCloudRtcVideoFrameObserver* observer) = 0;
	//ֹͣ����ͷCapture����
	virtual int stopCaptureFrame() = 0;

protected:
	UCloudRtcMediaDevice() { }
	virtual ~UCloudRtcMediaDevice() {}
};

#endif







