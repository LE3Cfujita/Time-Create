#include "Player.h"

Player::Player()
{
}

Player::~Player()
{

}

void Player::Resource(int graph)
{
	player = graph;//画像読み込み
}

void Player::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::PLAYER;
	objectStage = GameObject::FIRSTSTAGE;
	position = { pos.x,pos.y };
	r = 16;
	this->number = number;
	/*tuujouSE = LoadSoundMem("Resource/tuujou.mp3");
	attackSE = LoadSoundMem("Resource/2.mp3");
	gendaiAttackSE = LoadSoundMem("Resource/gendaiPlayerSE.mp4");
	kodaiAttackSE = LoadSoundMem("Resource/playershot_kodai.mp3");
	damageSE = LoadSoundMem("Resource/playerdamage.mp3");*/
	HP = 2;
}


void Player::Update()
{
	Move();//�ړ�
	Attack();//�U��
	Invincible();
	if (HP <= 0)
	{
		objState = DEATH;
		deathCount = 1;
	}
	Formation();
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
		position2 = position;
		position.x += 5;
		if (position.x + 32 >= 850)
		{
			position.x = 850 - 32;
		}
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		position2 = position;
		position.x -= 5;
		if (position.x - 32 <= 0)
		{
			position.x = 32;
		}
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		position2 = position;
		position.y -= 5;
		if (position.y - r <= 0)
		{
			position.y = 0 + r;
		}
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		position2 = position;
		position.y += 5;
		if (position.y + r * 3 >= 720)
		{
			position.y = 720 - r * 3;
		}
	}
	if (position.x - 32 <= 0)
	{
		position.x = 32;
	}
	if (position.y - r <= 0)
	{
		position.y = 0 + r;
	}
	if (position.x + 32 >= 850)
	{
		position.x = 850 - 32;
	}
	if (position.y + r * 3 >= 720)
	{
		position.y = 720 - r * 3;
	}
}

void Player::Attack()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)//�X�y�[�X�������ōU����������
	{
		if (objectStage == FIRSTSTAGE)
		{
			if (hitButton == true)return;
			if (CheckSoundMem(kodaiAttackSE) == FALSE)
			{
				PlaySoundMem(kodaiAttackSE, DX_PLAYTYPE_BACK, TRUE);
			}
			animationFlag = true;
			PlayerBullet* bullet = new PlayerBullet();
			bullet->BaseInitialize(referenceGameObjects);
			bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
			addGameObjects.push_back(bullet);
			hitButton = true;
			timeFlag = true;
		}
	}
	else
	{
		if (CheckSoundMem(kodaiAttackSE) == TRUE)
		{
			StopSoundMem(kodaiAttackSE);
		}
		if (CheckSoundMem(gendaiAttackSE) == TRUE)
		{
			StopSoundMem(gendaiAttackSE);
		}
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
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYER)
	{
		position = position2;
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

void Player::Formation()
{
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		switch (number)
		{
		case 0:
			position = { 100,300 };
			break;
		case 1:
			position = { 200,300 };
			break;
		case 2:
			position = { 300,300 };
			break;
		case 3:
			position = { 400,300 };
			break;
		case 4:
			position = { 500,300 };
			break;
		}
	}
	if (CheckHitKey(KEY_INPUT_X) == 1)
	{
		switch (number)
		{
		case 0:
			position = { 100,100 };
			break;
		case 1:
			position = { 100,200 };
			break;
		case 2:
			position = { 100,300 };
			break;
		case 3:
			position = { 100,400 };
			break;
		case 4:
			position = { 100,500 };
			break;
		}
	}
}
