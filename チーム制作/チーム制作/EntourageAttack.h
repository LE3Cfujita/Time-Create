#pragma once
#include"GameObject.h"
class EntourageAttack : public GameObject
{
public:
	EntourageAttack();
	~EntourageAttack();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

private:
	int bullet;
};

