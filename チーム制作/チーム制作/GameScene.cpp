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
	back=LoadGraph("Resource/PlayeBack.png"); // 描画
}

void GameScene::Update()
{
	switch (gameState)
	{
	case TITLE://タイトル
		ChangeScene();
		break;
	case PLAY://ゲームプレイ
		gameObjectManager->Update();
		
		break;
	case CLEA://クリア
		break;
	case OVER://ゲームオーバー
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
		DrawExtendGraph(0, 0,1280,720, back, FALSE);
		gameObjectManager->Draw();
		break;
	case CLEA://クリア
		break;
	case OVER://ゲームオーバー
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
