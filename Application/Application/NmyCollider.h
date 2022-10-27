#pragma once
#include "NmyComponent.h"

namespace Nmy
{

	class Collider : public Component
	{
	public:

		Collider();
		~Collider();

		virtual void Tick() override;

	private:

	};


}
