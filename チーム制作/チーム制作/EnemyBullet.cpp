#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::ENEMYBULLET;
	position = { pos.x,pos.y };
	r = 32;
	this->number = number;
	color = GetColor(255, 0, 255);
	ancient = -10;

	bullet = LoadGraph("Resource/unkoBullet.png"); // •`‰æ
}

void EnemyBullet::Update()
{
	Move();
}

void EnemyBullet::Draw()
{
	DrawRotaGraph(position.x, position.y, 2.0, angle, bullet, TRUE);
}

void EnemyBullet::Move()
{
	angle += 0.1;
	if (number == 0)
	{
		position.x -= 5;
		position.y += ancient;
		ancient += 0.25;
	}
	else if (number == 1)
	{
		position.x -= 7;
		position.y += ancient;
		ancient += 0.25;
	}
	else
	{
		position.x -= 10;
		position.y += ancient;
		ancient += 0.25;
	}
	if (position.y >= 800)
	{
		deathFlag = true;
	}
}
