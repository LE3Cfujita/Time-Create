#pragma once
#include"GameObject.h"
class EntourageBullet : public GameObject
{

public:
	EntourageBullet();
	~EntourageBullet();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Move();

	void Distance(XMFLOAT2 pos);
private:
	int bullet;
};

