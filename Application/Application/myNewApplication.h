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

			static NewApplication mInstance;
			return mInstance;
		}

		void Initialize(WindowDataA data);
		void Tick();


	private:
		NewApplication();
		~NewApplication();



	private:
		WindowDataA mWindowdata;

	};

}


