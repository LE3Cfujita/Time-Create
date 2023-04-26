#pragma once
#include"GameObject.h"
class EnemyFire : public GameObject
{

public:
	EnemyFire();
	~EnemyFire();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();
};

