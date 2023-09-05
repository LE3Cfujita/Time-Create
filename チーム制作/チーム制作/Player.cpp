#include "Player.h"

Player::Player()
{
}

Player::~Player()
{

}

void Player::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::PLAYER;//�v���C���[
	objectAge = GameObject::ANCIENT;//�Ñ�
	position = { pos.x,pos.y };
	r = 16;
	playerAncient = LoadGraph("Resource/Playeranime.png"); // �`��
	playerModern = LoadGraph("Resource/PlayerModern.png"); // �`��
	playerFuture = LoadGraph("Resource/PlayerFuture.png"); // �`��
	ancientHP = LoadGraph("Resource/ancienthp.png"); // �`��
	modernHP = LoadGraph("Resource/modernHP.png"); // �`��
	futureHP = LoadGraph("Resource/futureHP.png"); // �`��
	charge = LoadGraph("Resource/PlayerCharge.png");
	chargedSE = LoadSoundMem("Resource/charge.mp3");
	tuujouSE = LoadSoundMem("Resource/tuujou.mp3");
	attackSE = LoadSoundMem("Resource/2.mp3");
	chargeingSE = LoadSoundMem("Resource/chargeing.mp3");
	gendaiAttackSE = LoadSoundMem("Resource/gendaiPlayerSE.mp4");
	kodaiAttackSE = LoadSoundMem("Resource/playershot_kodai.mp3");
	damageSE = LoadSoundMem("Resource/playerdamage.mp3");
	HP = 1;
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
			DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 62, playerAncient, TRUE, FALSE);
		}
		else if (objectAge == MODERN)
		{
			DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 62, playerModern, TRUE, FALSE);
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
			DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 64, playerFuture, TRUE, FALSE);

			if (chargeFlag == true)
			{
				chargeAnimation = chargeAnimation + 1;
				if (chargeAnimation > 2)
				{
					if (chargeTime >= 120)
					{
						chargeAnimationCount = 0;
						if (CheckSoundMem(chargedSE) == FALSE)
						{
							PlaySoundMem(chargedSE, DX_PLAYTYPE_BACK, TRUE);
						}
					}
					else
					{
						chargeAnimationCount = chargeAnimationCount + 1;
						chargeAnimation = 0;
						if (chargeAnimationCount >= 2)
						{
							chargeAnimationCount = 0;
						}
					}
				}
				DrawRectGraph(position.x + r, position.y, chargeAnimationCount * 32, 0, 32, 32, charge, TRUE, FALSE);

			}
		}
		Animation();
	}
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		position2 = position;
		position.x += 5;//�E
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		position2 = position;
		position.x -= 5;//��
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		position2 = position;
		position.y -= 5;//��
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		position2 = position;
		position.y += 5;//��
	}
	if (position.x - 32 <= 0)
	{
		position.x = 32;
		position2 = position;
	}
	if (position.y - r <= 0)
	{
		position.y = 0 + r;
		position2 = position;
	}
	if (position.x + 32 >= 850)
	{
		position.x = 850 - 32;
		position2 = position;
	}
	if (position.y + r * 3 >= 720)
	{
		position.y = 720 - r * 3;
		position2 = position;
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
			else if (objectAge == MODERN)
			{
				if (CheckSoundMem(gendaiAttackSE) == FALSE)
				{
					PlaySoundMem(gendaiAttackSE, DX_PLAYTYPE_BACK, TRUE);
				}
				animationFlag = true;
				PlayerModernBullet* bullet = new PlayerModernBullet();
				bullet->BaseInitialize(referenceGameObjects);
				bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
				addGameObjects.push_back(bullet);
				timeFlag = true;
			}
			else
			{
				if (CheckSoundMem(chargeingSE) == FALSE)
				{
					PlaySoundMem(chargeingSE, DX_PLAYTYPE_BACK, TRUE);
				}
				chargeTime++;
				hitButton = true;
				chargeFlag = true;
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
			if (hitButton == true && objectAge == FUTURE)
			{
				if (CheckSoundMem(chargeingSE) == TRUE)
				{
					StopSoundMem(chargeingSE);
				}
				if (chargeTime >= 120)
				{
					PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
					animationFlag = true;
					PlayerCharge* bullet = new PlayerCharge();
					bullet->BaseInitialize(referenceGameObjects);
					bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
					addGameObjects.push_back(bullet);
				}
				else
				{
					PlaySoundMem(tuujouSE, DX_PLAYTYPE_BACK, TRUE);
					animationFlag = true;
					PlayerFutureBullet* bullet = new PlayerFutureBullet();
					bullet->BaseInitialize(referenceGameObjects);
					bullet->Initialize({ position.x + r / 32,position.y + r / 32 });
					addGameObjects.push_back(bullet);
				}
				chargeTime = 0;
			}
			hitButton = false;
			chargeFlag = false;
		}
	}
	else
	{
		timer++;

		if (timer >= 5 && objectAge == MODERN)
		{
			timeFlag = false;
			timer = 0;
		}
		else if (timer >= 20 && objectAge != MODERN)
		{
			timeFlag = false;
			timer = 0;
		}
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
			gameObject->GetObjectMember() == OBJECTMEMBER::ENEMYCANNON ||
			gameObject->GetObjectMember() == OBJECTMEMBER::ENTOURAGEBULLET)
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

	if (objectAge == ANCIENT)
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
		DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 64, playerAncient, TRUE, FALSE);
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
				animationFlag = false;
			}
		}
		DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 64, playerModern, TRUE, FALSE);
	}
}
