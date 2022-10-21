#include "Player.h"

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

	if (GetAsyncKeyState('W') & 0x8000)
	{
		pos.y -= 0.01f;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		pos.x -= 0.01f;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		pos.y += 0.01f;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		pos.x += 0.01f;
	}
	SetPos(pos);

}

void Nmy::Player::Render(HDC hdc)
{
	Vector2 pos = GetPos();
	Vector2 mScale = GetScale();


	Rectangle(hdc, pos.x, pos.y, pos.x + mScale.x, pos.y + mScale.y);

}
