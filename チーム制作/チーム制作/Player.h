#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
#include"PlayerModernBullet.h"
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
	int ancientHP;//•`‰æ—p
	int modernHP;//•`‰æ—p
	int futureHP;//•`‰æ—p

	XMFLOAT2 hpPos = { 0,0 };

	int invincibleFlag = false;
	int invincibleTime = 0;
};

