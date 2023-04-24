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
	objectAge = GameObject::ANCIENT;
	position = { pos.x,pos.y };
	r = 16;
	color = (0, 0, 255);
}

void EnemyBullet::Update()
{
	Move();
}

void EnemyBullet::Draw()
{
	DrawCircle(position.x, position.y, r, color, true);
}

void EnemyBullet::Move()
{
}
