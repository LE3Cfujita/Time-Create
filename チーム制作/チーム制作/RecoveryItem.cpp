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
}

void RecoveryItem::Update()
{
	Move();
}

void RecoveryItem::Draw()
{
}

void RecoveryItem::Resource(int graph, int damage, int se)
{
}

void RecoveryItem::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYER)
	{
		deathFlag = true;
	}
}

void RecoveryItem::Move()
{
	position.x -= 5;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}
