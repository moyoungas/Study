#include "Drop.h"
#include "Time.h"

namespace Nmy
{
	Drop::Drop()
		: mSpeed(1.0f)
	{
		SetPos({ 10.0f , 10.0f });
		SetScale({ 50.0f,50.0f });
	}

	Drop::~Drop()
	{

	}


	void Drop::Tick()
	{
		Vector2 pos = GetPos();
		pos.y += 150 * Time::DeltaTime();
		SetPos(pos);
	}

	void Drop::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		Ellipse(hdc, pos.x, pos.y, pos.x + mScale.x, pos.y + mScale.y);
	}

}

