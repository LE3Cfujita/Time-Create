#pragma once
#include"GameObject.h"
#include "EnemyBullet.h"
#include"EnemyFire.h"
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
	void Move();
	void BulletAttack();//�e�U��
	void FireAttack();//�΍U��

	void HitAction(GameObject* gameObject);

};

