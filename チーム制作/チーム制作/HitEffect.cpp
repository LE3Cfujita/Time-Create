#include "HitEffect.h"

HitEffect::HitEffect()
{
}

HitEffect::~HitEffect()
{
}

void HitEffect::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::HITEFFECT;
	position = pos;
	r = 32;
	effect = LoadGraph("Resource/hitEffect.png");
}

void HitEffect::Update()
{
}

void HitEffect::Draw()
{
	animation = animation + 1;

	if (animation > 3)
	{
		animeCount = animeCount + 1;
		animation = 0;
		if (animeCount >= 3)
		{
			animeCount = 0;
			deathFlag = true;
		}
	}
	DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 64, effect, TRUE, FALSE);
}
