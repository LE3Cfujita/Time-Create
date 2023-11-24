#pragma once
#include"GameObject.h"
class RecoveryItem : public GameObject
{

public:
	RecoveryItem();
	~RecoveryItem();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

private:
	void Move();

	int item;
};

