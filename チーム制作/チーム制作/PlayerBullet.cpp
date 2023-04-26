#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;//プレイヤー弾
	objectAge = GameObject::ANCIENT;//古代
	position = { pos.x,pos.y };
	r = 16;
	color = GetColor(0,0,0);
}

void PlayerBullet::Update()
{
	Move();//移動
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