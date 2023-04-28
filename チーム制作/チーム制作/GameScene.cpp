#include "GameScene.h"
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	gameObjectManager = new GameObjectManager();
	gameObjectManager->Intialize();

	gameState = TITLE;
	//�摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

	title=LoadGraph("Resource/TITLE.png"); // �`��
	back=LoadGraph("Resource/PlayeBack.png"); // �`��
}

void GameScene::Update()
{
	switch (gameState)
	{
	case TITLE://�^�C�g��
		ChangeScene();
		break;
	case PLAY://�Q�[���v���C
		gameObjectManager->Update();
		
		break;
	case CLEA://�N���A
		break;
	case OVER://�Q�[���I�[�o�[
		break;
	}
}

void GameScene::Draw()
{
	switch (gameState)
	{
	case TITLE://�^�C�g��
		DrawGraph(0, 0, title, FALSE);
		break;
	case PLAY://�Q�[���v���C
		DrawExtendGraph(0, 0,1280,720, back, FALSE);
		gameObjectManager->Draw();
		break;
	case CLEA://�N���A
		break;
	case OVER://�Q�[���I�[�o�[
		break;
	}

}

void GameScene::ChangeScene()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1&& keyCount==0)
	{
		gameState = PLAY;
		keyCount = 1;
		ObjCreate();
	}
	else
	{
		keyCount = 0;
	}

}

void GameScene::ObjCreate()
{
	//�v���C���[
	Player* player = nullptr;
	player = new Player();
	player->BaseInitialize(gameObjectManager->GetGameObjects());
	player->Initialize();
	gameObjectManager->AddGameObject(player);

	//�G
	Enemy* enemy = nullptr;
	enemy = new Enemy();
	enemy->BaseInitialize(gameObjectManager->GetGameObjects());
	enemy->Initialize();
	gameObjectManager->AddGameObject(enemy);
}
