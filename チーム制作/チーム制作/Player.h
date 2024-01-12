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

	void Resource(int graph, int se,int kirikae,int damage, int recovery);

	void changeForm(XMFLOAT2 pos);

	void FormationQ(XMFLOAT2 pos);
	void FormationE(XMFLOAT2 pos);

private:
	void Move();//移動
	void Attack();//攻撃
	void Invincible();//無敵
	void HitAction(GameObject* gameObject);
	void Animation();
	void Action();
	void AnotherP(GameObject* gameObject);//別のプレイヤーキャラ
	void Distance();//プレイヤー間の距離
	void Limit();//移動限界

	int player;//描画用
	int attackSE;
	int kirikaeSE;
	int damageSE;
	int recoverySE;

	bool invincibleFlag = false;
	int invincibleTime = 0;
	bool animationFlag = false;

	bool chargeFlag = false;
	int chargeAnimation = 0;
	int chargeAnimationCount = 0;

	bool attackFlag = false;
	int coolTime = 0;

	int chargeTime = 0;
	int pushTime = 0;

	bool X = false;

	bool actionFlag = false;

	int speed = 5;

	int subNumber = 0;
	XMFLOAT2 subPos = { 0,0 };
	bool moveFlag = true;

	XMFLOAT2 oldPos = { 0,0 };//1フレーム前の座標

	bool formFlag = false;

	int bullet;
};

