#pragma once

#include "NCommon.h"
#include "NmyScene.h"
#include "Nmyimage.h"

namespace Nmy
{

	// ���� ���α׷��� �� �༮
	class NewApplication
	{
	public:
		static NewApplication& Getinstance()
		{

			static NewApplication mInstance;
			return mInstance;
		}

		WindowDataA GetWindowdata() { return mWindowdata; }

		void Initialize(WindowDataA data);
		void Tick();

		void SetPlaySceneNumber(int number) {}


	private:
		NewApplication();
		~NewApplication();

		void initializeWindow(WindowDataA data);

	private:
		WindowDataA mWindowdata;
		HPEN mPen[(UINT)ePenColor::END];
		HBRUSH mBrush[(UINT)eBrushColor::END];
	};

}


