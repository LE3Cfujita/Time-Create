#include "EnemyFire.h"

EnemyFire::EnemyFire()
{
}

EnemyFire::~EnemyFire()
{
}

void EnemyFire::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMYFIRE;
	objectAge = GameObject::ANCIENT;
	position = { pos.x,pos.y };
	r = 16;
	color = GetColor(255, 0, 0);
}

void EnemyFire::Update()
{
	Move();
}

void EnemyFire::Draw()
{
	DrawCircle(position.x, position.y, r, color, true);
}

void EnemyFire::Move()
{
	position.x -= 10;
	if (position.x >= 1300)
	{
		deathFlag = true;
	}
}
