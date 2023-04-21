#include "GameScene.h"
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	gameObjectManager = new GameManager();
	gameObjectManager->Initialize();
	//画像などのリソースデータの変数宣言と読み込み

	Player* player = nullptr;
	player = new Player();
	player->BaseInitialize(gameObjectManager->GetGameObjects());
	player->Initialize();
	gameObjectManager->AddGameObject(player);
}

void GameScene::Update()
{
	gameObjectManager->Update();
}

void GameScene::Draw()
{
	gameObjectManager->Draw();
}
