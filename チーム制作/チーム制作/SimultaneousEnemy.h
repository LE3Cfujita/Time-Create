#pragma once
#include"GameObject.h"
class SimultaneousEnemy : public GameObject
{

public:
	SimultaneousEnemy();
	~SimultaneousEnemy();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int bul);
private:

	void Move();

	void Attack();

	int bullet;
	int simultaneous;

	int time = 0;

	bool moveFlag = false;
};

