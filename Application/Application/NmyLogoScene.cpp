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
	// ������Ʈ tick�� ȣ��
	// �θ���� ȣ���ϰ� �ڱ���� �۾�����
	// ����Ƽ���� ���Ƶ�
	Scene::Tick();




}

void Nmy::LogoScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
