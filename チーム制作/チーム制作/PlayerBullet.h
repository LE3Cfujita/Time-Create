#pragma once
#include"GameObject.h"
#include"HitEffect.h"
class PlayerBullet : public GameObject
{
public:
	PlayerBullet();
	~PlayerBullet();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void HitAction(GameObject* gameObject);
private:
	void Animation();
	void Move();

	int bullet;
};


