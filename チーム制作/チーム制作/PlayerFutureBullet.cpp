#include "PlayerFutureBullet.h"

PlayerFutureBullet::PlayerFutureBullet()
{
}

PlayerFutureBullet::~PlayerFutureBullet()
{
}

void PlayerFutureBullet::Initialize(XMFLOAT2 pos) 
{
	objectMember = GameObject::PLAYERBULLET;//ƒvƒŒƒCƒ„[’e
	position = { pos.x + r,pos.y};
	r = 16;

	bullet = LoadGraph("Resource/futureBullet.png"); // •`‰æ
}

void PlayerFutureBullet::Update()
{
	Move();
}

void PlayerFutureBullet::Draw()
{
	DrawGraph(position.x, position.y, bullet, true);
}

void PlayerFutureBullet::Move()
{
	position.x += 10;
	if (position.x >= 1300)
	{
		deathFlag = true;
	}
}
