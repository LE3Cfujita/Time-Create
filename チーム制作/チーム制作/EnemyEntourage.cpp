#include "EnemyEntourage.h"

using namespace std;

EnemyEntourage::EnemyEntourage()
{
}

EnemyEntourage::~EnemyEntourage()
{
}

void EnemyEntourage::Initialize(XMFLOAT2 pos, int number)
{
	srand((unsigned int)time(NULL));
	objectMember = GameObject::ENEMYENTOURAGE;
	objectAge = GameObject::ANCIENT;
	position = { 900,pos.y };
	HP = 1;
	this->number = number;
	r = 29;
	enemy = LoadGraph("Resource/EnemyFutureAnime.png");
}

void EnemyEntourage::Update()
{
	Move();
	int attack = rand() % 50 + 1;
	if (attack == 1)
	{
		Attack();
	}
	if (HP <= 0)
	{
		deathFlag = true;
		for (GameObject* gameObject : referenceGameObjects)
		{
			if (gameObject->GetObjectMember() != GameObject::ENEMY)continue;
			{
				int number = gameObject->GetNumber();
				gameObject->SetNumber(number -= 1);
				break;
			}
		}
	}
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
		HP -= 1;
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

void EnemyEntourage::Attack()
{
	EntourageBullet* bullet = new EntourageBullet();
	bullet->BaseInitialize(referenceGameObjects);
	bullet->Initialize(position);
	addGameObjects.push_back(bullet);
}
