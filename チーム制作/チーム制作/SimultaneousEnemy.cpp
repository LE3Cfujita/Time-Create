#include "SimultaneousEnemy.h"

SimultaneousEnemy::SimultaneousEnemy()
{
}

SimultaneousEnemy::~SimultaneousEnemy()
{
}

void SimultaneousEnemy::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::RECOVERYENEMY;
	HP = 20;
	r = 32;
	simultaneous = LoadGraph("Resource/Playeranime.png");
	position = pos;
	position.y = position.y * number;
	moveNumber = number;
	speed = rand() % 5 + 5;
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

void SimultaneousEnemy::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		//PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
		HP--;
		gameObject->SetDeathFlag(true);
	}
}

void SimultaneousEnemy::Move()
{
	if (HP <= 0)
	{
		time++;
		objState = TENTATIVE;
	}
	else
	{
		if (moveNumber == 1)
		{
			if (position.y <= 16)moveFlag = true;//trueだったら下移動
			if (position.y >= 360)moveFlag = false;//falseだったら上移動
		}
		else
		{
			if (position.y <= 360)moveFlag = true;//trueだったら下移動
			if (position.y >= 702 - 16)moveFlag = false;//falseだったら上移動
		}
		if (moveFlag == true)position.y += speed;
		else position.y -= speed;
	}

	if (time >= 240)
	{
		objState = IDLE;
		HP = 20;
		time = 0;
	}
}

void SimultaneousEnemy::Attack()
{
}
