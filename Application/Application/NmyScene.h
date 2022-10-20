#pragma once
#include "NCommon.h"
#include "NmyEntity.h"



namespace Nmy
{
	class Actor;

	class Scene : public Entity 
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize() = 0;
		virtual void Tick();
		virtual void Render(HDC hdc);

		void AddGameActor(Actor* actor);



	private:
		std::vector<Actor*> mActor;
	};



}

