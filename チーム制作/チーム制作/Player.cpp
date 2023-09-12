#include "Player.h"

Player::Player()
{
}

Player::~Player()
{

}

void Player::Resource(int graph, int se, int kirikae, int damage)
{
	player = graph;//画像読み込み
	attackSE = se;
	kirikaeSE = kirikae;
	damageSE = damage;
}

void Player::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::PLAYER;
	objectStage = GameObject::FIRSTSTAGE;
	position = { pos.x,pos.y };
	r = 32;
	this->number = number;
	HP = 2;
}


void Player::Update()
{
	Move();
	Attack();
	Invincible();
	if (HP <= 0)
	{
		objState = DEATH;
		deathCount = 1;
	}
}

void Player::Draw()
{
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
		DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 62, player, TRUE, FALSE);
		Animation();
	}
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		if (position.x + r > 650)
		{
			position.x = 650 - r;
		}
		position.x += 5;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		if (position.x - r < 0)
		{
			position.x = r;
		}
		position.x -= 5;
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		if (position.y - r < 0)
		{
			position.y = 0 + r;
		}
		position.y -= 5;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		if (position.y + r > 720)
		{
			position.y = 720 - r;
		}
		position.y += 5;
	}
}

void Player::Attack()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)//�X�y�[�X�������ōU����������
	{
		if (hitButton == true)return;
		PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
		animationFlag = true;
		PlayerBullet* bullet = new PlayerBullet();
		bullet->BaseInitialize(referenceGameObjects);
		bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
		addGameObjects.push_back(bullet);
		hitButton = true;
		timeFlag = true;
	}
	else
	{
		hitButton = false;
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
		if (gameObject->GetObjectMember() == OBJECTMEMBER::SLIMEBULLET ||
			gameObject->GetObjectMember() == OBJECTMEMBER::BOSSBULLET)
		{
			PlaySoundMem(damageSE, DX_PLAYTYPE_BACK, TRUE);
			HP--;
			invincibleFlag = true;
			gameObject->SetDeathFlag(true);
		}
	}
	//プレイヤー同士が触れ合ってる場合
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYER)
	{
		if (X == true)
		{
			if (CheckHitKey(KEY_INPUT_D) == 1)
			{
				position.x -= 5;
			}
			if (CheckHitKey(KEY_INPUT_A) == 1)
			{
				position.x += 5;
			}
		}
		else
		{
			if (CheckHitKey(KEY_INPUT_W) == 1)
			{
				position.y += 5;
			}
			if (CheckHitKey(KEY_INPUT_S) == 1)
			{
				position.y -= 5;
			}
		}
		hitFlag = true;
	}
}


void Player::Animation()
{
	if (animationFlag == false)return;
	animation = animation + 1;

	if (objectStage == FIRSTSTAGE)
	{
		if (animation > 3)
		{
			animeCount = animeCount + 1;
			animation = 0;
			if (animeCount >= 3)
			{
				animeCount = 0;
				animationFlag = false;
			}
		}
		DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 64, player, TRUE, FALSE);
	}
}

void Player::FormationX(XMFLOAT2 pos)
{
	switch (number)
	{
	case 0:
		position = { pos.x - 100 * 2,pos.y };
		break;
	case 1:
		position = { pos.x - 100 * 1,pos.y };
		break;
	case 2:
		position = { pos.x,pos.y };
		break;
	case 3:
		position = { pos.x + 100 * 1,pos.y };
		break;
	case 4:
		position = { pos.x + 100 * 2,pos.y };
		break;
	}
	if (CheckSoundMem(kirikaeSE) == FALSE)
	{
		PlaySoundMem(kirikaeSE, DX_PLAYTYPE_BACK, TRUE);
	}
	X = true;
}

void Player::FormationZ(XMFLOAT2 pos)
{
	switch (number)
	{
	case 0:
		position = { pos.x,pos.y - 100 * 2 };
		break;
	case 1:
		position = { pos.x,pos.y - 100 * 1 };
		break;
	case 2:
		position = { pos.x,pos.y };
		break;
	case 3:
		position = { pos.x,pos.y + 100 * 1 };
		break;
	case 4:
		position = { pos.x,pos.y + 100 * 2 };
		break;
	}
	if (CheckSoundMem(kirikaeSE) == FALSE)
	{
		PlaySoundMem(kirikaeSE, DX_PLAYTYPE_BACK, TRUE);
	}
	X = false;
}
