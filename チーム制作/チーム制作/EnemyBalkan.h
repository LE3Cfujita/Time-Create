#pragma once
#include"GameObject.h"
class EnemyBalkan : public GameObject
{
public:
	EnemyBalkan();
	~EnemyBalkan();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();

	int bullet;
};

