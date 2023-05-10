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
	objState = GameObject::IDLE;
	position = { 1400,600 };
	r = 128;
	enemy = LoadGraph("Resource/Enemy.png"); // ï`âÊ
	time = 100;
	HP = 50;
	moveCount = true;
}

void Enemy::Update()
{
	if (move == true)
	{
		Move();
	}
	switch (objectAge)
	{
	case ANCIENT://å√ë„çUåÇ
		ANCIENTAttack();
		break;
	case MODERN://åªë„çUåÇ
		MODERNAttack();
		break;
	case FUTURE://ñ¢óàçUåÇ
		break;
	}
}

void Enemy::Draw()
{
	switch (objectAge)
	{
	case ANCIENT://å√ë„äG
		DrawExtendGraph(position.x - r - 16, position.y - r, position.x + r, position.y + r, enemy, TRUE);
		break;
	case MODERN://åªë„äG
		DrawExtendGraph(position.x - r - 16, position.y - r, position.x + r, position.y + r, enemy, TRUE);
		break;
	case FUTURE://ñ¢óàäG
		break;
	}
}

void Enemy::ANCIENTAttack()
{

	if (timeFlag == false)
	{
		//int rad = rand() % 2;
		//if (rad == 1)
		//{
		//	BulletAttack();//íe
		//}
		//else
		//{
		//	FireAttack();
		//}
		BulletAttack();//íe
		FireAttack();//âŒ
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

void Enemy::MODERNAttack()
{
	time++;
	if (move == false)
	{
		BalkanAttack();
		AimAttack();
		if (time <= 180)return;
		move = true;
		time = 0;
	}
	else
	{
		if (time <= rand() % 120 + 180)return;
		move = false;
		time = 0;
	}
}

void Enemy::Move()
{
	if (position.y - r <= 0)
	{
		moveCount = 1;
	}
	if (position.y + r >= 720)
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
	if (moveCount == true)
	{
		position.x -= 10;
	}
	if (position.x <= 1100)
	{
		moveCount == false;
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

void Enemy::BalkanAttack()
{
	if (balkanFlag == false)
	{
		EnemyBalkan* bullet = new EnemyBalkan();
		bullet->BaseInitialize(referenceGameObjects);
		bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
		addGameObjects.push_back(bullet);
		balkanFlag = true;
		timeFlag = true;
	}
	else
	{
		balkanTime++;
		if (balkanTime <= 5)return;
		balkanFlag = false;
		balkanTime = 0;
	}
}

void Enemy::AimAttack()
{
	if (cannonFlag == true)return;
	EnemyCannon* bullet = new EnemyCannon();
	bullet->BaseInitialize(referenceGameObjects);
	bullet->Initialize(position);
	addGameObjects.push_back(bullet);
	cannonFlag = true;
}

void Enemy::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMenber() == OBJECTMEMBER::PLAYERBULLET)
	{
		//deathFlag = true;
		gameObject->SetDeathFlag(true);
	}
}
