#pragma once

#include "NCommon.h"

namespace Nmy
{

	// ���� ���α׷��� �� �༮
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


