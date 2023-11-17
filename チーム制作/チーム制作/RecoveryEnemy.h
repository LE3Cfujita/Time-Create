#pragma once
#include"GameObject.h"
#include"RecoveryItem.h"
#include "RecoveryBullet.h"
class RecoveryEnemy : public GameObject
{
public:
	RecoveryEnemy();
	~RecoveryEnemy();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw(); 
	
	void Resource(int bul);

	void HitAction(GameObject* gameObject);

private:
	void Move();

	void Recovery();

	void Attack();
	
	void Spwan();

	bool topFlag = false;
	bool moveFlag = false;
	bool attackFlag = false;


	int recovery;
	int bul;

	int moveTime = 0;
	int attackTime = 0;
	int time = 0;

	double size = 0.0;
	double angle = 0;
};

