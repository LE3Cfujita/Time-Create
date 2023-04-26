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
	r = 128;
	enemy= LoadGraph("Resource/Enemy.png"); // •`‰æ
}

void Enemy::Update()
{
	if (move == true)
	{
		Move();
	}
	Attack();
}

void Enemy::Draw()
{
	DrawExtendGraph(position.x - r-16, position.y - r, position.x + r, position.y + r, enemy, TRUE);
}

void Enemy::Attack()
{

	if (timeFlag == false)
	{
		//int rad = rand() % 2;
		//if (rad == 1)
		//{
		//	BulletAttack();//’e
		//}
		//else
		//{
		//	FireAttack();
		//}
		BulletAttack();//’e
		FireAttack();//‰Î
		move = false;
	}
	else
	{
		time++;
		if (time <= 60)return;
		move = true;
		if (time <= 180)return;
		timeFlag = false;
		time = 0;
	}
}

void Enemy::Move()
{
	if (position.y-r <= 0)
	{
		moveCount = 1;
	}
	if (position.y+r >= 720)
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
	for (int i = 0; i < 3; i++)
	{
		EnemyBullet* bullet = new EnemyBullet();
		bullet->BaseInitialize(referenceGameObjects);
		bullet->Initialize(position, i);
		addGameObjects.push_back(bullet);
		timeFlag = true;
	}

}

void Enemy::FireAttack()
{
	/*	for (int i = 0; i < 2; i++)
		{*/
	EnemyFire* bullet = new EnemyFire();
	bullet->BaseInitialize(referenceGameObjects);
	bullet->Initialize(position, 1);
	addGameObjects.push_back(bullet);
	timeFlag = true;
	//}
}

void Enemy::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMenber() == OBJECTMEMBER::PLAYERBULLET)
	{
		//deathFlag = true;
		gameObject->SetDeathFlag(true);
	}
}
