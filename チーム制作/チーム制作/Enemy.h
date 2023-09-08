#pragma once
#include"GameObject.h"
#include"SlimeBullet.h"
#include"HitEffect.h"
#include "DownEffec.h"
class Enemy : public GameObject
{

public:
	Enemy();
	~Enemy();

	//初期化
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph,int damage,int se);

	void HitAction(GameObject* gameObject);

private:
	void ANCIENTAttack();
	void Move();
	void FireAttack();//火攻撃
	void Animation();
	void Effect();
	void DownEffect();


	int moveCount = 0;//0の場合上移動

	int slimeEnemy;
	int prediction;

	//音関係
	int fireSE;
	int damageSE;
	int attackSE;

	bool moveFlag = true;
	bool createFlag = false;
	bool effectFlag = false;
	int predictionTime = 0;
};

