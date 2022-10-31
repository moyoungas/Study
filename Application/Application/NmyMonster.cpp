
#include "NmyMonster.h"
#include "NmyScene.h"
#include "Nmyimage.h"
#include "MyResources.h"
#include "NmyAnimator.h"
#include "NmyCollider.h"


namespace Nmy
{


	Monster::Monster()
	{
		SetPos({ 1600 / 2, 900 / 2 });
		SetScale({ 3.0f, 3.0f });

		if (pImage == nullptr)
		{

			// 여기서 경로 입력시 이 파일이 있는 경로에 로드를 함
			// 그러므로 ..을 붙여 앞폴더로 나간 뒤 
			pImage = Resources::Load<image>(L"Monster", L"..\\Resource\\Image\\Monster.bmp");
		}

		AddComponent(new Animator());
		AddComponent(new Collider());
	}

	Monster::~Monster()
	{
	}

	void Monster::Initialize()
	{
	}

	void Monster::Tick()
	{

		Actor::Tick();

		Vector2 pos = GetPos();


		SetPos(pos);
	}

	void Monster::Render(HDC hdc)
	{

		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		Vector2 finalPos;
		finalPos.x = pos.x - (pImage->GetWidth() * (mScale.x / 2.0f));
		finalPos.y = pos.y - (pImage->GetHeight() * (mScale.x / 2.0f));

		Vector2 rect;
		rect.x = pImage->GetWidth() * mScale.x;
		rect.y = pImage->GetHeight() * mScale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y
			, rect.x, rect.y, pImage->GetDc()
			, 0, 0, pImage->GetWidth(), pImage->GetHeight()
			, RGB(255, 0, 255));

		Actor::Render(hdc);
	}

}