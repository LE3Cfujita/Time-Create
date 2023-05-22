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
	r = 8;
	playerAncient = LoadGraph("Resource/Playeranime.png"); // �`��
	playerModern = LoadGraph("Resource/PlayerModern.png"); // �`��
	playerFuture = LoadGraph("Resource/PlayerFuture.png"); // �`��
	ancientHP = LoadGraph("Resource/ancienthp.png"); // �`��
	modernHP = LoadGraph("Resource/modernHP.png"); // �`��
	futureHP = LoadGraph("Resource/ancienthp.png"); // �`��
	HP = 10;
}

void Player::Update()
{
	Move();//�ړ�
	Attack();//�U��
	Invincible();
}

void Player::Draw()
{
	for (int i = 0; i < HP; i++)
	{
		if (objectAge == ANCIENT)
		{
			DrawGraph(i * 64, 0, ancientHP, TRUE);
		}
		else if (objectAge == MODERN)
		{
			DrawGraph(i * 64, 0, modernHP, TRUE);
		}
		else
		{
			DrawGraph(i * 64, 0, futureHP, TRUE);
		}
	}

	if (invincibleTime == 0 ||
		invincibleTime >= 3 && invincibleTime <= 6 ||
		invincibleTime >= 9 && invincibleTime <= 12 ||
		invincibleTime >= 15 && invincibleTime <= 18 ||
		invincibleTime >= 21 && invincibleTime <= 24 ||
		invincibleTime >= 27 && invincibleTime <= 30 ||
		invincibleTime >= 33 && invincibleTime <= 36 ||
		invincibleTime >= 39 && invincibleTime <= 42 ||
		invincibleTime >= 45 && invincibleTime <= 48 ||
		invincibleTime >= 51 && invincibleTime <= 54)
	{
		if (objectAge == ANCIENT)
		{
			DrawRectGraph(position.x - r * 2, position.y - r * 2, animeCount * 64, 0, 64, 64, playerAncient, TRUE, FALSE);
		}
		else if (objectAge == MODERN)
		{
			DrawRectGraph(position.x - r * 2, position.y - r * 2, animeCount * 64, 0, 64, 64, playerModern, TRUE, FALSE);
		}
		else
		{
			animation = animation + 1;
			if (animation > 2)
			{
				animeCount = animeCount + 1;
				animation = 0;
				if (animeCount >= 2)
				{
					animeCount = 0;
				}
			}
			DrawRectGraph(position.x - r * 2, position.y - r * 2, animeCount * 64, 0, 64, 64, playerFuture, TRUE, FALSE);

		}

		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			Animation();
		}
	}
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
			if (objectAge == ANCIENT)
			{
				PlayerBullet* bullet = new PlayerBullet();
				bullet->BaseInitialize(referenceGameObjects);
				bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
				addGameObjects.push_back(bullet);
			}
			else
			{
				PlayerModernBullet* bullet = new PlayerModernBullet();
				bullet->BaseInitialize(referenceGameObjects);
				bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
				addGameObjects.push_back(bullet);
			}
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

void Player::Invincible()
{
	if (invincibleFlag == false)return;
	invincibleTime++;
	if (invincibleTime < 60)return;
	invincibleTime = 0;
	invincibleFlag = false;

}

void Player::HitAction(GameObject* gameObject)
{
	if (invincibleFlag == false)
	{
		if (gameObject->GetObjectMember() == OBJECTMEMBER::ENEMYBULLET ||
			gameObject->GetObjectMember() == OBJECTMEMBER::ENEMYFIRE ||
			gameObject->GetObjectMember() == OBJECTMEMBER::ENEMYBALKAN ||
			gameObject->GetObjectMember() == OBJECTMEMBER::ENEMYCANNON)
		{
			HP--;
			invincibleFlag = true;
			gameObject->SetDeathFlag(true);
			if (gameObject->GetObjectMember() == OBJECTMEMBER::ENEMYCANNON)
			{
				for (GameObject* gameObject2 : referenceGameObjects)
				{
					if (gameObject2->GetObjectMember() != GameObject::ENEMY)continue;
					{
						gameObject2->SetCannonFlag(false);
						break;
					}
				}
				SetCannonFlag(false);
			}
		}
	}
}

void Player::Animation()
{
	animation = animation + 1;

	if (objectAge == ANCIENT)
	{
		if (animation > 3)
		{
			animeCount = animeCount + 1;
			animation = 0;
			if (animeCount >= 3)
			{
				animeCount = 0;
			}
		}
		DrawRectGraph(position.x - r * 2, position.y - r * 2, animeCount * 64, 0, 64, 64, playerAncient, TRUE, FALSE);
	}
	else if (objectAge == MODERN)
	{
		if (animation > 2)
		{
			animeCount = animeCount + 1;
			animation = 0;
			if (animeCount >= 2)
			{
				animeCount = 0;
			}
		}
		DrawRectGraph(position.x - r * 2, position.y - r * 2, animeCount * 64, 0, 64, 64, playerModern, TRUE, FALSE);
	}
}
