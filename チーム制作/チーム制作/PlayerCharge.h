#pragma once
#include"GameObject.h"
class PlayerCharge : public GameObject
{
public:
	PlayerCharge();
	~PlayerCharge();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();

	int bullet;
};

