#pragma once
#include"GameObject.h"
class PlayerBullet : public GameObject
{
public:
	PlayerBullet();
	~PlayerBullet();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();
};


