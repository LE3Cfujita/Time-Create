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
	yajirusi = LoadGraph("Resource/sentaku.png"); // �`��

	ancientBGM = LoadSoundMem("Resource/ancientBGM.mp3");
	modernBGM = LoadSoundMem("Resource/modernBGM.mp3");
	futureBGM = LoadSoundMem("Resource/Shining_star.mp3");
	overBGM = LoadSoundMem("Resource/failed.mp3");

	objectAge = ANCIENT;
	createFlag = false;
}

void GameScene::Update()
{
	switch (gameState)
	{
	case TITLE:
		ChangeScene();
		break;
	case PLAY:
		BGM();
		BackgroundScroll();
		PBCollision();
		Invincible();
		gameObjectManager->Update();
		SceneChange();
		break;
	case CLEA://�N���A
		ChangeScene();
		break;
	case OVER:
		StopSoundFile();
		ChangeScene();
		break;
	case EXPLANATION:
		break;
	}
}

void GameScene::Draw()
{
	switch (gameState)
	{
	case TITLE://�^�C�g��
		DrawGraph(0, 0, title, FALSE);
		DrawGraph(yajirusiPos.x, yajirusiPos.y, yajirusi, FALSE);
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
	case EXPLANATION:

		break;
	}

}

void GameScene::ChangeScene()
{
	if (CheckHitKey(KEY_INPUT_UP) == 1 && hitButton == false ||
		CheckHitKey(KEY_INPUT_DOWN) == 1 && hitButton == false)
	{
		if (start == true)
		{
			start = false;
			yajirusiPos = { 450,560 };
		}
		else
		{
			start = true;
			yajirusiPos = { 450,480 };
		}
		hitButton = true;
	}
	else if (CheckHitKey(KEY_INPUT_UP) == 0 &&
		CheckHitKey(KEY_INPUT_DOWN) == 0)
	{
		hitButton = false;
	}

	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && keyCount == 0)
	{
		if (gameState == TITLE)
		{
			if (start = true)
			{
				gameState = PLAY;
				PlayerCreate();
			}
			else
			{
				gameState = EXPLANATION;
			}
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
			if (pHP <= 0)
			{
				if (objectAge == ANCIENT && CheckSoundMem(ancientBGM) == 1)
				{
					StopSoundMem(ancientBGM);
				}
				else if (objectAge == MODERN && CheckSoundMem(modernBGM) == 1)
				{
					StopSoundMem(modernBGM);
				}
				else if (objectAge == FUTURE && CheckSoundMem(futureBGM) == 1)
				{
					StopSoundMem(futureBGM);
				}
				gameState = OVER;
				PlaySoundMem(overBGM, DX_PLAYTYPE_LOOP, TRUE);
			}
		}
		if (gameobject->GetObjectMember() == GameObject::OBJECTMEMBER::ENEMY)
		{
			eHP = gameobject->GetHP();
			if (eHP <= 0)
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
							gameobject2->SetPosition({ 300, 300 });
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
							gameobject2->SetPosition({ 300, 300 });
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
			if (changePos.x >= -30)
			{
				StopSoundMem(ancientBGM);
				StopSoundMem(modernBGM);
				StopSoundMem(futureBGM);
			}
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
	volume -= 3;
	changePos.x -= 30;
	if (changePos.x <= -1280)
	{
		changeFlag = false;
		flagCount = false;
		changePos.x = 1280;
	}
	ChangeVolumeSoundMem(volume, ancientBGM);
	ChangeVolumeSoundMem(volume, modernBGM);
	ChangeVolumeSoundMem(volume, futureBGM);
	ChangeVolumeSoundMem(volume, overBGM);
}

void GameScene::PBCollision()
{
	for (GameObject* gameobject : gameObjectManager->GetGameObjects())
	{
		if (gameobject->GetObjectMember() != GameObject::OBJECTMEMBER::PLAYER)continue;
		XMFLOAT2 pos = gameobject->GetPosition();
		float r = gameobject->GetRadius();
		XMFLOAT2 pos2 = { pos.x + r * 2,pos.y + r * 2 };
		int HP = gameobject->GetHP();
		for (GameObject* gameobject2 : gameObjectManager->GetGameObjects())
		{
			if (gameobject2->GetObjectMember() != GameObject::OBJECTMEMBER::ENEMYBEAM)continue;
			XMFLOAT2 epos = gameobject2->GetPosition();
			XMFLOAT2 epos2 = gameobject2->GetPosition2();

			if (invincibleFlag == false)
			{
				if (pos.x <= epos.x && pos2.x > epos.x)
				{
					if (pos.y <= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos.y && pos2.y >= epos2.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
				}
				if (pos.x >= epos.x && pos.x <= epos2.x &&
					pos2.x<epos.x && pos2.x>epos2.x)
				{
					if (pos.y <= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos.y && pos2.y >= epos2.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
				}
				if (pos.x >= epos.x && pos.x <= epos2.x &&
					pos2.x >= epos.x && pos2.x <= epos2.x)
				{
					if (pos.y <= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos.y && pos2.y >= epos2.y)
					{
						gameobject->SetHP(HP - 1);
						invincibleFlag = true;
						break;
					}
					if (pos.y >= epos2.y && pos.y <= epos.y &&
						pos2.y >= epos2.y && pos2.y <= epos.y)
					{
						gameobject->SetHP(HP - 1);
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
	if (invincibleFlag != true)return;
	invincibleTime++;
	if (invincibleTime < 20)return;
	invincibleTime = 0;
	invincibleFlag = false;
}

void GameScene::BGM()
{
	if (objectAge == ANCIENT && CheckSoundMem(ancientBGM) == 0)
	{
		PlaySoundMem(ancientBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
	else if (objectAge == MODERN && CheckSoundMem(modernBGM) == 0)
	{
		PlaySoundMem(modernBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
	else if (objectAge == FUTURE && CheckSoundMem(futureBGM) == 0)
	{
		PlaySoundMem(futureBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
	if (volume <= 0)
	{
		volume = 200;
	}
}
