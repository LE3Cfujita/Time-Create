#pragma once
#include"GameObject.h"
class PlayerModernBullet : public GameObject
{
public:
	PlayerModernBullet();
	~PlayerModernBullet();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();

	int bullet;
};

