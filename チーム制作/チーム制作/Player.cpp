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

void Player::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYER;
	objectStage = GameObject::FIRSTSTAGE;
	position = { pos.x,pos.y };
	r = 32;
	this->number = number;
	HP = 10;
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
		for (int i = 0; i < drawNumber; i++)
		{
			if (formationFlag == true)
			{
				DrawRectGraph(position.x - r, position.y - r + (gap * i), animeCount * 64, 0, 64, 62, player, TRUE, FALSE);
			}
			else
			{
				DrawRectGraph(position.x - r - (gap * i), position.y - r, animeCount * 64, 0, 64, 62, player, TRUE, FALSE);
			}
		}
		Animation();
	}
	if (HP % 2 != 0)return;
	drawNumber = HP / 2;
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
		if (formationFlag == true)
		{
			if (position.y - r <= 0)
			{
				position.y = 0 + r;
				if (gap <= r * 2)return;
				gap -= 3;
			}
			else if (position.y - r > 0 && gap <= 100)
			{
				position.y -= 2 * drawNumber;
				if (gap <= 100)
				{
					gap += 2;
				}
			}
			else
			{
				position.y -= 5;
			}
		}
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		if (formationFlag == true)
		{
			if (position.y + r * 2 + (gap * (drawNumber - 1)) >= 720)
			{
				if (gap <= r * 2)return;
				gap -= 2;
				position.y += 2 * drawNumber;
			}
			else if (position.y + r + (gap * drawNumber) < 720 && gap <= 100)
			{
				gap += 3;
			}
			else
			{
				position.y += 5;
			}
		}
	}
	if (CheckHitKey(KEY_INPUT_X) == 1)
	{
		formationFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		formationFlag = false;
	}
}

void Player::Attack()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		if (hitButton == true)return;
		PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
		animationFlag = true;
		for (int i = 0; i < drawNumber; i++)
		{
			PlayerBullet* bullet = new PlayerBullet();
			bullet->BaseInitialize(referenceGameObjects);
			if (formationFlag == true)
			{
				bullet->Initialize({ position.x + r / 32,position.y + r / 32 + (gap * i) });
			}
			else
			{
				bullet->Initialize({ position.x + r / 32 - (gap * i),position.y + r / 32 });
			}
			addGameObjects.push_back(bullet);
		}
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
	}
}

