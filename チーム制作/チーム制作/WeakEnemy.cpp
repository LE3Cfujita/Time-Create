#include "WeakEnemy.h"

WeakEnemy::WeakEnemy()
{
}

WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::SLIME;
	objectStage = GameObject::SECONDSTAGE;
	position = { pos.x,pos.y };
	this->number = number;
}

void WeakEnemy::Update()
{
	Move();
	//ANCIENTAttack();
}

void WeakEnemy::Draw()
{

	if (objState == EFFECT || objState == DEATH)return;
	switch (objectStage)
	{
	case SECONDSTAGE:
		r = 16;
		DrawRectGraph(position.x - r, position.y, animeCount * 32, 0, 32, 16, enemy, TRUE, FALSE);
		break;
	}
}

void WeakEnemy::Resource(int graph, int damage, int se)
{
	enemy = graph;//画像読み込み
	damageSE = damage;
	attackSE = se;
}

void WeakEnemy::HitAction(GameObject* gameObject)
{
	if (objState == EFFECT || objState == DEATH)return;

	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
		HP--;
		gameObject->SetDeathFlag(true);
	}
}

void WeakEnemy::Move()
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
		break;
	case 3:
		dy = 500 - position.y;
		if (500 - position.y == 0)number = 100;
		break;
	case 4:
		dy = 600 - position.y;
		if (600 - position.y == 0)number = 100;
		break;
	}
	if (number >= 5)return;
	da = dy * dy;
	L = sqrt(da);
	position.y += (dy / L) * 5;
}

void WeakEnemy::ANCIENTAttack()
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

void WeakEnemy::Animation()
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

void WeakEnemy::FireAttack()
{
	PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
	SlimeBullet* bullet = new SlimeBullet();
	bullet->BaseInitialize(referenceGameObjects);
	bullet->Initialize(position, 1);
	addGameObjects.push_back(bullet);
}
