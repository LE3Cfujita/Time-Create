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
		ANCIENT,//�Ñ�
		MODERN,//����
		FUTURE,//����
	};

public:
	/// <summary>
	/// �R���X�g�N���^
	/// </summary>
	GameScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

	void ChangeScene();//�V�[���؂�ւ�

	void PlayerCreate();

	void EnemyCreate();

	void SceneChange();//�Q�[�����V�[���؂�ւ�

	void BackgroundScroll();//�w�i�X�N���[��

	void PBCollision();

	void Invincible();

	void BGM();

private:
	GameState gameState;
	OBJAGE objectAge;
	GameObjectManager* gameObjectManager = nullptr;
	Collision* collision = nullptr;

	XMFLOAT2 backPos = { 0,0 };
	XMFLOAT2 backPos2 = { 1280,0 };
	XMFLOAT2 changePos = { 1280,0 };
	XMFLOAT2 yajirusiPos = { 450,480 };
	int title;
	int ancientback;
	int modernback;
	int futureback;
	int changeback;
	int clear;
	int over;
	int yajirusi;
	int ancientBGM;
	int modernBGM;
	int futureBGM;

	int volume = 255;

	int keyCount = 0;
	bool changeFlag = false;
	bool backFlag = false;
	bool flagCount = false;
	bool createFlag = false;
	bool invincibleFlag = false;
	bool start = true;
	bool hitButton = false;
	int invincibleTime = 0;
};

