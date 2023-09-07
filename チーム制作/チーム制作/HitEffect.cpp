#include "HitEffect.h"

HitEffect::HitEffect()
{
}

HitEffect::~HitEffect()
{
}

void HitEffect::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMY;
	for (GameObject* gameObject : referenceGameObjects)
	{
		if (gameObject->GetObjectMember() != GameObject::ENEMY)continue;
		objectStage = gameObject->GetObjectAge();
	}
	position = pos;
	r = 16;
	effect1= LoadGraph("Resource/hitEfectt1.png");
	effect2= LoadGraph("Resource/hitEfectt2.png");
	effect3= LoadGraph("Resource/hitEfectt3.png");
}

void HitEffect::Update()
{
}

void HitEffect::Draw()
{
	animation = animation + 1;

	if (animation > 5)
	{
		animeCount = animeCount + 1;
		animation = 0;
		if (animeCount >= 5)
		{
			timeFlag = true;
			move = false;
			animeCount = 0;
			deathFlag = true;
		}
	}

	if (objectStage == FIRSTSTAGE)
	{
		DrawRectGraph(position.x - r, position.y - r, animeCount * 32, 0, 32, 32, effect1, TRUE, FALSE);
	}
}
