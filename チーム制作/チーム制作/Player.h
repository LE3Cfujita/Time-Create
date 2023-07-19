#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
#include"PlayerModernBullet.h"
#include"PlayerFutureBullet.h"
#include"PlayerCharge.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//‰Šú‰»
	void Initialize();

	void Update();

	void Draw();
private:
	void Move();//ˆÚ“®
	void Attack();//UŒ‚
	void Invincible();//–³“G
	void HitAction(GameObject* gameObject);
	void Animation();


	int playerAncient;//•`‰æ—p
	int playerModern;
	int playerFuture;
	int ancientHP;//•`‰æ—p
	int modernHP;//•`‰æ—p
	int futureHP;//•`‰æ—p
	int chargedSE;
	int chargeingSE;
	int charge;
	int tuujouSE;
	int attackSE;

	XMFLOAT2 hpPos = { 0,0 };

	bool invincibleFlag = false;
	int invincibleTime = 0;
	bool animationFlag = false;

	bool chargeFlag = false;
	int chargeAnimation = 0;
	int chargeAnimationCount = 0;

	bool hitButton = false;

	int chargeTime = 0;
};

