#pragma once
#include"GameObject.h"
class PlayerFutureBullet : public GameObject
{
public:
	PlayerFutureBullet();
	~PlayerFutureBullet();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();

	int bullet;
};

