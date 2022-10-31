#pragma once
#include "Actor.h"

namespace Nmy
{
	class image;

	class Monster : public Actor
	{
	public:
		Monster();
		virtual ~Monster();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		image* pImage;
	};



}
