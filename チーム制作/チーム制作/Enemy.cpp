#include "Enemy.h"
#include "EnemyBullet.h"

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
	color= GetColor(255, 255, 255);
}

void Enemy::Update()
{
	Attack();
}

void Enemy::Draw()
{
	DrawCircle(position.x, position.y, r, color, true);
}

void Enemy::Move()
{
}

void Enemy::Attack()
{
	if (timeFlag == false)
	{
			EnemyBullet* bullet = new EnemyBullet();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize(position);
			addGameObjects.push_back(bullet);
			timeFlag = true;
	}
	else
	{
		time++;
		if (time <= 10)return;
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
