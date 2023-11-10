#include "SimultaneousEnemy.h"

SimultaneousEnemy::SimultaneousEnemy()
{
}

SimultaneousEnemy::~SimultaneousEnemy()
{
}

void SimultaneousEnemy::Initialize(XMFLOAT2 pos,int number)
{
	objectMember = GameObject::RECOVERYENEMY;
	HP = 20;
	r = 32;
	simultaneous = LoadGraph("Resource/Playeranime.png");
	position = pos;
	position.y = position.y * number;
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
		if (position.y <= 16)moveFlag = true;//true‚¾‚Á‚½‚ç‰ºˆÚ“®
		if (position.y >= 704)moveFlag = false;//false‚¾‚Á‚½‚çãˆÚ“®
		if (moveFlag == true)position.y += 5;
		else position.y -= 5;
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
