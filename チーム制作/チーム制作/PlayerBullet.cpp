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
	position = { pos.x,pos.y };
	r = 16;
}

void PlayerBullet::Update()
{
	Move();
}

void PlayerBullet::Draw()
{
	DrawCircle(position.x, position.y, r, (1, 0, 0), true);
}

void PlayerBullet::Move()
{
	position.x += 10;
	if (position.x >= 1300)
	{
		deathFlag = true;
	}
}
