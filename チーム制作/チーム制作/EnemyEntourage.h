#pragma once
#include"GameObject.h"
#include"HitEffect.h"
#include"EntourageBullet.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class EnemyEntourage : public GameObject
{

public:
	EnemyEntourage();
	~EnemyEntourage();

	//初期化
	void Initialize(XMFLOAT2 pos, int number);

	void Update();

	void Draw();

	void Move();

	void HitAction(GameObject* gameObject);

	void Effect();

	void Attack();
private:
	int moveCount = 0;//0の場合上移動
	bool moveFlag = true;
	int number = 0;

	int enemy;
};

