#pragma once
#include"GameObject.h"
#include"RecoveryItem.h"
#include "RecoveryBullet.h"
#include"RecoveryBeam.h"
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

	void BeamAttack();

	void Spwan();

	bool topFlag = false;
	bool moveFlag = false;
	bool attackFlag = false;
	bool beamFlag = false;

	int recovery;
	int bul;
	int heal;

	int moveTime = 0;
	int attackTime = 0;
	int time = 0;

	double size = 0.0;
	double angle = 0;
};

