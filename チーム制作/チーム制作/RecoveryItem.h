#pragma once
#include"GameObject.h"
class RecoveryItem : public GameObject
{

public:
	RecoveryItem();
	~RecoveryItem();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph, int damage, int se);

	void HitAction(GameObject* gameObject);

private:
	void Move();
};

