#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	
}

void Player::Initialize()
{
	objectMember = GameObject::PLAYER;
	objectState = GameObject::ANCIENT;
	position = { 300,300 };
	r = 32;
	color = GetColor(0, 0, 0);
}

void Player::Update()
{
	Move();
	Attack();
}

void Player::Draw()
{
	DrawCircle(position.x, position.y, r, color, true);
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		position.x += 5;//‰E
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		position.x -= 5;//¶
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		position.y -= 5;//ã
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		position.y += 5;//‰º
	}
}

void Player::Attack()
{
	if (timeFlag == false)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			PlayerBullet* bullet = new PlayerBullet();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize(position);
			addGameObjects.push_back(bullet);
			timeFlag = true;
		}
	}
	else
	{
		time++;
		if (time <= 5)return;
		timeFlag = false;
		time = 0;
	}
}
