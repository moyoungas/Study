#include "DropManager.h"
#include "Drop.h"
#include "SceneManager.h"

namespace Nmy
{

	Drop* DropManager::drop = nullptr;

	void DropManager::Initialize()
	{
		Drop* mDrop = new Drop[(UINT)10];
		Scene* playScene = SceneManager::GetPlayScene();

		for (size_t i = 0; i < 10; i++)
		{
			playScene->AddGameActor(mDrop);
		}
	}

	void DropManager::Tick()
	{
		drop->Tick();
	}

	void DropManager::Render(HDC hdc)
	{
		drop->Render(hdc);
	}

	void DropManager::Release()
	{


	}

}