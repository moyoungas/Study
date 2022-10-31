#include "NmyScene.h"
#include"Actor.h"


namespace Nmy
{

	Scene::Scene()
	{
		mActor.resize(_COLLIDER_LAYER);
	}

	Scene::~Scene()
	{

		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t i = 0; i < mActor[y].size(); i++)
			{
				delete mActor[y][i];
				mActor[y][i] = nullptr;
			}

		}

	}

	void Scene::Initialize()
	{

		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t i = 0; i < mActor[y].size(); i++)
			{
				if(mActor[y][i] != nullptr)
					mActor[y][i]->Initialize();
			}

		}
	}

	void Scene::Tick()
	{
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t i = 0; i < mActor[y].size(); i++)
			{
				if (mActor[y][i] != nullptr)
					mActor[y][i]->Tick();
			}

		}
	}

	void Scene::Render(HDC hdc)
	{
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t i = 0; i < mActor[y].size(); i++)
			{
				if (mActor[y][i] != nullptr)
					mActor[y][i]->Render(hdc);
			}

		}
	}

	void Scene::AddGameActor(Actor* actor, eColliderLayer type)
	{
		if (actor == nullptr)
		{
			return;
		}
		mActor[(UINT)type].push_back(actor);
	}

	void Scene::Enter()
	{
	}

	void Scene::Exit()
	{
	}


}
