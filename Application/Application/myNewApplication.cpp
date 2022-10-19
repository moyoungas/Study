#include "myNewApplication.h"


namespace Nmy
{
	NewApplication NewApplication::mInstance;

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

