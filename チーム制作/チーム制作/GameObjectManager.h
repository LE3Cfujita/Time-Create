#pragma once

#include <algorithm>
#include"GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Intialize();
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// GameObject��ǉ�
	/// </summary>
	/// <param name="gameObject">�Q�[���I�u�W�F�N�g</param>
	void AddGameObject(GameObject* gameObject);

	/// <summary>
	/// Game
	/// </summary>
	/// <returns></returns>
	std::vector<GameObject*>GetGameObjects() { return gameObjects; }
private:
	std::vector<GameObject*>gameObjects;
};

