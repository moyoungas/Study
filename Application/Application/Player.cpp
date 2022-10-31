#include "Player.h"
#include "Time.h"
#include "NmyInput.h"
#include "SceneManager.h"
#include "Missile.h"
#include "NmyScene.h"
#include "Nmyimage.h"
#include "MyResources.h"
#include "NmyAnimator.h"
#include "NmyCollider.h"

Nmy::Player::Player() 
	: mSpeed(1.0f)
{
	SetPos({ 100.0f, 100.0f });
	SetScale({ 3.0f, 3.0f });

	if (pImage == nullptr)
	{
		
		// ���⼭ ��� �Է½� �� ������ �ִ� ��ο� �ε带 ��
		// �׷��Ƿ� ..�� �ٿ� �������� ���� �� 
		pImage = Resources::Load<image>(L"Player", L"..\\Resource\\Image\\Player.bmp");
	}

	AddComponent(new Animator());
	AddComponent(new Collider());
}

Nmy::Player::~Player()
{
}


void Nmy::Player::Tick()
{

	Actor::Tick();

	Vector2 pos = GetPos();

	if (KEY_PRESSED(eKeyCode::W))
	{
		pos.y -= 200.0f * Time::DeltaTime();
	}
	if (KEY_PRESSED(eKeyCode::S))
	{
		pos.y += 200.0f * Time::DeltaTime();
	}
	if (KEY_PRESSED(eKeyCode::A))
	{
		pos.x -= 200.0f * Time::DeltaTime();
	}
	if (KEY_PRESSED(eKeyCode::D))
	{
		pos.x += 200.0f * Time::DeltaTime();
	}

	if (KEY_DOWN(eKeyCode::SPACE))
	{
		Missile* missile = new Missile();
		Scene* playScene = SceneManager::GetPlayScene();

		playScene->AddGameActor(missile, eColliderLayer::Player_Projecttile);

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale() / 2.0f;
		Vector2 missileScale = missile->GetScale();

		missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));
	}
	SetPos(pos);
}

void Nmy::Player::Render(HDC hdc)
{
	HBRUSH skyBrush = CreateSolidBrush(RGB(153, 204, 255));
	Brush brush(hdc, skyBrush);

	HPEN redPen = CreatePen(PS_SOLID , 2, RGB(255, 0, 0));
	Pen pen(hdc, redPen);

	Vector2 pos = GetPos();
	Vector2 mScale = GetScale();

	//Rectangle(hdc, pos.x, pos.y, pos.x + mScale.x, pos.y + mScale.y);


	// �̹��� , ���� ���� �� �Ȱ��� �ε��� �� �ְ� �� �����ϰ�����
	//Resource::Load<image>();
	//Resource::Load<sound>();

	// ũ�⺯���� �ȵȴ�.
	/*BitBlt(hdc, pos.x, pos.y
		, pImage->GetWidth(), pImage->GetHeight()
		,pImage->GetDc(), 0, 0, SRCCOPY);*/


	Vector2 finalPos;
	finalPos.x = pos.x - (pImage->GetWidth() * (mScale.x / 2.0f));
	finalPos.y = pos.y - (pImage->GetHeight() * (mScale.x / 2.0f));

	Vector2 rect;
	rect.x = pImage->GetWidth() * mScale.x;
	rect.y = pImage->GetHeight() * mScale.y;

	TransparentBlt(hdc, finalPos.x, finalPos.y
		, rect.x, rect.y, pImage->GetDc()
		, 0, 0, pImage->GetWidth(),pImage->GetHeight()
		, RGB(255, 0, 255));

	Actor::Render(hdc);
}
