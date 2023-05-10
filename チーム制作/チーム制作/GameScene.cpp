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
	ancientback = LoadGraph("Resource/ancientback.png"); // �`��
	modernback= LoadGraph("Resource/modernback.png"); // �`��
	futureback=LoadGraph("Resource/futurenack.png"); // �`��
	clear=LoadGraph("Resource/GameClear.png"); // �`��
	over=LoadGraph("Resource/GameOver.png"); // �`��
}

void GameScene::Update()
{
	switch (gameState)
	{
	case TITLE://�^�C�g��
		ChangeScene();
		break;
	case PLAY://�Q�[���v���C
		BackgroundScroll();
		gameObjectManager->Update();
		SceneChange();
		break;
	case CLEA://�N���A
		ChangeScene();
		break;
	case OVER://�Q�[���I�[�o�[
		ChangeScene();
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
		DrawGraph(backPos.x, backPos.y, modernback, true);
		DrawGraph(backPos2.x, backPos2.y, modernback, true);
		gameObjectManager->Draw();
		break;
	case CLEA://�N���A
		DrawGraph(0, 0, clear, FALSE);
		break;
	case OVER://�Q�[���I�[�o�[
		DrawGraph(0, 0, over, FALSE);
		break;
	}

}

void GameScene::ChangeScene()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1&& keyCount==0)
	{
		if (gameState == TITLE)
		{
			gameState = PLAY;
			ObjCreate();
		}
		else if (gameState == CLEA|| gameState == OVER)
		{
			for (GameObject* gameobject : gameObjectManager->GetGameObjects())
			{
				gameobject->SetDeathFlag(true);
			}
			gameState = TITLE;
			gameObjectManager->Update();
		}
		keyCount = 1;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 0)
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

void GameScene::SceneChange()
{
	int pHP = 0;
	int eHP = 0;
	for (GameObject* gameobject : gameObjectManager->GetGameObjects())
	{		
		if (gameobject->GetObjectMember() == GameObject::OBJECTMEMBER::PLAYER)
		{
			pHP = gameobject->GetHP();
			if (pHP == 0)
			{
				gameState = OVER;
			}
		}
		if (gameobject->GetObjectMember() == GameObject::OBJECTMEMBER::ENEMY)
		{
			eHP = gameobject->GetHP();
			if (eHP == 0 && gameobject->GetObjectAge() == GameObject::OBJAGE::ANCIENT)
			{
				objectAge = MODERN;
			}
			else if (eHP == 0 && gameobject->GetObjectAge() == GameObject::OBJAGE::MODERN)
			{
				objectAge = FUTURE;
			}
			else if (eHP == 0&&gameobject->GetObjectAge() == GameObject::OBJAGE::FUTURE)
			{
				gameState = CLEA;
				objectAge = ANCIENT;
			}
		}
		if (objectAge == ANCIENT)
		{
			gameobject->SetObjAge(GameObject::OBJAGE::ANCIENT);
		}
		else if (objectAge == MODERN)
		{
			gameobject->SetObjAge(GameObject::OBJAGE::MODERN);
		}
		else if (objectAge == FUTURE)
		{
			gameobject->SetObjAge(GameObject::OBJAGE::FUTURE);
		}
			if (eHP == 0&&gameobject->GetObjectAge() == GameObject::OBJAGE::FUTURE)
			{
				gameState = CLEA;
			}

		}

	}
	
}

void GameScene::BackgroundScroll()
{
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
}
