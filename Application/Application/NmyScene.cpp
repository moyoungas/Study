#include "NmyScene.h"
#include"Actor.h"


namespace Nmy
{

	Scene::Scene()
	{
	}

	Scene::~Scene()
	{

		for (size_t i = 0; i < mActor.size(); i++)
		{
			delete mActor[i];
			mActor[i] = nullptr;
		}

	}

	void Scene::Initialize()
	{

		for (size_t i = 0; i < mActor.size(); i++)
		{
			mActor[i]->Initialize();
		}

	}

	void Scene::Tick()
	{
		for (size_t i = 0; i < mActor.size(); i++)
		{
			mActor[i]->Tick();
		}
	}

	void Scene::Render(HDC hdc)
	{

		for (size_t i = 0; i < mActor.size(); i++)
		{
			mActor[i]->Render(hdc);
		}
	}

	void Scene::AddGameActor(Actor* actor)
	{
		if (actor == nullptr)
		{
			return;
		}
		mActor.push_back(actor);
	}


}
