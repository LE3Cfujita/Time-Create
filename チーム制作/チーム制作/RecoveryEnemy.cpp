#include "RecoveryEnemy.h"

RecoveryEnemy::RecoveryEnemy()
{
}

RecoveryEnemy::~RecoveryEnemy()
{
}

void RecoveryEnemy::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::RECOVERYENEMY;
	HP = 50;
	r = 32;
	recovery = LoadGraph("Resource/Playeranime.png");
	position = pos;
	actionFlag = false;
}

void RecoveryEnemy::Update()
{
	if (actionFlag == false)
	{
		Spwan();
	}
	else
	{
		Move();
		Recovery();
	}
	if (HP <= 0)
	{
		objState = DEATH;
	}
}

void RecoveryEnemy::Draw()
{
	if (actionFlag == true)
	{
		DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 62, recovery, TRUE, FALSE);
	}
	else
	{
		DrawRotaGraph(position.x, position.y, size, angle, recovery, TRUE, FALSE);
	}
}

void RecoveryEnemy::Resource(int bul)
{
	this->bul = bul;
}

void RecoveryEnemy::HitAction(GameObject* gameObject)
{
	if (actionFlag != true)return;
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		//PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
		HP--;
		gameObject->SetDeathFlag(true);
	}
}

void RecoveryEnemy::Move()
{
	moveTime++;

	if (moveFlag == false)
	{
		if (moveTime >= 300)
		{
			moveFlag = true;
			moveTime = 0;
			RecoveryItem* item = new RecoveryItem;
			item->BaseInitialize(referenceGameObjects);
			item->Initialize({ position });
			addGameObjects.push_back(item);
		}
		Attack();
		if (position.y <= 16)topFlag = true;//true‚¾‚Á‚½‚ç‰ºˆÚ“®
		if (position.y >= 704)topFlag = false;//false‚¾‚Á‚½‚çãˆÚ“®
		if (topFlag == true)position.y += 3;
		else position.y -= 3;
	}
	else
	{
		if (moveTime >= 300)
		{
			moveFlag = false;
			moveTime = 0;
		}
	}
}

void RecoveryEnemy::Recovery()
{
	time++;
	if (time >= 30)
	{
		HP += 2;
		time = 0;
	}
}

void RecoveryEnemy::Attack()
{
	if (attackFlag == false)
	{
		RecoveryBullet* bullet = new RecoveryBullet();
		bullet->BaseInitialize(referenceGameObjects);
		bullet->Initialize(position);
		bullet->Resource(bul);
		addGameObjects.push_back(bullet);
		attackFlag = true;
	}
	else
	{
		attackTime++;
		if (attackTime > 5)
		{
			attackFlag = false;
			attackTime = 0;
		}
	}
}

void RecoveryEnemy::Spwan()
{
	if (size < 1)
	{
		angle += 0.5;
		size += 0.02;
	}
	else
	{
		actionFlag = true;
	}
}
