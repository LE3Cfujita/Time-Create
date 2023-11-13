#pragma once
#include"GameObject.h"
class SimultaneousEnemy : public GameObject
{

public:
	SimultaneousEnemy();
	~SimultaneousEnemy();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos,int number);

	void Update();

	void Draw();

	void Resource(int bul);

	void HitAction(GameObject* gameObject);
private:

	void Move();

	void Attack();

	int bullet;
	int simultaneous;

	int time = 0;
	int moveNumber = 0;

	int speed = 0;

	bool moveFlag = false;
};

