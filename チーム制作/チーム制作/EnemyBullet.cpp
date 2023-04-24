
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;
	position = { pos.x,pos.y };
	r = 16;
}

void EnemyBullet::Update()
{
}

void EnemyBullet::Draw()
{
}

void EnemyBullet::Move()
{
}
