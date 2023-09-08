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

	//èâä˙âª
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
	//ïœêî
	bool moveFlag = false;
	bool attackFlag = false;
	//âπä÷åW
	int damageSE;
	int attackSE;

};

