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
	
	bullet = LoadGraph("Resource/EnemyFire.png"); // •`‰æ


	bulletSpeed = rand() % 10 - 20 ;
}

void EnemyFire::Update()
{
	Move();
}

void EnemyFire::Draw()
{
	DrawExtendGraph(position.x - r, position.y - r, position.x + r, position.y + r, bullet, TRUE);
}

void EnemyFire::Move()
{
	position.x += bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
