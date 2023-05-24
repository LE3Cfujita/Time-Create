#include "PlayerModernBullet.h"

PlayerModernBullet::PlayerModernBullet()
{
}

PlayerModernBullet::~PlayerModernBullet()
{
}

void PlayerModernBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;//ƒvƒŒƒCƒ„[’e
	position = { pos.x + r,pos.y - 16 };
	r = 16;

	bullet = LoadGraph("Resource/modernBullet.png"); // •`‰æ
}

void PlayerModernBullet::Update()
{
	Move();
}

void PlayerModernBullet::Draw()
{
	DrawGraph(position.x, position.y, bullet, true);
}

void PlayerModernBullet::Move()
{
	position.x += 10;
	if (position.x >= 1300)
	{
		deathFlag = true;
	}
}
