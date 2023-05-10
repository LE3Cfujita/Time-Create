#pragma once
#include"GameObject.h"
class EnemyCannon : public GameObject
{

public:
	EnemyCannon();
	~EnemyCannon();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();

	void Distance(XMFLOAT2 pos);

	int bullet;
};

