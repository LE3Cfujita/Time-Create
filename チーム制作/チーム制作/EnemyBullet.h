#pragma once
#include"GameObject.h"
class EnemyBullet : public GameObject
{
public:
	EnemyBullet();
	~EnemyBullet();

	//������
	void Initialize(XMFLOAT2 pos,int namber);

	void Update();

	void Draw();
private:

	void Move();

	int bullet;
};

