#include "Player.h"

Player::Player()
{
}

Player::~Player()
{

}

void Player::Initialize()
{
	objectMember = GameObject::PLAYER;//�v���C���[
	objectAge = GameObject::ANCIENT;//�Ñ�
	objState = GameObject::IDLE;
	position = { 300,300 };
	r = 64;
	player = LoadGraph("Resource/Player2.png"); // �`��
}

void Player::Update()
{
	Move();//�ړ�
	Attack();//�U��
}

void Player::Draw()
{
	DrawExtendGraph(position.x - r, position.y - r, position.x + r, position.y + r, player, TRUE);
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		position.x += 5;//�E
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		position.x -= 5;//��
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		position.y -= 5;//��
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		position.y += 5;//��
	}
	if (position.x - 32 <= 0)
	{
		position.x = 32;
	}
	if (position.y - r <= 0)
	{
		position.y = 0 + r;
	}
	if (position.x + 32 >= 1280)
	{
		position.x = 1280 - 32;
	}
	if (position.y + r >= 720)
	{
		position.y = 720 - r;
	}
}

void Player::Attack()
{
	if (timeFlag == false)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)//�X�y�[�X�������ōU����������
		{
			PlayerBullet* bullet = new PlayerBullet();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
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

void Player::HitAction(GameObject* gameObject)
{
	if (gameObject->GetObjectMenber() == OBJECTMEMBER::ENEMYBULLET || gameObject->GetObjectMenber() == OBJECTMEMBER::ENEMYFIRE)
	{
		//deathFlag = true;
		gameObject->SetDeathFlag(true);
	}
}
