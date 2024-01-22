#include "Player.h"

Player::Player()
{
}

Player::~Player()
{

}

void Player::Resource(int graph, int se, int kirikae, int damage, int recovery)
{
	player = graph;//画像読み込み
	attackSE = se;
	kirikaeSE = kirikae;
	damageSE = damage;
	recoverySE = recovery;
}

void Player::changeForm(XMFLOAT2 pos)
{
	if (formFlag == false)
	{
		FormationQ(pos);
		formFlag = true;
	}
	else
	{
		FormationE(pos);
		formFlag = false;
	}

}

void Player::Initialize(XMFLOAT2 pos, int number)
{
	objectMember = GameObject::PLAYER;
	position = { pos.x,pos.y };
	r = 32;
	this->number = number;
	HP = 5;
}


void Player::Update()
{
	Action();
	if (actionFlag == true)
	{
		Move();
		Attack();
		Invincible();
	}
	if (HP == 0)
	{
		objState = TENTATIVE;
		deathCount = 1;
		HP = -10;
	}

}

void Player::Draw()
{
	if (objState != TENTATIVE)
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
}

void Player::Move()
{
	oldPos = position;
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		position.x += speed;
		if (position.x + r > 650)
		{
			position.x = 650 - r;
		}
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		position.x -= speed;
		if (position.x - r < 0)
		{
			position.x = 0 + r;
		}
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		position.y -= speed;
		if (position.y - r < 0)
		{
			position.y = 0 + r;
		}
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		position.y += speed;
		if (position.y + r > 720)
		{
			position.y = 720 - r;
		}
	}
}

void Player::Attack()
{
	if (objState != TENTATIVE)
	{
		if (attackFlag == false)
		{
			if (CheckHitKey(KEY_INPUT_SPACE) == 1)//�X�y�[�X�������ōU����������
			{
				PlaySoundMem(attackSE, DX_PLAYTYPE_BACK, TRUE);
				PlayerBullet* bullet = new PlayerBullet();
				bullet->BaseInitialize(referenceGameObjects);
				bullet->Initialize({ position.x + r / 32,position.y + r });
				addGameObjects.push_back(bullet);
				attackFlag = true;
				timeFlag = true;
			}
		}
		else
		{
			coolTime++;
			if (coolTime >= 15)
			{
				coolTime = 0;
				attackFlag = false;
			}
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
	if (objState != TENTATIVE)
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
		if (gameObject->GetObjectMember() == OBJECTMEMBER::RECOVERYBEAM)
		{
			HP--;
		}
		if (gameObject->GetObjectMember() == OBJECTMEMBER::RECOVERY)
		{
			for (GameObject* gameobject2 : referenceGameObjects)
			{
				if (gameobject2->GetObjectMember() != OBJECTMEMBER::PLAYER)continue;
				PlaySoundMem(recoverySE, DX_PLAYTYPE_BACK, TRUE);
				gameobject2->SetObjectState(IDLE);
				gameobject2->SetHP(5);
				gameObject->SetDeathFlag(true);
				recoveryFlag = true;
			}
		}
	}
	//プレイヤー同士が触れ合ってる場合
	if (gameObject->GetObjectMember() == OBJECTMEMBER::PLAYER)
	{
		AnotherP(gameObject);
		if (gameObject->GetObjectState() == GameObject::OBJSTATE::TENTATIVE)return;
		if (X == true)
		{
			if (number > subNumber)
			{
				position.x = subPos.x + r * 2;
			}
			else
			{
				position.x = oldPos.x;
			}
			if (number < subNumber)
			{
				position.x = subPos.x - r * 2;
			}
			else
			{
				position.x = oldPos.x;
			}
		}
		else
		{
			if (number > subNumber)
			{
				position.y = subPos.y + r * 2;
			}
			else
			{
				position.y = oldPos.y;
			}
			if (number < subNumber)
			{
				position.y = subPos.y - r * 2;
			}
			else
			{
				position.y = oldPos.y;
			}
		}
	}
}


void Player::Animation()
{
	if (HP == 1)
	{
		animeCount = 0;
	}
	if (HP == 2)
	{
		animeCount = 1;
	}
	if (HP == 3)
	{
		animeCount = 2;
	}
	if (HP == 4)
	{
		animeCount = 3;
	}
	if (HP == 5)
	{
		animeCount = 4;
	}
}

void Player::Action()
{
	for (GameObject* gameObject : referenceGameObjects)
	{
		if (gameObject->GetObjectMember() == GameObject::SLIME ||
			gameObject->GetObjectMember() == GameObject::BOSSENEMY ||
			gameObject->GetObjectMember() == GameObject::RECOVERYENEMY ||
			gameObject->GetObjectMember() == GameObject::SIMULTANEOUSENEMY)
		{
			actionFlag = gameObject->GetActionFlag();
		}
	}
}

void Player::AnotherP(GameObject* gameObject)
{
	subNumber = gameObject->GetNumber();
	subPos = gameObject->GetPosition();

}

void Player::Distance()//プレイヤー同士の距離計算
{
	dx = subPos.x - position.x;//Xの距離の計算
	dy = subPos.y - position.y;//Yの距離の計算
	//ルートの中の計算
	da = dx * dx + dy * dy;
	L = sqrt(da);
}

void Player::FormationQ(XMFLOAT2 pos)
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

void Player::FormationE(XMFLOAT2 pos)
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

