#pragma once
#include"GameObject.h"
class RecoveryEnemy : public GameObject
{
public:
	RecoveryEnemy();
	~RecoveryEnemy();

	//������
	void Initialize();

	void Update();

	void Draw();

private:
	void Move();

	bool moveFlag = false;

	int recovery;
};

