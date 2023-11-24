#pragma once
#include"GameObject.h"
class BossNormalBullet : public GameObject
{
public:
	BossNormalBullet();
	~BossNormalBullet();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource();
private:
	void Animation();
	void Move();

	int bullet;
	bool homingFlag = false;

	//�v���C���[�̍��W
	XMFLOAT2 pPos = { 0,0 };
};

