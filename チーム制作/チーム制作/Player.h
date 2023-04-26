#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//èâä˙âª
	void Initialize();

	void Update();

	void Draw();
private:
	void Move();
	void Attack();
	void HitAction(GameObject* gameObject);

	int player;
};

