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
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// GameObjectを追加
	/// </summary>
	/// <param name="gameObject">ゲームオブジェクト</param>
	void AddGameObject(GameObject* gameObject);

	/// <summary>
	/// Game
	/// </summary>
	/// <returns></returns>
	std::vector<GameObject*>GetGameObjects() { return gameObjects; }
private:
	std::vector<GameObject*>gameObjects;
};

