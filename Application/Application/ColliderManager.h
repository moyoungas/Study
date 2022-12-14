#pragma once
#include "NCommon.h"



namespace Nmy
{
	class Scene;
	class Collider;

	class ColliderManager
	{
	public:


		static void Tick();
		static void SetLayer(eColliderLayer left, eColliderLayer right, bool value);
		static void LayerCollision(Scene* scene , eColliderLayer left, eColliderLayer right);
		static bool Intersect(Collider* left, Collider* right);

	private:
		
		static WORD mMatrix[_COLLIDER_LAYER];


	};



}