#pragma once
#include "NCommon.h"
#include "NmyScene.h"
#include "Drop.h"



namespace Nmy
{
	class Scene;

	class DropManager
	{
	public:
		DropManager();
		~DropManager();

		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static void Release();


	private:
		static Drop* mdrop;
		static std::list<Drop*> falldrop[5];
	};
}