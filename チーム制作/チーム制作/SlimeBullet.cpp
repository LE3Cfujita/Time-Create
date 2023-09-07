#include "SlimeBullet.h"

SlimeBullet::SlimeBullet()
{
}

SlimeBullet::~SlimeBullet()
{
}

void SlimeBullet::Resource()
{
	bullet = LoadGraph("Resource/SlimeEnemyBullet.png"); // •`‰æ
}

void SlimeBullet::Initialize(XMFLOAT2 pos,int number)
{
	objectMember = GameObject::SLIMEBULLET;

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
	bulletSpeed = rand() % 10 - 20 ;
	Resource();
}

void SlimeBullet::Update()
{
	Move();
}

void SlimeBullet::Draw()
{
	DrawGraph(position.x, position.y, bullet, TRUE);
}

void SlimeBullet::Move()
{
	position.x += bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
