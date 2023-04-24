#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::vector<GameObject*>().swap(gameObjects);
}

void GameObjectManager::Intialize()
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->BaseInitialize(gameObjects);
		gameObject->Initialize();
	}
}

void GameObjectManager::Update()
{
	//追加したいオブジェクトを一時的に保管する変数
	std::vector<GameObject*> addGameObjects;

	//全てのゲームオブジェクトを回す
	for (int i = 0; i < gameObjects.size(); i++)
	{
		//参照用のゲームオブジェクトを代入
		gameObjects[i]->referenceGameObjects = gameObjects;
		gameObjects[i]->Update();

		#pragma region 衝突判定ここから

		for (int j = 0; j < gameObjects.size(); j++)
		{
			//for文のiとjが同じなら抜け,次のgameObjectへ
			if (i == j)
				continue;

			#pragma region 説明用変数ここから
			const XMFLOAT2 axPosition = { gameObjects[i]->GetPosition() };	//オブジェクトAのx成分ポジション
			const XMFLOAT2 ayPosition = { gameObjects[i]->GetPosition() };	//オブジェクトAのy成分ポジション
			const XMFLOAT2 axVelocity = { gameObjects[i]->GetVelocity().x, 0.0f};	//オブジェクトAのx成分移動量
			const XMFLOAT2 ayVelocity = { 0.0f, gameObjects[i]->GetVelocity().y};	//オブジェクトAのy成分移動量
			const float aRadius = gameObjects[i]->GetRadius();	//オブジェクトAの半径
			const bool aPhysicsFlag = gameObjects[i]->GetPhysicsFlag();	//オブジェクトAの物理的判定フラグ
			const XMFLOAT2 velocityXNone = { 0.0f, gameObjects[i]->GetVelocity().y};	//オブジェクトAのx成分移動量を0にする
			const XMFLOAT2 velocityYNone = { gameObjects[i]->GetVelocity().x, 0.0f};	//オブジェクトAのy成分移動量を0にする
			const XMFLOAT2 bxPosition = { gameObjects[j]->GetPosition() };	//オブジェクトBのx成分ポジション
			const XMFLOAT2 byPosition = { gameObjects[j]->GetPosition() };	//オブジェクトBのy成分ポジション
			const float bRadius = gameObjects[j]->GetRadius();	//オブジェクトBの半径
			const bool bPhysicsFlag = gameObjects[j]->GetPhysicsFlag();	//オブジェクトBの物理的判定フラグ
			#pragma endregion ここまで

			//衝突判定_x成分
			bool hitFlag = false;
			if (((powf((axPosition.x + axVelocity.x - bxPosition.x), 2)) + (powf((ayPosition.y - byPosition.y), 2))) <=
				(powf(aRadius + bRadius, 2)))
			{
				if (aPhysicsFlag && bPhysicsFlag)
				{
					gameObjects[i]->SetVelocity(velocityXNone);
				}
				hitFlag = true;
			}
			//衝突判定_y成分
			if (((powf((axPosition.x - bxPosition.x), 2)) + (powf((ayPosition.y + ayVelocity.y - byPosition.y), 2))) <=
				(powf(aRadius + bRadius, 2)))
			{
				if (aPhysicsFlag && bPhysicsFlag)
				{
					gameObjects[i]->SetVelocity(velocityYNone);
				}
				hitFlag = true;
			}

			if (hitFlag == true)
			{
				gameObjects[i]->SetActionFlag(gameObjects[i]->GetActionFlag());
				gameObjects[i]->HitAction(gameObjects[j]);
			}
		}

		#pragma endregion ここまで

		//追加したいゲームオブジェクトがあれば
		if (gameObjects[i]->addGameObjects.size() != 0)
		{
			for (GameObject* addGameObject : gameObjects[i]->addGameObjects)
			{
				//追加したいゲームオブジェクトを一時的な変数に代入する
				addGameObjects.push_back(addGameObject);
			}
		}
		//一回だけ追加したいので追加したいゲームオブジェクトの配列を空にする
		std::vector<GameObject*>().swap(gameObjects[i]->addGameObjects);
	}

	//追加したいゲームオブジェクトを本体に追加する
	for (GameObject* addGameObject : addGameObjects)
	{
		AddGameObject(addGameObject);
	}

	std::vector<GameObject*>().swap(addGameObjects);

	//配列の最初から最後まで調べ、deathFlagがtrueのオブジェクトを配列の前に持ってくる
	auto it = std::partition(gameObjects.begin(), gameObjects.end(), [](GameObject* gameObject)
		{ return gameObject->GetDeathFlag() == true; });

	//前に持ってきたオブジェクトをdeleteして解放処理をする
	std::for_each(gameObjects.begin(), it, [](GameObject* gameObject) {delete gameObject; });
	gameObjects.erase(gameObjects.begin(), it);
}

void GameObjectManager::Draw()
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw();
	}
}

void GameObjectManager::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}
