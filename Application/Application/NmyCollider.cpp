#include "NmyCollider.h"
#include "Actor.h"
#include "myNewApplication.h"

namespace Nmy
{



	Collider::Collider()
		: Component(eComponentType::Collider)
		, mOffset(Vector2::Zero)
		, mPos(Vector2::Zero)
		, mScale(Vector2::One)
	{
		mScale = Vector2(100.0f, 100.0f);
	}

	Collider::~Collider()
	{
	}

	void Collider::Tick()
	{
		Actor* owner = GetOwner();
		// ���� �������� ���������� �Ÿ��� �����Ͽ���
		mPos = owner->GetPos() + mOffset;

	}

	void Collider::Render(HDC hdc)
	{
		HBRUSH gray = NewApplication::Getinstance().GetBrush(eBrushColor::Transparent);
		Brush brush(hdc, gray);

		HPEN green = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		Pen pen(hdc,green);


		// �������� ���̷� �����
		Rectangle(hdc, mPos.x - (mScale.x / 2.0f)
			, mPos.y - (mScale.y / 2.0f)
			, mPos.x + (mScale.x / 2.0f)
			, mPos.y + (mScale.y / 2.0f));
	}

}