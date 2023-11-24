#include "RecoveryBullet.h"

RecoveryBullet::RecoveryBullet()
{
}

RecoveryBullet::~RecoveryBullet()
{
}

void RecoveryBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::SLIMEBULLET;
	r = 32;
	bulletSpeed = rand() % 10 - 20;
	position = pos;
}

void RecoveryBullet::Update()
{
	Move();
}

void RecoveryBullet::Draw()
{
	DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 32, bullet, TRUE, FALSE);
}

void RecoveryBullet::Resource(int bul)
{
	bullet = bul;
}

void RecoveryBullet::Animation()
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

void RecoveryBullet::Move()
{
	position.x += bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
