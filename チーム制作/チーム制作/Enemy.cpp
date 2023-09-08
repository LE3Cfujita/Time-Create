#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Resource(int graph, int damage, int se)
{
	slimeEnemy = graph;//画像読み込み
	damageSE = damage;
	attackSE = se;
}
void Enemy::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::SLIME;
	objectStage = GameObject::FIRSTSTAGE;
	position = { pos.x,pos.y };
	r = 16;
	timer = 100;
	HP = 1;
	moveFlag = true;
	timeFlag = true;
	beamCT = 0;
}

void Enemy::Update()
{
	if (HP <= 0)
	{
		objState = DEATH;
		deathCount = 1;
	}
	switch (objectStage)
	{
	case FIRSTSTAGE://�Ñ�U��
		//ANCIENTAttack();
		break;
	}
}

void Enemy::Draw()
{
	if (objState == EFFECT || objState == DEATH)return;
	switch (objectStage)
	{
	case FIRSTSTAGE:
		r = 16;
		DrawRectGraph(position.x - r, position.y, animeCount * 32, 0, 32, 16, slimeEnemy, TRUE, FALSE);
		break;
	}
}


void Enemy::ANCIENTAttack()
{


	if (timeFlag == false)
	{
		int a = rand() % 2;
		if (a == 0)
		{
			Animation();
		}
	}
	else
	{
		timer++;
		if (timer <= 60)return;
		move = true;
		if (timer <= 180)return;
		timeFlag = false;
		timer = 0;
	}
}
void Enemy::FireAttack()
{
	PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
	SlimeBullet* bullet = new SlimeBullet();
	bullet->BaseInitialize(referenceGameObjects);
	bullet->Initialize(position, 1);
	addGameObjects.push_back(bullet);
}


void Enemy::Animation()
{
	animation = animation + 1;

	if (animation > 5)
	{
		animeCount = animeCount + 1;
		animation = 0;
		if (animeCount >= 5)
		{
			timeFlag = true;
			FireAttack();//��
			move = false;
			animeCount = 0;
		}
	}
}

void Enemy::Effect()
{
	HitEffect* effect = new HitEffect();
	effect->BaseInitialize(referenceGameObjects);
	effect->Initialize(position);
	addGameObjects.push_back(effect);
}

void Enemy::DownEffect()
{
	DownEffec* effect = new DownEffec();
	effect->BaseInitialize(referenceGameObjects);
	effect->Initialize(position);
	addGameObjects.push_back(effect);
	effectFlag = true;
}

void Enemy::HitAction(GameObject* gameObject)
{
	if (objState == EFFECT || objState == DEATH)return;

	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
		HP--;
		gameObject->SetDeathFlag(true);
	}
}
