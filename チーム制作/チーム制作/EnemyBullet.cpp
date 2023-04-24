#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMYBULLET;
	objectAge = GameObject::ANCIENT;
	position = { pos.x,pos.y };
	r = 16;
	color = GetColor(255, 0, 255);
	ancient = -10;
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
	position.x -= 5;
	position.y += ancient;
	ancient += 0.25;
	if (position.x <= -20)
	{
		deathFlag = true;
	}
}
