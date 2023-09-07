#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
#include"PlayerCharge.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos,int number);

	void Update();

	void Draw();

	void Resource(int graph);

private:
	void Move();//ˆÚ“®
	void Attack();//UŒ‚
	void Invincible();//–³“G
	void HitAction(GameObject* gameObject);
	void Animation();
	void Formation();

	int player;//•`‰æ—p
	int tuujouSE;
	int attackSE;
	int kodaiAttackSE;
	int gendaiAttackSE;
	int damageSE;

	XMFLOAT2 hpPos = { 0,0 };

	bool invincibleFlag = false;
	int invincibleTime = 0;
	bool animationFlag = false;

	bool chargeFlag = false;
	int chargeAnimation = 0;
	int chargeAnimationCount = 0;

	bool hitButton = false;

	int chargeTime = 0;
	int pushTime = 0;

	int number;//ƒLƒƒƒ‰”Ô†
};

