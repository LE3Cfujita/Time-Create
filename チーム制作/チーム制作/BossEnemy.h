#pragma once
#include"GameObject.h"
#include"HitEffect.h"
#include "DownEffec.h"
#include"BossNormalBullet.h"
#include"WeakEnemy.h"
class BossEnemy : public GameObject
{

public:
	BossEnemy();
	~BossEnemy();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph,int damage,int se,int weak);

	void HitAction(GameObject* gameObject);

private:

	void Move();

	void Attack();

	void Summon();



	int boss;
	int weakEnemy;
	//�ϐ�
	bool moveFlag = false;
	bool attackFlag = false;
	//���֌W
	int damageSE;
	int attackSE;

};

