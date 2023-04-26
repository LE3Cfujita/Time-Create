#pragma once
#include"GameObject.h"
#include "EnemyBullet.h"
#include"EnemyFire.h"
class Enemy : public GameObject
{

public:
	Enemy();
	~Enemy();

	//‰Šú‰»
	void Initialize();

	void Update();

	void Draw();
private:
	void Attack();
	void Move();
	void BulletAttack();//’eUŒ‚
	void FireAttack();//‰ÎUŒ‚

	void HitAction(GameObject* gameObject);

	int moveCount = 0;//0‚Ìê‡ãˆÚ“®

	int enemy;

	bool move = true;
};

