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
		FIRSTSTAGE,//1�X�e�[�W��
		SECONDSTAGE,//2�X�e�[�W��
		THIRDSTAGE,//3�X�e�[�W��
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

	XMFLOAT2 formPos = { 0,0 };//�v���C���[�̃t�H�[���[�V�����`�F���W���Ɏg��
	//�w�i�G
	int title;
	int ancientback;
	int changeback;
	int clear;
	int over;
	int setumei;
	int yajirusi;

	//�L�����N�^�[�G
	int playerGraph;//�v���C���[�G
	int slimeGraph;//�X���C���G
	int bossGraph;
	int recoveryGraph;

	//�e�G
	int recoveryBullet;//�X���C���̒e�̊G


	//���֌W
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

	//�ϐ�
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

	int pNumber = 0;//�v���C���[�̎c��l��
	int sNumber = 0;//�X���C���̎c�萔
};

