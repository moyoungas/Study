#pragma once
#include "Actor.h"

namespace Nmy
{

	class Player : public Actor
	{
	public:
		Player();
		~Player();
		
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;



	private:
		float mSpeed;

	};



}


