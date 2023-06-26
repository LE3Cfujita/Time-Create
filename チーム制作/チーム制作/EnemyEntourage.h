#pragma once
#include"GameObject.h"
#include"HitEffect.h"
class EnemyEntourage : public GameObject
{

public:
	EnemyEntourage();
	~EnemyEntourage();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos, int number);

	void Update();

	void Draw();

	void Move();

	void HitAction(GameObject* gameObject);

	void Effect();

	void Attack();
private:
	int moveCount = 0;//0‚Ìê‡ãˆÚ“®
	bool moveFlag = true;
	int number = 0;

	int enemy;
};

