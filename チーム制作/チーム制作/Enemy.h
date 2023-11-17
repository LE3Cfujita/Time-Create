#pragma once
#include"GameObject.h"
#include"SlimeBullet.h"
#include"HitEffect.h"
#include "DownEffec.h"
#include"RecoveryItem.h"
class Enemy : public GameObject
{

public:
	Enemy();
	~Enemy();

	//������
	void Initialize(XMFLOAT2 pos,int number);

	void Update();

	void Draw();

	void Resource(int graph, int damage, int se);

	void HitAction(GameObject* gameObject);

	void Spawn();
private:
	void ANCIENTAttack();
	void FireAttack();//�΍U��
	void Animation();
	void Effect();
	void DownEffect();


	int moveCount = 0;//0�̏ꍇ��ړ�

	int slimeEnemy;
	int prediction;
	int item;

	//���֌W
	int fireSE;
	int damageSE;
	int attackSE;

	bool moveFlag = true;
	bool createFlag = false;
	bool effectFlag = false;
	int predictionTime = 0;
};

