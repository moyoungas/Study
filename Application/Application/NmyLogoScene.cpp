#include "NmyLogoScene.h"
#include "Player.h"

Nmy::LogoScene::LogoScene()
{
}

Nmy::LogoScene::~LogoScene()
{
}

void Nmy::LogoScene::Initialize()
{
	AddGameActor(new Player());
}

void Nmy::LogoScene::Tick()
{
	// 오브젝트 tick을 호출
	// 부모것을 호출하고 자기것을 작업하자
	// 유니티에선 막아둠
	Scene::Tick();




}

void Nmy::LogoScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
