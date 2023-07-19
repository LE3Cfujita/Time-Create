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

	//������
	void Initialize();

	void Update();

	void Draw();
private:
	void Move();//�ړ�
	void Attack();//�U��
	void Invincible();//���G
	void HitAction(GameObject* gameObject);
	void Animation();


	int playerAncient;//�`��p
	int playerModern;
	int playerFuture;
	int ancientHP;//�`��p
	int modernHP;//�`��p
	int futureHP;//�`��p
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

