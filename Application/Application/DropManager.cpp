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
		// ���α׷��� ����� �� �ѹ��� ȣ��
		delete mdrop;
	}

}