#include "myNewApplication.h"
#include "SceneManager.h"


namespace Nmy
{/*
	NewApplication NewApplication::mInstance;*/
	// �̱��� ���� �޸𸮼Ҹ��ڰ� ȣ����� ����

	void Nmy::NewApplication::Initialize(WindowDataA data)
	{
		mWindowdata = data;
		mWindowdata.hdc = GetDC(data.hWnd);

		SceneManager::Initialize();

	}

	void Nmy::NewApplication::Tick()
	{
		SceneManager::Tick();
		SceneManager::Render(mWindowdata.hdc);
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

}

