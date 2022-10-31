#include "Actor.h"
#include "NmyComponent.h"

namespace Nmy
{
	Actor::Actor() 
		: mPos{ 0.0f , 0.0f }
		, mScale{ 1.0f , 1.0f}
	{
	}

	Actor::~Actor()
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			delete component;
			component = nullptr;
		}

	}


	void Actor::Initialize()
	{
	}

	void Actor::Tick()
	{
		// ��� ������Ʈ tick�� ȣ��

		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->Tick();

		}

	}

	void Actor::Render(HDC hdc)
	{
		// ��� ������Ʈ Render�� ȣ��

		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->Render(hdc);

		}
	}

	void Actor::AddComponent(Component* component)
	{
		if (component == nullptr)
			return;

		mComponents.push_back(component);

		component->mOwner = this;


	}





}


