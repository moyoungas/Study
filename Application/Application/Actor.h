#pragma once
#include "NCommon.h"
#include "NmyEntity.h"

namespace Nmy
{
	class Actor : public Entity
	{
	public:
		Actor();
		~Actor();


		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 pos) { mScale = pos; }
		Vector2 GetScale() { return mScale; }
		// �����Ͽ� ���� ũ�⸦ �ٸ��� �׸���





	private:
		Vector2 mPos;
		Vector2 mScale;
		
	};


}

