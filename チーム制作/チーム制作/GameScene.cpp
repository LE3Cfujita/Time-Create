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
		PBCollision();
		Invincible();
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

void GameScene::PBCollision()
{
	if (invincibleFlag == false)
	{
		for (GameObject* gameobject : gameObjectManager->GetGameObjects())
		{
			if (gameobject->GetObjectMember() != GameObject::OBJECTMEMBER::PLAYER)continue;
			int HP = gameobject->GetHP();
			XMFLOAT2 pos = gameobject->GetPosition();
			float r = gameobject->GetRadius();
			XMFLOAT2 pos2 = { pos.x * 2,pos.y + r * 2 };
			for (GameObject* gameobject2 : gameObjectManager->GetGameObjects())
			{
				if (gameobject2->GetObjectMember() != GameObject::OBJECTMEMBER::ENEMYBEAM)continue;
				XMFLOAT2 epos = gameobject2->GetPosition();
				XMFLOAT2 epos2 = gameobject2->GetPosition2();
				if (pos.x <= epos.x && pos2.x > epos.x)
				{
					if (pos.y <= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP--);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos.y && pos2.y >= epos2.y)
					{
						gameobject->SetHP(HP--);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y>=epos2.y&&pos2.y<=epos.y)
					{
						gameobject->SetHP(HP--);
						invincibleFlag = true;
						break;
					}
				}
				else if (pos.x >= epos.x && pos.x <= epos2.x)
				{
					if (pos.y <= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP--);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos.y && pos2.y >= epos2.y)
					{
						gameobject->SetHP(HP--);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP--);
						invincibleFlag = true;
						break;
					}
				}
			}
		}
	}
}

void GameScene::Invincible()
{
	if (invincibleFlag == false)return;
	invincibleTime++;
	if (invincibleTime < 60)return;
	invincibleTime = 0;
	invincibleFlag = false;
}
