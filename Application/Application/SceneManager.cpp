#include "SceneManager.h"
#include "NmyLogoScene.h"
#include "TitleScene.h"


namespace Nmy
{
	Scene* SceneManager::mScene[(UINT)eSceneType::MAX] = {};
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{
		// ��� ������ �ʱ�ȭ
		mScene[(UINT)eSceneType::Logo] = new LogoScene;
	/*	mScene[(UINT)eSceneType::Title] = new TitleScene;*/
		mScene[(UINT)eSceneType::Logo]->Initialize();

		mPlayScene = mScene[(UINT)eSceneType::Logo];

		// �ڽ��� �θ�� ��ĳ����
		// �θ� �ڽ��� �ٿ�ĳ����
		//Scene* t = new LogoScene();
		//t->Initialize();
	}

	void SceneManager::Tick()
	{

		// ���� ���� ������Ʈ
		mPlayScene->Tick();
	}

	void SceneManager::Render(HDC hdc)
	{
		// ������� ������
		mPlayScene->Render(hdc);

	}

	void SceneManager::Release()
	{

		// ���α׷��� ����� �� �ѹ��� ȣ��
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


