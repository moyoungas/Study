#pragma once
#include "NCommon.h"
#include "NmyEntity.h"
#include "NmyComponent.h"

namespace Nmy
{

	class Actor : public Entity
	{
	public:
		Actor();
		virtual ~Actor();


		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 pos) { mScale = pos; }
		Vector2 GetScale() { return mScale; }
		// 스케일에 따라 크기를 다르게 그릴것

		void AddComponent(Component* component);



	private:
		std::vector<Component*> mComponents;

		Vector2 mPos;
		Vector2 mScale;
		
	};


}

