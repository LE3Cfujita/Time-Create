#pragma once
#include"GameObject.h"
class WeakEnemy : public GameObject
{

public:
	WeakEnemy();
	~WeakEnemy();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos,int number);

	void Update();

	void Draw();

	void Resource(int graph, int damage, int se);

	void HitAction(GameObject* gameObject);

private:

	void Move();

	int enemy;
	int damageSE;
	int attackSE;
};

