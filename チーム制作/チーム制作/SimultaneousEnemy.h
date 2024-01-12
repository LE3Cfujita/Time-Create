#pragma once
#include"GameObject.h"
#include"BossNormalBullet.h"
#include"RecoveryItem.h"
#include"SlimeBullet.h"
class SimultaneousEnemy : public GameObject
{

public:
	SimultaneousEnemy();
	~SimultaneousEnemy();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos,int number);

	void Update();

	void Draw();

	void Resource(int bul);

	void HitAction(GameObject* gameObject);

	void Death();
private:

	void Move();

	void Attack();

	void Spwan();

	void RecoveryDrop();

	int bullet;
	int simultaneous;

	int time = 0;

	int speed = 0;

	bool moveFlag = false;
	bool attackFlag = false;

};

