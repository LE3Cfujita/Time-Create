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
	position = { pos.x,pos.y-32 };
	r = 16;

	bullet = LoadGraph("Resource/PlayerBullet.png"); // 描画
}

void PlayerBullet::Update()
{
	Move();//移動
}

void PlayerBullet::Draw()
{
	DrawGraph(position.x, position.y,bullet, true);
}

void PlayerBullet::Move()
{
	position.x += 10;
	if (position.x >= 1300)
	{
		deathFlag = true;
	}
}