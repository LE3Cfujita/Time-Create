#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Resource(int graph)
{
	slimeEnemy = graph;//画像読み込み
}
void Enemy::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::SLIME;
	objectStage = GameObject::FIRSTSTAGE;
	position = { pos.x,pos.y };
	r = 16;
	/*prediction = LoadGraph("Resource/prediction.png");
	beamSE = LoadSoundMem("Resource/UFObeam.mp3");
	fireSE = LoadSoundMem("Resource/fireSE.mp3");
	cannonSE = LoadSoundMem("Resource/gendaiEnemySE.mp3");
	dieSE = LoadSoundMem("Resource/enemyDIE.mp3");*/
	timer = 100;
	HP = 1;
	moveFlag = true;
	timeFlag = true;
	move = true;
	beamCT = 0;
}

void Enemy::Update()
{
		if (HP <= 0)
		{
			objState = DEATH;
			deathCount = 1;
		}
		if (move == true)
		{
			//Move();
		}
		switch (objectStage)
		{
		case FIRSTSTAGE://�Ñ�U��
			ANCIENTAttack();
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
		Animation();
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


void Enemy::FireAttack()
{
	if (CheckSoundMem(fireSE) == FALSE)
	{
		PlaySoundMem(fireSE, DX_PLAYTYPE_BACK, TRUE);
	}
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
	if (CheckSoundMem(dieSE) == FALSE)
	{
		PlaySoundMem(dieSE, DX_PLAYTYPE_BACK, TRUE);
	}
}

void Enemy::HitAction(GameObject* gameObject)
{
	if (objState == EFFECT || objState == DEATH)return;

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
