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
}

void Obstacle::Update()
{
}

void Obstacle::Draw()
{
	DrawGraph(position.x - r, position.y - r, obstacle, true);
}

void Obstacle::Resource(int graph)
{
	obstacle = graph;
}

void Obstacle::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYERBULLET)
	{
		gameObject->SetDeathFlag(true);
	}
}
