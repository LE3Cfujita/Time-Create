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
void Enemy::Initialize(XMFLOAT2 pos, int number)
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
	this->number = number;
}

void Enemy::Update()
{
	Spawn();
	if (HP <= 0)
	{
		objState = DEATH;
		deathCount = 1;
		int a = rand() % 9;
		if (a == 5)
		{
			RecoveryItem* item = new RecoveryItem;
			item->BaseInitialize(referenceGameObjects);
			item->Initialize({ position });
			addGameObjects.push_back(item);
		}

	}
	ANCIENTAttack();
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
	if (actionFlag == false)return;
	if (timeFlag == false)
	{
		int a = rand() % 3;
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
	if (objState == EFFECT || objState == DEATH || actionFlag == false)return;

	if (actionFlag == true && gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
		HP--;
		gameObject->SetDeathFlag(true);
	}
}

void Enemy::Spawn()
{
	switch (number)
	{
	case 0:
		dy = 200 - position.y;
		if (200 - position.y == 0)number = 100;
		break;
	case 1:
		dy = 300 - position.y;
		if (300 - position.y == 0)number = 100;
		break;
	case 2:
		dy = 400 - position.y;
		if (400 - position.y == 0)number = 100;
	case 3:
		dy = 500 - position.y;
		if (500 - position.y == 0)
			number = 100;
		break;
	case 4:
		dy = 600 - position.y;
		if (600 - position.y == 0)
		{
			number = 100;
			for (GameObject* gameobject : referenceGameObjects)
			{
				if (gameobject->GetObjectMember() == OBJECTMEMBER::SLIME)
				{
					gameobject->SetActionFlag(true);
				}
			}
		}
		break;
	}
	if (number >= 5)return;
	da = dy * dy;
	L = sqrt(da);
	position.y += (dy / L) * 5;
}
