#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;//ƒvƒŒƒCƒ„[’e
	position = { pos.x,pos.y - 16 };
	r = 32;

	bullet = LoadGraph("Resource/PlayerBullet.png"); // •`‰æ
}

void PlayerBullet::Update()
{
	Move();//ˆÚ“®
	Animation();
}

void PlayerBullet::Draw()
{
	DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 32, bullet, TRUE, FALSE);
}

void PlayerBullet::HitAction(GameObject* gameObject)
{
	if (gameObject->GetActionFlag() == true)
	{
		if (gameObject->GetObjectMember() == OBJECTMEMBER::SLIME ||
			gameObject->GetObjectMember() == OBJECTMEMBER::BOSSENEMY ||
			gameObject->GetObjectMember() == OBJECTMEMBER::RECOVERYENEMY ||
			gameObject->GetObjectMember() == OBJECTMEMBER::SIMULTANEOUSENEMY)
		{
			HitEffect* effect;
			effect = new HitEffect();
			effect->BaseInitialize(referenceGameObjects);
			effect->Initialize({ position });
			addGameObjects.push_back(effect);
		}
	}
}

void PlayerBullet::Animation()
{
	animation = animation + 1;

	if (animation > 2)
	{
		animeCount = animeCount + 1;
		animation = 0;
		if (animeCount >= 2)
		{
			animeCount = 0;
		}
	}
}

void PlayerBullet::Move()
{
	position.x += 10;
	if (position.x >= 1300)
	{
		deathFlag = true;
	}
}