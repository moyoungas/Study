#include "ColliderManager.h"
#include "SceneManager.h"
#include "NmyCollider.h"
#include "Actor.h"
#include "NmyScene.h"

namespace Nmy
{
	WORD ColliderManager::mMatrix[_COLLIDER_LAYER] = {};


	void ColliderManager::Tick()
	{
		Scene* playScene = SceneManager::GetPlayScene();

		for (size_t row = 0; row < _COLLIDER_LAYER; row++)
		{
			for (size_t col = 0; col < _COLLIDER_LAYER; col++)
			{
				if (mMatrix[row] & (1 << col))
				{
					// �浹 �Ǿ��ִ� �� Ȯ��
					LayerCollision(playScene
						, (eColliderLayer)row, (eColliderLayer)col);
				}
			}
		}
	}

	void ColliderManager::SetLayer(eColliderLayer left, eColliderLayer right, bool value)
	{

		// �� ���� ���ڸ� ������ ��� �� ū ���ڸ� ���� 
		// �� ���� �ݸ� ����ϰڴ� �׷��� ū ���ڸ� ���� ������Ų��.
		UINT row = 0;
		UINT col = 0;

		UINT iLeft = (UINT)left;
		UINT iRight = (UINT)right;

		if (iLeft < iRight)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		if (value == true)
			mMatrix[row] != (1 << col);
		else
			mMatrix[row] &= ~(1 << col);
	}

	void ColliderManager::LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right)
	{

		// ��� left , right ������Ʈ���� ������ ��������Ѵ�.

		std::vector<Actor*>& lefts = scene->GetActor(left);
		std::vector<Actor*>& rights = scene->GetActor(right);

		for (auto leftActor : lefts)
		{

			if (leftActor->GetComponent<Collider>() == nullptr)
				continue;

			for (auto rightActor : rights)
			{

				if (rightActor->GetComponent<Collider>() == nullptr)
					continue;


				if (leftActor == rightActor)
					continue;

				// �浹 üũ
				if (Intersect(leftActor->GetComponent<Collider>()
					, rightActor->GetComponent<Collider>()))
				{
					//�浹

				}
				else
				{
					//�浹x

				}



			}
		}

	}

	bool ColliderManager::Intersect(Collider* left, Collider* right)
	{

		Vector2 leftPos = left->GetPos();
		Vector2 leftScale = left->GetScale();

		Vector2 rightPos = right->GetPos();
		Vector2 rightScale = right->GetScale();

		if (fabs(leftPos.x - rightPos.x) < fabs(leftScale.x / 2.0f + rightScale.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs(fabs(leftScale.y / 2.0f + rightScale.y / 2.0f)) )
		{
			return true;
		}

		return false;

	}

}