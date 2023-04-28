#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYERBULLET;//�v���C���[�e
	position = { pos.x,pos.y-32 };
	r = 16;

	bullet = LoadGraph("Resource/PlayerBullet.png"); // �`��
}

void PlayerBullet::Update()
{
	Move();//�ړ�
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