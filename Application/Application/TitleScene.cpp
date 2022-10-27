#include "TitleScene.h"
#include "MyResources.h"


namespace Nmy
{

	TitleScene::TitleScene()
	{
		


	}

	TitleScene::~TitleScene()
	{


	}


	void TitleScene::Initialize()
	{

		if (mimage == nullptr)
		{
			mimage = Resources::Load<image>(L"Title", L"..\\Resource\\Title\\mainScreen.bmp");
		}

	}

	void TitleScene::Tick()
	{
		Scene::Tick();

		//if (_kbhit())
		//{
		//	char input = _getch();

		//	if (input == '\r')
		//	{

		//		NewApplication::Getinstance().SetPlaySceneNumber((UINT)eSceneType::Logo);
		//	}

		//}

	}

	void TitleScene::Render(HDC hdc)
	{

		BitBlt(hdc, 0, 0
			, mimage->GetWidth(), mimage->GetHeight()
			, mimage->GetDc(), 0, 0, SRCCOPY);


		Scene::Render(hdc);
	}





}


