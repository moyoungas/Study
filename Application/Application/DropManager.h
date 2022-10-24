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

		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static void Release();

		static Scene* GetPlayScene() { return mPlayScene; }

	private:
		static Scene* mScene[(UINT)eSceneType::MAX];
		static Drop* drop;
		static Scene* mPlayScene;

	};
}