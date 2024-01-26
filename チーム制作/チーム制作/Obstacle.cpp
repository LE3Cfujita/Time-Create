#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::OBSTACLE;
	position = pos;
	r = 16;
}

void Obstacle::Update()
{
}

void Obstacle::Draw()
{
	DrawGraph(position.x - r, position.y - r * 2, obstacle, true);
}

void Obstacle::Resource(int graph)
{
	obstacle = graph;
}

void Obstacle::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET ||
		gameObject->GetObjectMember() == OBJECTMEMBER::BOSSBULLET ||
		gameObject->GetObjectMember() == OBJECTMEMBER::SLIMEBULLET)
	{
		gameObject->SetDeathFlag(true);
	}
}
