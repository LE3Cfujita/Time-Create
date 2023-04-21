#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//‰Šú‰»
	void Initialize();

	void Update();

	void Draw();
private:
	void Move();
	void Attack();

	bool timeFlag = false;//false‚È‚ç‘Å‚Â
	int time = 0;

};

