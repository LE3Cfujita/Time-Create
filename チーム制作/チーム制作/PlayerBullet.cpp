#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;
	objectAge = GameObject::ANCIENT;
	position = { pos.x,pos.y };
	r = 16;
	color = (0,0,0);
}

void PlayerBullet::Update()
{
	Move();
}

void PlayerBullet::Draw()
{
	DrawCircle(position.x, position.y, r,color, true);
}

void PlayerBullet::Move()
{
	position.x += 10;
	if (position.x >= 1300)
	{
		deathFlag = true;
	}
}