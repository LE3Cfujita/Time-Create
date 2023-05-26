#pragma once
#include"GameObject.h"
#include "EnemyBullet.h"
#include"EnemyFire.h"
#include"EnemyBalkan.h"
#include"EnemyCannon.h"
#include"EnemyBeam.h"
class Enemy : public GameObject
{

public:
	Enemy();
	~Enemy();

	//‰Šú‰»
	void Initialize();

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

	void HitAction(GameObject* gameObject);

	int moveCount = 0;//0‚Ìê‡ãˆÚ“®

	int ancientEnemy;
	int ancientEnemyanime;
	int modernEnemy;
	int futureEnemy;
	int prediction;

	bool moveFlag = true;
	int predictionTime = 0;
};

