#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	objectMember = GameObject::ENEMY;
	objectAge = GameObject::ANCIENT;
	objState = GameObject::IDLE;
	position = { 1000,600 };
	r = 32;
	color = GetColor(255, 255, 255);
}

void Enemy::Update()
{
	Attack();
}

void Enemy::Draw()
{
	DrawCircle(position.x, position.y, r, color, true);
}

void Enemy::Attack()
{
	
	BulletAttack();//’e
	FireAttack();
}

void Enemy::Move()
{
	if (position.y <= 64)
	{
		moveCount = 1;
	}
	if (position.y >= 654)
	{
		moveCount = 0;
	}
	if (moveCount == 0)
	{
		position.y -= 3;
	}
	else
	{
		position.y += 3;
	}
}

void Enemy::BulletAttack()
{
	if (timeFlag == false)
	{
		for (int i = 0; i < 3; i++)
		{
			EnemyBullet* bullet = new EnemyBullet();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize(position, i);
			addGameObjects.push_back(bullet);
			timeFlag = true;
		}
	}
	else
	{
		time++;
		if (time <= 60)return;
		timeFlag = false;
		time = 0;
	}
}

void Enemy::FireAttack()
{
	if (timeFlag == false)
	{
	/*	for (int i = 0; i < 2; i++)
		{*/
			EnemyFire* bullet = new EnemyFire();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize(position,1);
			addGameObjects.push_back(bullet);
			timeFlag = true;
		//}
	}
	else
	{
		time++;
		if (time <= 60)return;
		timeFlag = false;
		time = 0;
	}
}

void Enemy::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMenber() == OBJECTMEMBER::PLAYERBULLET)
	{
		deathFlag = true;
		gameObject->SetDeathFlag(true);
	}
}
