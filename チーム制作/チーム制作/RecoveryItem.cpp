#include "RecoveryItem.h"

RecoveryItem::RecoveryItem()
{
}

RecoveryItem::~RecoveryItem()
{
}

void RecoveryItem::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::RECOVERY;
	position = pos;
	r = 16;
	item = LoadGraph("Resource/recovery.png");
}

void RecoveryItem::Update()
{
	Move();
}

void RecoveryItem::Draw()
{
	DrawGraph(position.x, position.y, item, true);
}


void RecoveryItem::Move()
{
	position.x -= 5;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
