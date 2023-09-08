#include "WeakEnemy.h"

WeakEnemy::WeakEnemy()
{
}

WeakEnemy::~WeakEnemy()
{
}

void WeakEnemy::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::SLIME;
	objectStage = GameObject::SECONDSTAGE;
	position = { pos.x,pos.y };
}

void WeakEnemy::Update()
{
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
	enemy = graph;//‰æ‘œ“Ç‚Ýž‚Ý
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
