#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//初期化
	void Initialize(XMFLOAT2 pos, int number);

	void Update();

	void Draw();

	void Resource(int graph, int se,int kirikae,int damage);

private:
	void Move();//移動
	void Attack();//攻撃
	void Invincible();//無敵
	void HitAction(GameObject* gameObject);
	void Animation();
	void Formation();

	int player;//描画用
	int attackSE;
	int kirikaeSE;
	int damageSE;

	bool invincibleFlag = false;
	int invincibleTime = 0;
	bool animationFlag = false;

	bool chargeFlag = false;
	int chargeAnimation = 0;
	int chargeAnimationCount = 0;

	bool hitButton = false;

	int chargeTime = 0;
	int pushTime = 0;

	int number;//キャラ番号
};

