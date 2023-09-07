#pragma once
#include"GameObject.h"
#include"HitEffect.h"
#include "DownEffec.h"
class BossEnemy : public GameObject
{

public:
	BossEnemy();
	~BossEnemy();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph);
private:
	int boss;


};

