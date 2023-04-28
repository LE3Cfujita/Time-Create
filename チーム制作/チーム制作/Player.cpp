#include "Player.h"

Player::Player()
{
}

Player::~Player()
{

}

void Player::Initialize()
{
	objectMember = GameObject::PLAYER;//プレイヤー
	objectAge = GameObject::ANCIENT;//古代
	objState = GameObject::IDLE;
	position = { 300,300 };
	r = 64;
	player = LoadGraph("Resource/Player2.png"); // 描画
}

void Player::Update()
{
	Move();//移動
	Attack();//攻撃
}

void Player::Draw()
{
	DrawExtendGraph(position.x - r, position.y - r, position.x + r, position.y + r, player, TRUE);
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		position.x += 5;//右
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		position.x -= 5;//左
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		position.y -= 5;//上
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		position.y += 5;//下
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
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)//スペース長押しで攻撃し続ける
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
