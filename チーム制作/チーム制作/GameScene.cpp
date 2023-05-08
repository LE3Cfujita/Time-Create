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
	back=LoadGraph("Resource/futurenack.png"); // �`��
}

void GameScene::Update()
{
	switch (gameState)
	{
	case TITLE://�^�C�g��
		ChangeScene();
		break;
	case PLAY://�Q�[���v���C
		backPos.x -= 5;
		backPos2.x -= 5;
		if (backPos.x <= -1280)
		{
			backPos.x = 1280;
		}
		if (backPos2.x <= -1280)
		{
			backPos2.x = 1280;
		}
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
		DrawGraph(backPos.x, backPos.y, back, true);
		DrawGraph(backPos2.x, backPos2.y, back, true);
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
