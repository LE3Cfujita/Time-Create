#include "EnemyBalkan.h"

EnemyBalkan::EnemyBalkan()
{
}

EnemyBalkan::~EnemyBalkan()
{
}

void EnemyBalkan::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMYBALKAN;//“Gƒoƒ‹ƒJƒ“
	position = { pos.x,pos.y - 32 };
	r = 8;
	bullet = LoadGraph("Resource/EnemyFire.png"); // •`‰æ
	bulletSpeed = rand() % 5 - 3;
}

void EnemyBalkan::Update()
{
	Move();
}

void EnemyBalkan::Draw()
{
	DrawGraph(position.x, position.y, bullet, true);
}

void EnemyBalkan::Move()
{
	position.x -= 10;
	position.y += bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
