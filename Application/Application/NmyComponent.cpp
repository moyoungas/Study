#include "NmyComponent.h"

namespace Nmy
{

	Component::Component(eComponentType type)
		: mType(type)
		, mOwner(nullptr)
	{

	}
	Component::~Component()
	{

	}
	void Component::Tick()
	{

	}
	void Component::Render(HDC hdc)
	{
	}
}