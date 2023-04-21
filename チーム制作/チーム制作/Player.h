#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//������
	void Initialize();

	void Update();

	void Draw();
private:

	void Move();

	void Attack();

	PlayerBullet* bullet = nullptr;

	bool timeFlag = false;//false�Ȃ�ł�
	int time = 0;//�N�[���^�C��
};

