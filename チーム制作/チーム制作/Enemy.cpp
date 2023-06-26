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
	r = 64;
	ancientEnemy = LoadGraph("Resource/Enemy.png"); // �`��
	ancientEnemyanime = LoadGraph("Resource/EnemyAnime.png"); // �`��
	modernEnemy = LoadGraph("Resource/EnemyModern.png");
	futureEnemy = LoadGraph("Resource/EnemyFuture.png");
	prediction = LoadGraph("Resource/prediction.png");
	time = 100;
	HP = 1;
	moveFlag = true;
	timeFlag = true;
	move = true;
	beamCT = 0;
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
		DrawRectGraph(position.x - r, position.y - r, animeCount * 295, 0, 295, 150, ancientEnemyanime, TRUE, FALSE);
		break;
	case MODERN://����G
		DrawExtendGraph(position.x - r - 16, position.y - r, position.x + r, position.y + r, modernEnemy, TRUE);
		break;
	case FUTURE://�����G
		DrawGraph(position.x - 174, position.y - 96, futureEnemy, TRUE);
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
		Animation();
		//int rad = rand() % 2;
		//if (rad == 1)
		//{
		//	BulletAttack();//�e
		//}
		//else
		//{
		//	FireAttack();
		//}
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
	if (beamCT == 150)
	{
		if (number != 0)return;
		EntourageCreate();
	}
	if (beamCT >= 300)
	{
		if (position.y >= 340 && position.y <= 380)
		{
			BeamAttack();
			move = false;
			createFlag = false;
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

void Enemy::Animation()
{
	animation = animation + 1;

	if (animation > 4)
	{
		animeCount = animeCount + 1;
		animation = 0;
		if (animeCount >= 4)
		{
			timeFlag = true;
			BulletAttack();//�e
			FireAttack();//��
			move = false;
			animeCount = 0;
		}
	}
}

void Enemy::EntourageCreate()
{
	if (createFlag == true)return;
	for (int i = 1; i <= 8; i++)
	{
		EnemyEntourage* entourage = new EnemyEntourage();
		entourage->BaseInitialize(referenceGameObjects);
		entourage->Initialize(position, i);
		addGameObjects.push_back(entourage);
		createFlag = true;
		number = 8;
	}
}

void Enemy::Effect()
{
	HitEffect* effect = new HitEffect();
	effect->BaseInitialize(referenceGameObjects);
	effect->Initialize(position);
	addGameObjects.push_back(effect);
}

void Enemy::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		Effect();
		HP--;
		gameObject->SetDeathFlag(true);
	}
	else if (gameObject->GetObjectMember() == OBJECTMEMBER::MODERNBBULLET)
	{
		Effect();
		HP -= 0.25;
		gameObject->SetDeathFlag(true);
	}
	else if (gameObject->GetObjectMember() == OBJECTMEMBER::FUTUREBULLET)
	{
		Effect();
		HP -= 0.25;
		gameObject->SetDeathFlag(true);
	}
}
