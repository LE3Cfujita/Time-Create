#pragma once
#include "GameObject.h"
#include "Player.h"
#include"Enemy.h"
#include"GameObjectManager.h"
#include"DxLib.h"
#include"Collision.h"
class GameScene
{
public:
	enum GameState
	{
		TITLE,
		PLAY,
		CLEA,
		OVER,
		EXPLANATION
	};

	enum OBJAGE
	{
		ANCIENT,//古代
		MODERN,//現代
		FUTURE,//未来
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

	void PlayerCreate();

	void EnemyCreate();

	void SceneChange();//ゲーム中シーン切り替え

	void BackgroundScroll();//背景スクロール

	void PBCollision();

	void Invincible();

	void BGM();

	void LoadResource();

private:
	GameState gameState;
	OBJAGE objectAge;
	GameObjectManager* gameObjectManager = nullptr;
	Collision* collision = nullptr;

	XMFLOAT2 backPos = { 0,0 };
	XMFLOAT2 backPos2 = { 1280,0 };
	XMFLOAT2 backPos3 = { 2569,0 };
	XMFLOAT2 changePos = { 1280,0 };
	XMFLOAT2 setumeiPos = { 0,0 };
	XMFLOAT2 yajirusiPos = { 450,480 };
	int title;
	int ancientback;
	int modernback;
	int futureback;
	int changeback;
	int clear;
	int over;
	int setumei;
	int yajirusi;
	int ancientBGM;
	int modernBGM;
	int futureBGM;
	int overBGM;

	int volume = 200;

	int keyCount = 0;
	bool changeFlag = false;
	bool backFlag = false;
	bool flagCount = false;
	bool createFlag = false;
	bool invincibleFlag = false;
	bool start = true;
	bool hitButton = false;
	bool loadFlag = false;
	int invincibleTime = 0;
};

