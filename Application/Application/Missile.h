#pragma once
#include "NCommon.h"
#include "Actor.h"

namespace Nmy
{

	class Missile : public Actor
	{
	public:
		Missile();
		~Missile();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;



	private:
		float mSpeed;

	};



}

