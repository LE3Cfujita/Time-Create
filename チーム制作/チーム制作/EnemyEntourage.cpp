#include "EnemyEntourage.h"

EnemyEntourage::EnemyEntourage()
{
}

EnemyEntourage::~EnemyEntourage()
{
}

void EnemyEntourage::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::ENEMYENTOURAGE;
	objectAge = GameObject::ANCIENT;
	position = {900,pos.y };
	HP = 10;
	this->number = number;
	r = 29;
	enemy = LoadGraph("Resource/EnemyFutureAnime.png");
}

void EnemyEntourage::Update()
{
	Move();
}

void EnemyEntourage::Draw()
{
	DrawGraph(position.x - r, position.y - r, enemy, TRUE);
}

void EnemyEntourage::Move()
{
	position.y = number * 40 * 2;
	/*if (position.y != number * 58)
	{
		position.y -= number * 58 - 10;
	}
	else
	{
		position.y == number * 58;
	}*/
}

void EnemyEntourage::HitAction(GameObject* gameObject)
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


void EnemyEntourage::Effect()
{
	HitEffect* effect = new HitEffect();
	effect->BaseInitialize(referenceGameObjects);
	effect->Initialize(position);
	addGameObjects.push_back(effect);
}