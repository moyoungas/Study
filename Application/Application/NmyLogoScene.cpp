#include "NmyLogoScene.h"
#include "Player.h"
#include "NmyInput.h"
#include "SceneManager.h"
#include "NmyBGActor.h"
#include "NmyMonster.h"
#include "ColliderManager.h"

Nmy::LogoScene::LogoScene()
{
}

Nmy::LogoScene::~LogoScene()
{
}

void Nmy::LogoScene::Initialize()
{


	//BGActor* bg = new BGActor();
	//bg->SetImage(L"LogoBG", L"LogoBG.bmp");
	//bg->Initialize();

	//AddGameActor(bg);

	AddGameActor(new Player(), eColliderLayer::Player);
	AddGameActor(new Monster(), eColliderLayer::Monster);
	ColliderManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player, true);
}

void Nmy::LogoScene::Tick()
{
	// 오브젝트 tick을 호출
	// 부모것을 호출하고 자기것을 작업하자
	// 유니티에선 막아둠
	Scene::Tick();

	if (KEY_DOWN(eKeyCode::N))
	{
		SceneManager::ChangeScene(eSceneType::Title);
	}
}

void Nmy::LogoScene::Render(HDC hdc)
{
	Scene::Render(hdc);
	wchar_t szFloat[50] = {};
 	swprintf_s(szFloat, 50, L"Logo Scene");
	int strlen = wcsnlen_s(szFloat, 50);
	TextOut(hdc, 10, 30, szFloat, strlen);
}

void Nmy::LogoScene::Enter()
{


}

void Nmy::LogoScene::Exit()
{
}
