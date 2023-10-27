#pragma once
#include"GameObject.h"
#include"SlimeBullet.h"
#include"RecoveryItem.h"
class WeakEnemy : public GameObject
{

public:
	WeakEnemy();
	~WeakEnemy();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos,int number);

	void Update();

	void Draw();

	void Resource(int graph, int damage, int se);

	void HitAction(GameObject* gameObject);

private:

	void Move();
	void ANCIENTAttack();
	void Animation();
	void FireAttack();

	int enemy;
	int damageSE;
	int attackSE;
};

