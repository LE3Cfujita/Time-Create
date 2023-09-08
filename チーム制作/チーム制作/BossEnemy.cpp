#include "BossEnemy.h"

BossEnemy::BossEnemy()
{
}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::Resource(int graph, int damage, int se, int weak)
{
	boss = graph;//‰æ‘œ“Ç‚Ýž‚Ý
	damageSE = damage;
	attackSE = se;
	weakEnemy = weak;
}

void BossEnemy::HitAction(GameObject* gameObject)
{
	if (objState == EFFECT || objState == DEATH)return;
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
		HP--;
		gameObject->SetDeathFlag(true);
	}
}

void BossEnemy::Move()
{
	if (position.y <= 16)moveFlag = true;//true‚¾‚Á‚½‚ç‰ºˆÚ“®
	if (position.y >= 704)moveFlag = false;//false‚¾‚Á‚½‚çãˆÚ“®
	if (moveFlag == true)position.y += 5;
	else position.y -= 5;
}

void BossEnemy::Attack()
{
	if (attackFlag == true)
	{
		PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
		BossNormalBullet* bullet;
		bullet = new BossNormalBullet();
		bullet->BaseInitialize(referenceGameObjects);
		bullet->Initialize({ position });
		bullet->Resource();
		addGameObjects.push_back(bullet);
		attackFlag = false;

		int a = rand() % 15;
		if (a == 0)
		{
			Summon();
			line++;
			if (line >= 5)
			{
				line = 0;
			}
		}
	}
	else
	{
		timer++;
		if (timer <= 120)return;
		attackFlag = true;
		timer = 0;
	}
}

void BossEnemy::Summon()
{
	for (int i = 0; i < 5; i++)
	{
		WeakEnemy* enemy;
		enemy = new WeakEnemy();
		enemy->BaseInitialize(referenceGameObjects);
		enemy->Initialize({ (float)750 + 100 * line,(float)-100 - 100 * i }, i);
		enemy->Resource(weakEnemy, damageSE, attackSE);
		addGameObjects.push_back(enemy);
	}
}

void BossEnemy::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::BOSSENEMY;
	objectStage = GameObject::SECONDSTAGE;
	position = pos;
	r = 64;
	HP = 50;
	timer = 0;
}

void BossEnemy::Update()
{
	if (HP <= 0)
	{
		objState = DEATH;
		deathCount = 1;
	}
	Move();
	Attack();
}

void BossEnemy::Draw()
{
	if (objState == EFFECT || objState == DEATH)return;
	switch (objectStage)
	{
	case SECONDSTAGE:
		DrawRectGraph(position.x - r, position.y - r, animeCount * 128, 0, 128, 128, boss, TRUE, FALSE);
		break;
	}
}

