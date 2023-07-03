#include "PlayerCharge.h"

PlayerCharge::PlayerCharge()
{
}

PlayerCharge::~PlayerCharge()
{
	
}

void PlayerCharge::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;
	position = { pos.x + r,pos.y };
	r = 64;
	bullet = LoadGraph("Resource/EnemyCannon.png"); // •`‰æ
	bulletSpeed = 15;
}

void PlayerCharge::Update()
{
	Move();
}

void PlayerCharge::Draw()
{
	DrawGraph(position.x, position.y, bullet, true);
}

void PlayerCharge::Move()
{
	position.x += bulletSpeed;
	if (position.x <= 1280)return;
	deathFlag = true;
}
