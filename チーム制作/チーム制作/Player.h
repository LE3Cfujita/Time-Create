#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//初期化
	void Initialize();

	void Update();

	void Draw();
private:
	void Move();
	void Attack();

	bool timeFlag = false;//falseなら打つ
	int time = 0;

};

