#include "myNewApplication.h"
#include "SceneManager.h"


namespace Nmy
{/*
	NewApplication NewApplication::mInstance;*/
	// 싱글톤 단점 메모리소멸자가 호출되지 않음

	Nmy::NewApplication::NewApplication()
	{

		mWindowdata.clear();
	}

	Nmy::NewApplication::~NewApplication()
	{
		ReleaseDC(mWindowdata.hWnd, mWindowdata.hdc);
	}

	void Nmy::NewApplication::Initialize(WindowDataA data)
	{
		mWindowdata = data;
		mWindowdata.hdc = GetDC(data.hWnd);

	}

	void Nmy::NewApplication::Tick()
	{
	}


}

