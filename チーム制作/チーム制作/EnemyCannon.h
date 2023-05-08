#pragma once
#include"GameObject.h"
class EnemyCannon : public GameObject
{

public:
	EnemyCannon();
	~EnemyCannon();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos, int number);

	void Update();

	void Draw();
private:

	void Move();

	int bullet;
};

