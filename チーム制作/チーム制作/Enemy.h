#pragma once
#include"GameObject.h"
class Enemy : public GameObject
{

public:
	Enemy();
	~Enemy();

	//‰Šú‰»
	void Initialize();

	void Update();

	void Draw();
private:
	void Move();
	void Attack();

	void HitAction(GameObject* gameObject);

};

