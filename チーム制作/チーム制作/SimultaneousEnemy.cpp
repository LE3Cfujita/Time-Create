#include "SimultaneousEnemy.h"

SimultaneousEnemy::SimultaneousEnemy()
{
}

SimultaneousEnemy::~SimultaneousEnemy()
{
}

void SimultaneousEnemy::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::RECOVERYENEMY;
	HP = 20;
	r = 32;
	simultaneous = LoadGraph("Resource/Playeranime.png");
	position = pos;
}

void SimultaneousEnemy::Update()
{
	Move();
	Attack();
}

void SimultaneousEnemy::Draw()
{
	DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 62, simultaneous, TRUE, FALSE);
}

void SimultaneousEnemy::Resource(int bul)
{
	bullet = bul;
}

void SimultaneousEnemy::Move()
{
	if (HP <= 0)
	{
		time++;
	}
	else
	{
		if (position.y <= 16)moveFlag = true;//true‚¾‚Á‚½‚ç‰ºˆÚ“®
		if (position.y >= 704)moveFlag = false;//false‚¾‚Á‚½‚çãˆÚ“®
		if (moveFlag == true)position.y += 5;
		else position.y -= 5;
	}

	if (time >= 240)
	{
		HP = 20;
		time = 0;
	}
}

void SimultaneousEnemy::Attack()
{
}
