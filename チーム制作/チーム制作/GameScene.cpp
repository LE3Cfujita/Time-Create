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

	title = LoadGraph("Resource/TITLE.png"); // �`��
	ancientback = LoadGraph("Resource/ancientback.png"); // �`��
	modernback = LoadGraph("Resource/modernback.png"); // �`��
	futureback = LoadGraph("Resource/futurenack.png"); // �`��
	changeback = LoadGraph("Resource/ageChange.png");
	clear = LoadGraph("Resource/GameClear.png"); // �`��
	over = LoadGraph("Resource/GameOver.png"); // �`��
	objectAge == FUTURE;
	createFlag = false;
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
		if (objectAge == ANCIENT)
		{
			DrawGraph(backPos.x, backPos.y, ancientback, true);
			DrawGraph(backPos2.x, backPos2.y, ancientback, true);
		}
		if (objectAge == MODERN)
		{
			DrawGraph(backPos.x, backPos.y, modernback, true);
			DrawGraph(backPos2.x, backPos2.y, modernback, true);
		}
		if (objectAge == FUTURE)
		{
			DrawGraph(backPos.x, backPos.y, futureback, true);
			DrawGraph(backPos2.x, backPos2.y, futureback, true);
		}
		gameObjectManager->Draw();
		if (changeFlag == true)
		{
			DrawGraph(changePos.x, changePos.y, changeback, true);
		}

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
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && keyCount == 0)
	{
		if (gameState == TITLE)
		{
			gameState = PLAY;
			PlayerCreate();
		}
		else if (gameState == CLEA || gameState == OVER)
		{
			for (GameObject* gameobject : gameObjectManager->GetGameObjects())
			{
				gameobject->SetDeathFlag(true);
			}
			gameState = TITLE;
			gameObjectManager->Update();
			Initialize();
		}
		keyCount = 1;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 0)
	{
		keyCount = 0;
	}

}

void GameScene::PlayerCreate()
{
	//プレイヤー生成
	Player* player = nullptr;
	player = new Player();
	player->BaseInitialize(gameObjectManager->GetGameObjects());
	player->Initialize();
	gameObjectManager->AddGameObject(player);
	EnemyCreate();
}

void GameScene::EnemyCreate()
{
	//敵生成
	if (createFlag == true)return;
	Enemy* enemy = nullptr;
	enemy = new Enemy();
	enemy->BaseInitialize(gameObjectManager->GetGameObjects());
	enemy->Initialize();
	gameObjectManager->AddGameObject(enemy);
	createFlag = true;
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
			if (eHP == 0)
			{
				changeFlag = true;
			}
			if (backFlag == true)
			{
				if (gameobject->GetObjectAge() == GameObject::OBJAGE::ANCIENT)
				{
					objectAge = MODERN;
					for (GameObject* gameobject2 : gameObjectManager->GetGameObjects())
					{
						if (gameobject2->GetObjectMember() == GameObject::OBJECTMEMBER::PLAYER)
						{
							gameobject2->SetAnimation(0);
						}
						else
						{
							gameobject2->SetDeathFlag(true);
						}
					}
					createFlag = false;
					backFlag = false;
				}
				else if (gameobject->GetObjectAge() == GameObject::OBJAGE::MODERN)
				{
					objectAge = FUTURE;
					for (GameObject* gameobject2 : gameObjectManager->GetGameObjects())
					{
						if (gameobject2->GetObjectMember() == GameObject::OBJECTMEMBER::PLAYER)
						{
							gameobject2->SetAnimation(0);
						}
						else
						{
							gameobject2->SetDeathFlag(true);
						}
					}
					createFlag = false;
					backFlag = false;
				}
				else if (gameobject->GetObjectAge() == GameObject::OBJAGE::FUTURE)
				{
					gameState = CLEA;
					objectAge = ANCIENT;
					for (GameObject* gameobject2 : gameObjectManager->GetGameObjects())
					{
						gameobject2->SetDeathFlag(true);
					}
					createFlag = false;
					backFlag = false;
				}
				gameObjectManager->Update();
			}
		}
		if (changePos.x <= 0)
		{
			if (flagCount == false)
			{
				backFlag = true;
				flagCount = true;
			}
			if (objectAge == ANCIENT)
			{
				EnemyCreate();
				gameobject->SetObjAge(GameObject::OBJAGE::ANCIENT);
			}
			else if (objectAge == MODERN)
			{
				EnemyCreate();
				gameobject->SetObjAge(GameObject::OBJAGE::MODERN);
			}
			else if (objectAge == FUTURE)
			{
				EnemyCreate();
				gameobject->SetObjAge(GameObject::OBJAGE::FUTURE);
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
	if (changeFlag == false)return;
	changePos.x -= 30;
	if (changePos.x <= -1280)
	{
		changeFlag = false;
		flagCount = false;
		changePos.x = 1280;
	}
}
