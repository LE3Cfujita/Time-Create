#include "EnemyCannon.h"

EnemyCannon::EnemyCannon()
{
}

EnemyCannon::~EnemyCannon()
{
}

void EnemyCannon::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::ENEMYCANNON;
	position = { pos.x,pos.y - 32 };
	r = 64;
	bullet = LoadGraph("Resource/EnemyFire.png"); // •`‰æ
	bulletSpeed = rand() % 5 - 3;
}

void EnemyCannon::Update()
{
	Move();
}

void EnemyCannon::Draw()
{
	DrawGraph(position.x, position.y, bullet, true);
}

void EnemyCannon::Move()
{
}
