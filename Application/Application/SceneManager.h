#pragma once
#include "NmyScene.h"
#include "NCommon.h"

namespace Nmy
{

	class SceneManager
	{
	public:

		void Initialize();
		void Tick();
		void Render(HDC hdc);

	private:

		Scene* mScene[(UINT)eSceneType::MAX];

	};


}
