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
		mWindowdata = data;
		mWindowdata.hdc = GetDC(data.hWnd);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
		DropManager::Initialize();
	}

	void Nmy::NewApplication::Tick()
	{
		Time::Tick();
		Input::Tick();

		SceneManager::Tick();
		DropManager::Tick();
		DropManager::Render(mWindowdata.hdc);
		SceneManager::Render(mWindowdata.hdc);
		Input::Render(mWindowdata.hdc);
		Time::Render(mWindowdata.hdc);

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

