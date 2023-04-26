#include "EnemyFire.h"

EnemyFire::EnemyFire()
{
}

EnemyFire::~EnemyFire()
{
}

void EnemyFire::Initialize(XMFLOAT2 pos,int number)
{
	objectMember = GameObject::ENEMYFIRE;
	objectAge = GameObject::ANCIENT;

	r = 32;
	this->number = number;
	if (this->number == 0)
	{
		position = { pos.x,pos.y - r };
	}
	else
	{
		position = { pos.x,pos.y + r };
	}
	
	color = GetColor(255, 0, 0);


	bulletSpeed = rand() % 10 - 20 ;
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
	position.x += bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
