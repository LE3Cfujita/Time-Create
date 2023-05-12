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
private:
	GameState gameState;
	OBJAGE objectAge;
	GameObjectManager* gameObjectManager = nullptr;


	XMFLOAT2 backPos = { 0,0 };
	XMFLOAT2 backPos2 = { 1280,0 };
	XMFLOAT2 changePos = { 1280,0 };
	int title;
	int ancientback;
	int modernback;
	int futureback;
	int changeback;
	int clear;
	int over;
	int keyCount = 0;
	bool changeFlag = false;
	bool backFlag = false;
	bool flagCount = false;
	bool createFlag = false;
};

