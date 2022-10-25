#include "DropManager.h"
#include "Drop.h"
#include "SceneManager.h"

namespace Nmy
{
	std::list<Drop*> DropManager::falldrop[] = {};
	Drop* DropManager::mdrop = nullptr;

	DropManager::DropManager()
	{

	}
	DropManager::~DropManager()
	{


	}
	void DropManager::Initialize()
	{
		Drop* dropball = new Drop();

		mdrop = dropball;
	}

	void DropManager::Tick()
	{
			mdrop->Tick();
	}

	void DropManager::Render(HDC hdc)
	{
		mdrop->Render(hdc);
	}

	void DropManager::Release()
	{
		// 프로그램이 종료될 때 한번만 호출
		delete mdrop;
	}

}