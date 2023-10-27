#pragma once
#include "GameObject.h"
#include "Player.h"
#include"Enemy.h"
#include"BossEnemy.h"
#include"RecoveryEnemy.h"
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
		STAND,
		FIRSTSTAGE,//1ステージ目
		SECONDSTAGE,//2ステージ目
		THIRDSTAGE,//3ステージ目
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

	void Invincible();

	void BGM();

	void LoadResource();

	void changeForm();

private:
	GameState gameState;
	OBJAGE objectAge;
	GameObjectManager* gameObjectManager = nullptr;
	Collision* collision = nullptr;

	XMFLOAT2 backPos = { 0,0 };
	XMFLOAT2 backPos2 = { 1280,0 };
	XMFLOAT2 backPos3 = { 2560,0 };
	XMFLOAT2 changePos = { 1280,0 };
	XMFLOAT2 setumeiPos = { 0,0 };
	XMFLOAT2 yajirusiPos = { 770,490 };

	XMFLOAT2 formPos = { 0,0 };//プレイヤーのフォーメーションチェンジ時に使う
	//背景絵
	int title;
	int ancientback;
	int changeback;
	int clear;
	int over;
	int setumei;
	int yajirusi;

	//キャラクター絵
	int playerGraph;//プレイヤー絵
	int slimeGraph;//スライム絵
	int bossGraph;
	int recoveryGraph;

	//弾絵
	int recoveryBullet;//スライムの弾の絵


	//音関係
	int titleBGM;
	int ancientBGM;
	int modernBGM;
	int futureBGM;
	int overBGM;
	int clearBGM;
	bool overFlag = false;
	int ketteiSE;
	int pAttack;
	int eAttack;
	int kirikae;
	int pDamage;
	int eDamage;

	int volume = 200;

	//変数
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

	int pNumber = 0;//プレイヤーの残り人数
	int sNumber = 0;//スライムの残り数
};

