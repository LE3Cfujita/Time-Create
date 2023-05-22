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
	position = { 1400,600 };
	r = 128;
	ancientEnemy = LoadGraph("Resource/Enemy.png"); // �`��
	modernEnemy = LoadGraph("Resource/EnemyModern.png");
	prediction = LoadGraph("Resource/prediction.png");
	time = 100;
	HP = 2;
	moveFlag = true;
	timeFlag = true;
	move = true;
}

void Enemy::Update()
{
	if (move == true)
	{
		Move();
	}
	switch (objectAge)
	{
	case ANCIENT://�Ñ�U��
		ANCIENTAttack();
		break;
	case MODERN://����U��
		MODERNAttack();
		break;
	case FUTURE://�����U��
		FUTUREAttack();
		break;
	}
}

void Enemy::Draw()
{
	switch (objectAge)
	{
	case ANCIENT://�Ñ�G
		DrawExtendGraph(position.x - r - 16, position.y - r, position.x + r, position.y + r, ancientEnemy, TRUE);
		break;
	case MODERN://����G
		DrawExtendGraph(position.x - r - 16, position.y - r, position.x + r, position.y + r, modernEnemy, TRUE);
		break;
	case FUTURE://�����G
		DrawExtendGraph(position.x - r - 16, position.y - r, position.x + r, position.y + r, modernEnemy, TRUE);
		if (predictionFlag == true)
		{
			DrawGraph(position.x - 1100, position.y - 260, prediction, TRUE);
		}
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
		//	BulletAttack();//�e
		//}
		//else
		//{
		//	FireAttack();
		//}
		BulletAttack();//�e
		FireAttack();//��
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

void Enemy::FUTUREAttack()
{
	if (move == true)
	{
		beamCT++;
	}
	if (beamCT >= 300)
	{
		if (position.y >= 340 && position.y <= 380)
		{
			BeamAttack();
			move = false;
		}
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
	if (moveFlag == true)
	{
		position.x -= 5;
		move = true;
	}
	if (position.x <= 1100)
	{
		moveFlag = false;
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

void Enemy::BeamAttack()
{
	if (beamCount == true)return;
	if (beamFlag == false)
	{
		predictionFlag = true;
		predictionTime++;
		if (predictionTime < 60)return;
		beamFlag = true;
		predictionTime = 0;
	}
	else
	{
		EnemyBeam* bullet = new EnemyBeam();
		bullet->BaseInitialize(referenceGameObjects);
		bullet->Initialize(position);
		addGameObjects.push_back(bullet);
		beamCount = true;
		beamCT = 0;
	}
}

void Enemy::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		HP--;
		gameObject->SetDeathFlag(true);
	}
}
