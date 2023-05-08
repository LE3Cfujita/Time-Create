#pragma once
#include"GameObject.h"
#include "EnemyBullet.h"
#include"EnemyFire.h"
#include"EnemyBalkan.h"
#include"EnemyCannon.h"
class Enemy : public GameObject
{

public:
	Enemy();
	~Enemy();

	//������
	void Initialize();

	void Update();

	void Draw();
private:
	void ANCIENTAttack();
	void MODERNAttack();
	void Move();
	void BulletAttack();//�e�U��
	void FireAttack();//�΍U��
	void BalkanAttack();//�o���J���U��
	void AimAttack();//�_���U��

	void HitAction(GameObject* gameObject);

	int moveCount = 0;//0�̏ꍇ��ړ�

	int enemy;

	bool move = true;
};

