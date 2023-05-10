#pragma once
#include "GameObject.h"
#include "Player.h"
#include"Enemy.h"
#include"GameObjectManager.h"
#include"DxLib.h"
class GameScene
{
public:
	enum GameState
	{
		TITLE,
		PLAY,
		CLEA,
		OVER,
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

	void ChangeScene();//シーン切り替え

	void ObjCreate();

	void SceneChange();//ゲーム中シーン切り替え

	void BackgroundScroll();//背景スクロール
private:
	GameState gameState;
	GameObjectManager* gameObjectManager = nullptr;


	XMFLOAT2 backPos = { 0,0 };
	XMFLOAT2 backPos2 = { 1280,0 };
	int title;
	int ancientback;
	int modernback;
	int futureback;
	int clear;
	int over;
	int keyCount = 0;

};

