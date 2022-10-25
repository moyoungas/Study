#pragma once

#include "NCommon.h"

namespace Nmy
{

	// 메인 프로그램이 될 녀석
	class NewApplication
	{
	public:
		static NewApplication& Getinstance()
		{

			static NewApplication mInstance;
			return mInstance;
		}

		void Initialize(WindowDataA data);
		void Tick();


	private:
		NewApplication();
		~NewApplication();

		void initializeWindow(WindowDataA data);

	private:
		WindowDataA mWindowdata;

	};

}


