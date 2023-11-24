#pragma once
#include"GameObject.h"
class BossNormalBullet : public GameObject
{
public:
	BossNormalBullet();
	~BossNormalBullet();

	//初期化
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource();
private:
	void Animation();
	void Move();

	int bullet;
	bool homingFlag = false;

	//プレイヤーの座標
	XMFLOAT2 pPos = { 0,0 };
};

