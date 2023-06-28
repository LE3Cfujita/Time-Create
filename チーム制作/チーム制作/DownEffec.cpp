#include "DownEffec.h"

DownEffec::DownEffec()
{
}

DownEffec::~DownEffec()
{
}

void DownEffec::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMY;
	for (GameObject* gameObject : referenceGameObjects)
	{
		if (gameObject->GetObjectMember() != GameObject::ENEMY)continue;
		objectAge = gameObject->GetObjectAge();
	}
	position = pos;
	r = 155;
	effect1 = LoadGraph("Resource/boss_down.png");
}

void DownEffec::Update()
{
}

void DownEffec::Draw()
{
	animation = animation + 1;
	a += 1;
	if (animation > 7)
	{
		animeCount = animeCount + 1;
		animation = 0;
		if (animeCount >= 7)
		{
			animeCount = 0;
			deathFlag = true;
			for (GameObject* gameObject : referenceGameObjects)
			{
				if (gameObject->GetObjectMember() != GameObject::ENEMY)continue;
				gameObject->SetObjectState(GameObject::OBJSTATE::DEATH);
			}
		}
	}

	DrawRectGraph(position.x - r, position.y - r, animeCount * 310, 0, 310, 310, effect1, TRUE, FALSE);
}
