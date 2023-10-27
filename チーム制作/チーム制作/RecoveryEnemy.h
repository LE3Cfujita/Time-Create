#pragma once
#include"GameObject.h"
#include"RecoveryItem.h"
#include "RecoveryBullet.h"
class RecoveryEnemy : public GameObject
{
public:
	RecoveryEnemy();
	~RecoveryEnemy();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw(); 
	
	void Resource(int bul);

private:
	void Move();

	void Recovery();

	void Attack();

	bool topFlag = false;
	bool moveFlag = false;
	bool attackFlag = false;


	int recovery;
	int bul;

	int moveTime = 0;
	int attackTime = 0;
	int time = 0;

};

