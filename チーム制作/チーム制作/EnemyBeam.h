#pragma once
#include"GameObject.h"
class EnemyBeam : public GameObject
{

public:
	EnemyBeam();
	~EnemyBeam();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();

	int bullet;
	int size_x = 0;
	int size_x2 = 0;
};

