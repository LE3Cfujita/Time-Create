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
	position = { 1000,400 };
	r = 32;
	color = GetColor(255, 255, 255);
}

void Enemy::Update()
{
	BulletAttack();//’e
	FireAttack();
}

void Enemy::Draw()
{
	DrawCircle(position.x, position.y, r, color, true);
}

void Enemy::Move()
{
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
	if (fireFlag == false)
	{
		EnemyFire* bullet = new EnemyFire();
		bullet->BaseInitialize(referenceGameObjects);
		bullet->Initialize(position);
		addGameObjects.push_back(bullet);
		fireFlag = true;
	}
	else
	{
		fireTime++;
		if (fireTime <= 5)return;
		fireFlag = false;
		fireTime = 0;
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
