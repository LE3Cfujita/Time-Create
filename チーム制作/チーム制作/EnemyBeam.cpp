#include "EnemyBeam.h"

EnemyBeam::EnemyBeam()
{
}

EnemyBeam::~EnemyBeam()
{
}

void EnemyBeam::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMYBEAM;
	position = { pos.x - 100,pos.y + 260 };
	position2 = { pos.x - 100,pos.y - 260 };
	bullet = LoadGraph("Resource/EnemyBeam.png"); // •`‰æ
	bulletSpeed = 15;
}

void EnemyBeam::Update()
{
	Move();
}

void EnemyBeam::Draw()
{
	DrawExtendGraph(position.x, position.y, position2.x, position2.y, bullet, TRUE);
}

void EnemyBeam::Move()
{
	position.x -= 20;
	size_x += 20;
	if (size_x >= 1100)
	{
		for (GameObject* gameObject : referenceGameObjects)
		{
			if (gameObject->GetObjectMember() != GameObject::ENEMY)continue;
			{
				gameObject->SetPredictionFlag(false);
				break;
			}
		}
		position2.x -= 20;
		size_x2 += 20;
	}
	if (size_x2 >= 1100)
	{
		deathFlag = true;
		for (GameObject* gameObject : referenceGameObjects)
		{
			if (gameObject->GetObjectMember() != GameObject::ENEMY)continue;
			{
				gameObject->SetMove(true);
				gameObject->SetBeamFlag(false);
				gameObject->SetBeamCount(false);
				break;
			}
		}
	}
}

