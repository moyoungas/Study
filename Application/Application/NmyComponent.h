#pragma once
#include "NmyEntity.h"
#include "NCommon.h"

namespace Nmy
{
	class Actor;

	class Component : public Entity
	{
	public:
		friend class Actor;

		Component(eComponentType type);
		Component() = delete;
		virtual ~Component();

		virtual void Tick() = 0;
		virtual void Render(HDC hdc);

		Actor* GetOwner() { return mOwner; }

	private:
		const eComponentType mType;
		Actor* mOwner;
	};

}



