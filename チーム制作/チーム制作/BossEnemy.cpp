#include "BossEnemy.h"

BossEnemy::BossEnemy()
{
}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::Resource(int graph)
{
	boss = graph;//âÊëúì«Ç›çûÇ›
}

void BossEnemy::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::BOSSENEMY;
	objectStage = GameObject::SECONDSTAGE;
	position = pos;
	HP = 50;
}

void BossEnemy::Update()
{
	if (HP <= 0)
	{
		objState = DEATH;
		deathCount = 1;
	}
}

void BossEnemy::Draw()
{
	if (objState == EFFECT || objState == DEATH)return;
	switch (objectStage)
	{
	case SECONDSTAGE:
		DrawRectGraph(position.x - r, position.y, animeCount * 32, 0, 32, 16, boss, TRUE, FALSE);
		break;
	}
}

