#include "SlimeBullet.h"

SlimeBullet::SlimeBullet()
{
}

SlimeBullet::~SlimeBullet()
{
}

void SlimeBullet::Resource()
{
	bullet = LoadGraph("Resource/enemyBullret.png"); // •`‰æ
}

void SlimeBullet::Initialize(XMFLOAT2 pos,int number)
{
	objectMember = GameObject::SLIMEBULLET;

	r = 16;
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
	Animation();
}

void SlimeBullet::Draw()
{
	DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 32, bullet, TRUE, FALSE);
}

void SlimeBullet::Move()
{
	position.x += bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}

void SlimeBullet::Animation()
{
	animation = animation + 1;

	if (animation > 2)
	{
		animeCount = animeCount + 1;
		animation = 0;
		if (animeCount >= 2)
		{
			animeCount = 0;
		}
	}
}
