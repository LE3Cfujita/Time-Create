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

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph);

private:
	void ANCIENTAttack();
	void Move();
	void FireAttack();//‰ÎUŒ‚
	void Animation();
	void Effect();
	void DownEffect();

	void HitAction(GameObject* gameObject);

	int moveCount = 0;//0‚Ìê‡ãˆÚ“®

	int slimeEnemy;
	int prediction;
	int beamSE;
	int fireSE;
	int cannonSE;
	int dieSE;

	bool moveFlag = true;
	bool createFlag = false;
	bool effectFlag = false;
	int predictionTime = 0;
};

