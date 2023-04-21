#pragma once

#include <algorithm>

#include "GameObject.h"
#include"XMFLOAT_Helper.h"
#include <vector>

using namespace std;

class GameManager
{
private:
	std::vector<GameObject*> gameObjects;
public:

	GameManager();
	~GameManager();
	void Initialize();
	void Update();
	void Draw();
	void AddGameObject(GameObject* gameObject);
	std::vector<GameObject*> GetGameObjects() { return gameObjects; }
};

