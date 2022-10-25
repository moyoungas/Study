#include "myNewApplication.h"
#include "SceneManager.h"
#include "Time.h"
#include "NmyInput.h"
#include "DropManager.h"

namespace Nmy
{/*
	NewApplication NewApplication::mInstance;*/
	// �̱��� ���� �޸𸮼Ҹ��ڰ� ȣ����� ����

	void Nmy::NewApplication::Initialize(WindowDataA data)
	{
		initializeWindow(data);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
		DropManager::Initialize();
	}

	void Nmy::NewApplication::Tick()
	{
		Time::Tick();
		Input::Tick();

		// clear
		Rectangle(mWindowdata.backBuffer,
			-1, -1, mWindowdata.width + 1, mWindowdata.height + 1);

		SceneManager::Tick();
		SceneManager::Render(mWindowdata.backBuffer);

		Input::Render(mWindowdata.backBuffer);
		Time::Render(mWindowdata.backBuffer);

		DropManager::Tick();
		DropManager::Render(mWindowdata.backBuffer);
		// BitBlt �Լ��� dc���� �̹����� �������ִ� �Լ�
		BitBlt(mWindowdata.hdc, 0, 0, mWindowdata.width, mWindowdata.height
			,mWindowdata.backBuffer, 0,0, SRCCOPY);

	}

	Nmy::NewApplication::NewApplication()
	{
		mWindowdata.clear();
	}

	Nmy::NewApplication::~NewApplication()
	{
		SceneManager::Release();
		ReleaseDC(mWindowdata.hWnd, mWindowdata.hdc);
	}

	void NewApplication::initializeWindow(WindowDataA data)
	{
		mWindowdata = data;
		mWindowdata.hdc = GetDC(data.hWnd);

		// ��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�� ���
		RECT rect = { 0, 0, mWindowdata.width, mWindowdata.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// ������ ũ�� ����
		SetWindowPos(mWindowdata.hWnd, nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top, 0
		);

		ShowWindow(mWindowdata.hWnd, true);

		mWindowdata.backTexture 
			= CreateCompatibleBitmap(mWindowdata.hdc, mWindowdata.width, mWindowdata.height);

		mWindowdata.backBuffer
			= CreateCompatibleDC(mWindowdata.hdc);

		HBITMAP defalutBitmap 
			= (HBITMAP)SelectObject(mWindowdata.backBuffer, mWindowdata.backTexture);

		DeleteObject(defalutBitmap);
	}

}

