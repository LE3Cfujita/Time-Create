#pragma once
#include"GameObject.h"
#include "EnemyBullet.h"
#include"EnemyFire.h"
#include"EnemyBalkan.h"
#include"EnemyCannon.h"
#include"EnemyBeam.h"
#include "EnemyEntourage.h"
#include"HitEffect.h"
#include "DownEffec.h"
class Enemy : public GameObject
{

public:
	Enemy();
	~Enemy();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos,int graph);

	void Update();

	void Draw();

private:
	void ANCIENTAttack();
	void MODERNAttack();
	void FUTUREAttack();
	void Move();
	void BulletAttack();//’eUŒ‚
	void FireAttack();//‰ÎUŒ‚
	void BalkanAttack();//ƒoƒ‹ƒJƒ“UŒ‚
	void AimAttack();//‘_‚¤UŒ‚
	void BeamAttack();
	void Animation();
	void EntourageCreate();//æ‚èŠª‚«¢Š«
	void Effect();
	void DownEffect();

	void HitAction(GameObject* gameObject);

	int moveCount = 0;//0‚Ìê‡ãˆÚ“®

	int ancientEnemy;
	int ancientEnemySlimeAnime;
	int modernEnemy;
	int futureEnemy;
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

