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
	//画像などのリソースデータの変数宣言と読み込み

	title=LoadGraph("Resource/TITLE.png"); // 描画
	ancientback = LoadGraph("Resource/ancientback.png"); // 描画
	modernback= LoadGraph("Resource/modernback.png"); // 描画
	futureback=LoadGraph("Resource/futurenack.png"); // 描画
	clear=LoadGraph("Resource/GameClear.png"); // 描画
	over=LoadGraph("Resource/GameOver.png"); // 描画
}

void GameScene::Update()
{
	switch (gameState)
	{
	case TITLE://タイトル
		ChangeScene();
		break;
	case PLAY://ゲームプレイ
		BackgroundScroll();
		gameObjectManager->Update();
		SceneChange();
		break;
	case CLEA://クリア
		ChangeScene();
		break;
	case OVER://ゲームオーバー
		ChangeScene();
		break;
	}
}

void GameScene::Draw()
{
	switch (gameState)
	{
	case TITLE://タイトル
		DrawGraph(0, 0, title, FALSE);
		break;
	case PLAY://ゲームプレイ
		DrawGraph(backPos.x, backPos.y, modernback, true);
		DrawGraph(backPos2.x, backPos2.y, modernback, true);
		gameObjectManager->Draw();
		break;
	case CLEA://クリア
		DrawGraph(0, 0, clear, FALSE);
		break;
	case OVER://ゲームオーバー
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
	//プレイヤー
	Player* player = nullptr;
	player = new Player();
	player->BaseInitialize(gameObjectManager->GetGameObjects());
	player->Initialize();
	gameObjectManager->AddGameObject(player);

	//敵
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
