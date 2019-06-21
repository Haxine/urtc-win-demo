//#pragma once
#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include <string>
#include <windows.h>
#include <vector>
#define MAX_PATH_LENGTH 1024  
#define MAX_BEAUTYFACEPARAMTER 5 
#define MAX_FACESHAPEPARAMTER 6

void resetBeautyParam();
void resetShapeParam();

enum BundleCategory 
{
	Animoji,
	ItemSticker,
	ARMask,
	ChangeFace,
	ExpressionRecognition,
	MusicFilter,
	BackgroundSegmentation,
	GestureRecognition,
	MagicMirror,
	PortraitDrive,

	Count
};
enum BundleCategoryEx
{
	Makeup = 10,
	Hair,
	ChangeFaceEx,
	ExpressionGif,
	Facebeauty,
	LightMakeup,
	Facepup,
	CountEx
};
static class UIBridge
{
public:
	static int bundleCategory;
	static int renderBundleCategory;
	static int faceType; 
	
	static bool showItemSelectWindow;
	static bool showItemTipsWindow;
	static bool showDegubInfoWindow;
	static bool showFilterSlider; 
	static bool mNeedIpcWrite; 
	static bool mNeedPlayMP3;
	static bool mNeedStopMP3;

	static uint32_t mFPS;
	static uint32_t mResolutionWidth;
	static uint32_t mResolutionHeight;
	static uint32_t mRenderTime;

	static int m_curFilterIdx;
	static int m_curRenderItem;	
	
	static int mEnableSkinDect;
	static int mEnableHeayBlur;
	static float mFaceBeautyLevel[5];
	static float mFaceShapeLevel[6];
	static float mFilterLevel[10];
	static float mMakeupLevel[10];
		
	static int mSelectedCamera;
	static double mLastTime;
	static std::string mCurRenderItemName;
	static std::vector<std::string> categoryBundles[BundleCategory::Count];

	static void UIBridge::FindAllBundle(std::string folder,std::vector<std::string> &files)
	{		
		IteratorFolder(folder.c_str(), files);
		//for each (auto file in files)
		//{
		//	std::cout << file << std::endl;
		//}
	}
	static void UIBridge::Wchar_tToString(std::string& szDst, wchar_t *wchar)
	{
		wchar_t * wText = wchar;
		DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);// WideCharToMultiByte������
		char *psText; // psTextΪchar*����ʱ���飬��Ϊ��ֵ��std::string���м����
		psText = new char[dwNum];
		WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);// WideCharToMultiByte���ٴ�����
		szDst = psText;// std::string��ֵ
		delete[]psText;// psText�����
	}
	static void UIBridge::IteratorFolder(const char* lpPath, std::vector<std::string> &fileList) {
		char szFind[MAX_PATH];
		WIN32_FIND_DATA FindFileData;
		strcpy(szFind, lpPath);
		strcat(szFind, "\\*.*");
		int len = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)szFind, -1, NULL, 0);
		wchar_t * wszUtf8 = new wchar_t[len + 1];
		memset(wszUtf8, 0, len * 2 + 2);
		MultiByteToWideChar(CP_ACP, 0, (LPCSTR)szFind, -1, (LPWSTR)wszUtf8, len);
		HANDLE hFind = ::FindFirstFileW(wszUtf8, &FindFileData);
		if (INVALID_HANDLE_VALUE == hFind)    return;
		while (true) {
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (FindFileData.cFileName[0] != '.')
				{
					char szFile[MAX_PATH];
					strcpy(szFile, lpPath);
					strcat(szFile, "\\");
					strcat(szFile, (char*)(FindFileData.cFileName));
					IteratorFolder(szFile, fileList);
				}
			}
			else
			{
				//std::cout << FindFileData.cFileName << std::endl;			
				std::string str;
				Wchar_tToString(str, FindFileData.cFileName);
				if (str.find(".bundle")!= std::string::npos)
				{
					fileList.push_back(str);
				}				
			}
			if (!FindNextFile(hFind, &FindFileData))    break;
		}
		FindClose(hFind);
	}
protected:
private:
};
const std::string g_assetDir = "../../assets/";
const std::string gBundlePath[] = {
	g_assetDir + "items/" + "Animoji",
	g_assetDir + "items/" + "ItemSticker",
	g_assetDir + "items/" + "ARMask",
	g_assetDir + "items/" + "ChangeFace",
	g_assetDir + "items/" + "ExpressionRecognition",
	g_assetDir + "items/" + "MusicFilter",
	g_assetDir + "items/" + "BackgroundSegmentation",
	g_assetDir + "items/" + "GestureRecognition",
	g_assetDir + "items/" + "MagicMirror",
	g_assetDir + "items/" + "PortraitDrive",
};
#endif