#pragma once
#include "GameObject.h"
#include "Player.h"
#include"GameManager.h"
#include"DxLib.h"
class GameScene
{
public:
	enum GameState
	{
		TITLE,
		OPTION_SELECT,
		OPTION_SOUND,
		OPTION_KEY,
		OPTION_SENSI,
		PLAY,
		CLEA,
		OVER,
		SCENECHANGE,
		SCENECHANGEOVER,
		SCENECHANGECLEA,
		OPERATION,
		RULE
	};
public:
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

private:
	GameManager* gameObjectManager = nullptr;
	Player* player = nullptr;
};

