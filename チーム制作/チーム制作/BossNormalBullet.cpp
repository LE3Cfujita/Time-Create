#include "BossNormalBullet.h"

BossNormalBullet::BossNormalBullet()
{
}

BossNormalBullet::~BossNormalBullet()
{
}

void BossNormalBullet::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::BOSSBULLET;

	r = 32;
	position = pos;
	bulletSpeed = rand() % 10 + 5;
	homingFlag = false;
	Resource();
}

void BossNormalBullet::Update()
{
	Move();
}

void BossNormalBullet::Draw()
{
	DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 32, bullet, TRUE, FALSE);
}

void BossNormalBullet::Resource()
{
	bullet = LoadGraph("Resource/enemyBullret.png"); // •`‰æ
}

void BossNormalBullet::Animation()
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
}

void BossNormalBullet::Move()
{
	for (GameObject* gameObject : referenceGameObjects)
	{
		if (gameObject->GetObjectMember() != GameObject::PLAYER)continue;
		pPos = gameObject->GetPosition();
		break;
	}
	timer++;
	if (timer >= 10)
	{
		timer = 0;
		homingFlag = true;
	}
	if (homingFlag == false)
	{
		dx = pPos.x - position.x;//X‚Ì‹——£‚ÌŒvZ
		dy = pPos.y - position.y;//Y‚Ì‹——£‚ÌŒvZ
		//ƒ‹[ƒg‚Ì’†‚ÌŒvZ
		da = dx * dx + dy * dy;
		L = sqrt(da);
	}
	position.x += (dx / L) * bulletSpeed;
	position.y += (dy / L) * bulletSpeed;

	if (position.x > 0)return;
	deathFlag = true;

}
