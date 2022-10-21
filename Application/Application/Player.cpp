#include "Player.h"
#include "Time.h"
#include "NmyInput.h"

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

	if (Input::GetKeystate(eKeyCode::W) == eKeyState::PRESSED)
	{
		pos.y -= 200.0f * Time::DeltaTime();
	}
	if (Input::GetKeystate(eKeyCode::S) == eKeyState::UP)
	{
		pos.x -= 200.0f * Time::DeltaTime();
	}
	if (Input::GetKeystate(eKeyCode::A) == eKeyState::PRESSED)
	{
		pos.y += 200.0f * Time::DeltaTime();
	}
	if (Input::GetKeystate(eKeyCode::D) == eKeyState::DOWN)
	{
		pos.x += 200.0f * Time::DeltaTime();
	}
	SetPos(pos);

}

void Nmy::Player::Render(HDC hdc)
{
	Vector2 pos = GetPos();
	Vector2 mScale = GetScale();


	Rectangle(hdc, pos.x, pos.y, pos.x + mScale.x, pos.y + mScale.y);

}
