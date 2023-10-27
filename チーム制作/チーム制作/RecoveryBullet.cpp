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
	DrawGraph(position.x, position.y, bullet, TRUE);
}

void RecoveryBullet::Resource(int bul)
{
	bullet = bul;
}

void RecoveryBullet::Move()
{
	position.x += bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
