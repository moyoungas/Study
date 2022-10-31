#pragma once
#include "NmyScene.h"
#include "NCommon.h"

namespace Nmy
{
	class Scene;

	class SceneManager
	{
	public:

		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static void Release();

		static Scene* GetPlayScene() { return mPlayScene; }
		static void ChangeScene(eSceneType aType);

	private:
		static Scene* mScene[(UINT)eSceneType::MAX];
		static Scene* mPlayScene;

	};


}
