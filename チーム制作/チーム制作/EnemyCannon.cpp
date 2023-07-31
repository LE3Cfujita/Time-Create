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
	bullet = LoadGraph("Resource/EnemyCannon.png"); // �`��
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
	//�e�̈ړ�
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
	//�J�E���g��0�Ȃ�z�[�~���O����
	if (homingCount == 0)
	{
		dx = pos.x - position.x;//X�̋����̌v�Z
		dy = pos.y - 32 - position.y;//Y�̋����̌v�Z
		//���[�g�̒��̌v�Z
		da = dx * dx + dy * dy;
		L = sqrt(da);
	}
}
