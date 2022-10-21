#include "myNewApplication.h"
#include "SceneManager.h"
#include "Time.h"
#include "NmyInput.h"

namespace Nmy
{/*
	NewApplication NewApplication::mInstance;*/
	// 싱글톤 단점 메모리소멸자가 호출되지 않음

	void Nmy::NewApplication::Initialize(WindowDataA data)
	{
		mWindowdata = data;
		mWindowdata.hdc = GetDC(data.hWnd);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Nmy::NewApplication::Tick()
	{
		Time::Tick();
		Input::Tick();
		SceneManager::Tick();
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

