#include "SceneManager.h"
#include "NmyLogoScene.h"
#include "TitleScene.h"


namespace Nmy
{
	Scene* SceneManager::mScene[(UINT)eSceneType::MAX] = {};
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{
		// 모든 씬들을 초기화
		mScene[(UINT)eSceneType::Logo] = new LogoScene;
	/*	mScene[(UINT)eSceneType::Title] = new TitleScene;*/
		mScene[(UINT)eSceneType::Logo]->Initialize();

		mPlayScene = mScene[(UINT)eSceneType::Logo];

		// 자식이 부모로 업캐스팅
		// 부모가 자식이 다운캐스팅
		//Scene* t = new LogoScene();
		//t->Initialize();
	}

	void SceneManager::Tick()
	{

		// 현재 씬만 업데이트
		mPlayScene->Tick();
	}

	void SceneManager::Render(HDC hdc)
	{
		// 현재씬을 렌더링
		mPlayScene->Render(hdc);

	}

	void SceneManager::Release()
	{

		// 프로그램이 종료될 때 한번만 호출
		for (Scene* scene : mScene)
		{
			if (scene == nullptr)
			{
				continue;
			}

			delete scene;
			scene = nullptr;
		}

	}

}


