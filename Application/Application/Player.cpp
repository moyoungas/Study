#include "Player.h"
#include "Time.h"
#include "NmyInput.h"
#include "Missile.h"
#include "SceneManager.h"
#include "NmyScene.h"

Nmy::Player::Player() 
	: mSpeed(1.0f)
{
	SetPos({ 100.0f, 100.0f });
	SetScale({ 100.0f, 100.0f });
}

Nmy::Player::~Player()
{
}

void Nmy::Player::Tick()
{
	Vector2 pos = GetPos();

	if (KEY_PRESSED(eKeyCode::W))
	{
		pos.y -= 200.0f * Time::DeltaTime();
	}
	if (KEY_PRESSED(eKeyCode::S))
	{
		pos.y += 200.0f * Time::DeltaTime();
	}
	if (KEY_PRESSED(eKeyCode::A))
	{
		pos.x -= 200.0f * Time::DeltaTime();
	}
	if (KEY_PRESSED(eKeyCode::D))
	{
		pos.x += 200.0f * Time::DeltaTime();
	}

	if (KEY_DOWN(eKeyCode::F))
	{
		Missile* missile = new Missile();
		Scene* playScene = SceneManager::GetPlayScene();

		playScene->AddGameActor(missile);

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale() / 2.0f;

		Vector2 missileScale = missile->GetScale();

		missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));

	}

	SetPos(pos);

}

void Nmy::Player::Render(HDC hdc)
{
	Vector2 pos = GetPos();
	Vector2 mScale = GetScale();


	Rectangle(hdc, pos.x, pos.y, pos.x + mScale.x, pos.y + mScale.y);

}
