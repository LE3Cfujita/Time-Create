#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;//ƒvƒŒƒCƒ„[’e
	objectAge = GameObject::ANCIENT;//ŒÃ‘ã
	position = { pos.x,pos.y };
	r = 16;
	color = GetColor(0,0,0);
}

void PlayerBullet::Update()
{
	Move();//ˆÚ“®
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