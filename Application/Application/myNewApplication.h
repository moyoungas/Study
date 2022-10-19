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
			return mInstance;
		}

		NewApplication();
		~NewApplication();

		void Initialize(WindowDataA data);
		void Tick();


	private:
		static NewApplication mInstance;
		WindowDataA mWindowdata;

	};

}


