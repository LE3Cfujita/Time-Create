#pragma once
#include"GameObject.h"
class Obstacle : public GameObject
{

public:
	Obstacle();
	~Obstacle();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph);

	void HitAction(GameObject* gameObject);
private:

	int obstacle;//è·äQï®
};

