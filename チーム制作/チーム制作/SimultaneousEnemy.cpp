#include "SimultaneousEnemy.h"

SimultaneousEnemy::SimultaneousEnemy()
{
}

SimultaneousEnemy::~SimultaneousEnemy()
{
}

void SimultaneousEnemy::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::SIMULTANEOUSENEMY;
	HP = 20;
	r = 32;
	simultaneous = LoadGraph("Resource/allEnemy_New.png");
	tentativ = LoadGraph("Resource/allEnemy_New_Tentatib.png");
	position = pos;
	position.y = position.y * number;
	moveNumber = number;
	speed = rand() % 5 + 5;
}

void SimultaneousEnemy::Update()
{
	if (actionFlag == false)
	{
		Spwan();
	}
	else
	{
		Move();
		Attack();
		Death();
	}
}

void SimultaneousEnemy::Draw()
{
	if (objState != TENTATIVE)
	{
		DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 64, simultaneous, TRUE, FALSE);
	}
	else
	{
		DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 64, tentativ, TRUE, FALSE);
	}
}

void SimultaneousEnemy::Resource(int bul)
{
	bullet = bul;
}

void SimultaneousEnemy::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		//PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
		HP--;
		gameObject->SetDeathFlag(true);
	}
}

void SimultaneousEnemy::Death()
{
	if (objState != TENTATIVE)return;
	for (GameObject* gameobject : referenceGameObjects)
	{
		if (gameobject->GetObjectMember() == OBJECTMEMBER::SIMULTANEOUSENEMY)
		{
			if (moveNumber == 1)
			{
				if (gameobject->GetMoveNumber() == 2)
				{
					if (gameobject->GetObjectState() == TENTATIVE)
					{
						objState = DEATH;
						gameobject->SetObjectState(DEATH);
					}
				}
			}
		}
	}
}

void SimultaneousEnemy::Move()
{
	if (HP <= 0)
	{
		time++;
		objState = TENTATIVE;
	}
	else
	{
		if (moveNumber == 1)
		{
			if (position.y <= 16)moveFlag = true;//trueÇæÇ¡ÇΩÇÁâ∫à⁄ìÆ
			if (position.y >= 360)moveFlag = false;//falseÇæÇ¡ÇΩÇÁè„à⁄ìÆ
		}
		else
		{
			if (position.y <= 360)moveFlag = true;//trueÇæÇ¡ÇΩÇÁâ∫à⁄ìÆ
			if (position.y >= 702 - 16)moveFlag = false;//falseÇæÇ¡ÇΩÇÁè„à⁄ìÆ
		}
		if (moveFlag == true)position.y += speed;
		else position.y -= speed;
	}

	if (time >= 240)
	{
		objState = IDLE;
		HP = 20;
		time = 0;
	}
}

void SimultaneousEnemy::Attack()
{
	if (objState != TENTATIVE)
	{
		if (attackFlag == true)
		{
			BossNormalBullet* bullet;
			bullet = new BossNormalBullet();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize({ position });
			bullet->Resource();
			addGameObjects.push_back(bullet);
			RecoveryDrop();
			attackFlag = false;
		}
		else
		{
			timer++;
			if (timer <= 120)return;
			attackFlag = true;
			timer = 0;
		}
	}
	else
	{
		if (attackFlag == true)
		{
			//PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
			SlimeBullet* bullet = new SlimeBullet();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize(position, 1);
			addGameObjects.push_back(bullet);
			RecoveryDrop();
			attackFlag = false;
		}
		else
		{
			timer++;
			if (timer <= 5)return;
			attackFlag = true;
			timer = 0;
		}
	}
}

void SimultaneousEnemy::Spwan()
{
	dx = 1100 - position.x;
	if (dx != 0)
	{
		da = dx * dx;
		L = sqrt(da);
		position.x += (dx / L) * 10;
	}
	else
	{
		actionFlag = true;
	}
}

void SimultaneousEnemy::RecoveryDrop()
{
	int a = rand() % 15;
	if (a == 1)
	{
		RecoveryItem* item = new RecoveryItem;
		item->BaseInitialize(referenceGameObjects);
		item->Initialize({ position });
		addGameObjects.push_back(item);
	}

}
