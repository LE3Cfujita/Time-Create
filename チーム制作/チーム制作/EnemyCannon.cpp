#include "EnemyCannon.h"

EnemyCannon::EnemyCannon()
{
}

EnemyCannon::~EnemyCannon()
{
}

void EnemyCannon::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMYCANNON;
	position = { pos.x - r,pos.y - r };
	r = 64;
	bullet = LoadGraph("Resource/EnemyCannon.png"); // 描画
	bulletSpeed = 15;
}

void EnemyCannon::Update()
{
	Move();
}

void EnemyCannon::Draw()
{
	DrawGraph(position.x, position.y, bullet, true);
}

void EnemyCannon::Move()
{
	XMFLOAT2 pos = { 0.0f,0.0f };
	for (GameObject* gameObject : referenceGameObjects)
	{
		if (gameObject->GetObjectMember() != GameObject::PLAYER)continue;
		{
			pos = gameObject->GetPosition();
			break;
		}
	}
	Distance(pos);
	//弾の移動
	position.x += (dx / L) * bulletSpeed;
	position.y += (dy / L) * bulletSpeed;
	if (position.x <= -10)
	{
		deathFlag = true;
	}
}

void EnemyCannon::Distance(XMFLOAT2 pos)
{
	homingTime++;
	if (homingTime >= 10)
	{
		homingTime = 0;
		homingCount = 1;
	}
	//カウントが0ならホーミングする
	if (homingCount == 0)
	{
		dx = pos.x - position.x;//Xの距離の計算
		dy = pos.y - 32 - position.y;//Yの距離の計算
		//ルートの中の計算
		da = dx * dx + dy * dy;
		L = sqrt(da);
	}
}
