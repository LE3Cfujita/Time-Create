#pragma once
#include"GameObject.h"
class RecoveryBullet : public GameObject
{

public:
	RecoveryBullet();
	~RecoveryBullet();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int bul);
private:

	void Move();

	int bullet;
};

