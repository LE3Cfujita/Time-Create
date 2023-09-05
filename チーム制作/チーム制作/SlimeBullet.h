#pragma once
#include"GameObject.h"
class SlimeBullet : public GameObject
{

public:
	SlimeBullet();
	~SlimeBullet();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos,int number);

	void Update();

	void Draw();

	void Resource();
private:

	void Move();

	int bullet;
};

