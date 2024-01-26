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

	gameState = PLAY;

	objectAge = THIRDSTAGE;
	createFlag = false;

	if (loadFlag != false)return;
	LoadResource();
	if (CheckSoundMem(titleBGM) == false)
	{
		PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
	}

	{//デバッグ用
		PlayerCreate();
		EnemyCreate();
	}
}

void GameScene::Update()
{
	switch (gameState)
	{
	case TITLE:
		if (CheckSoundMem(titleBGM) == false)
		{
			PlaySoundMem(titleBGM, DX_PLAYTYPE_LOOP, TRUE);
		}
		ChangeScene();
		break;
	case PLAY:
		BackgroundScroll();
		Invincible();
		changeForm();
		gameObjectManager->Update();
		SceneChange();
		break;
	case CLEA://�N���A
		if (CheckSoundMem(clearBGM) == false)
		{
			PlaySoundMem(clearBGM, DX_PLAYTYPE_LOOP, TRUE);
		}
		ChangeScene();
		break;
	case OVER:
		StopSoundFile();
		ChangeScene();
		break;
	case EXPLANATION:
		ChangeScene();
		break;
	}
}

void GameScene::Draw()
{
	switch (gameState)
	{
	case TITLE:
		DrawGraph(0, 0, title, TRUE);
		break;
	case PLAY://�Q�[���v���C
		DrawGraph(backPos.x, backPos.y, ancientback, true);
		DrawGraph(backPos2.x, backPos2.y, ancientback, true);
		gameObjectManager->Draw();
		if (changeFlag == true)//objectAge == FIRSTSTAGE
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
	case EXPLANATION:
		DrawGraph(setumeiPos.x, setumeiPos.y, setumei, true);
		break;
	}

}

void GameScene::ChangeScene()
{
	backPos.x -= 5;
	backPos2.x -= 5;
	backPos3.x -= 5;
	if (backPos.x <= -1280)
	{
		backPos.x = 1280;
	}
	if (backPos2.x <= -1280)
	{
		backPos2.x = 1280;
	}

	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		if (keyCount == false)
		{
			if (CheckSoundMem(ketteiSE) == FALSE)
			{
				PlaySoundMem(ketteiSE, DX_PLAYTYPE_BACK, TRUE);
			}
			if (gameState == TITLE)
			{
				gameState = EXPLANATION;
			}
			else if (gameState == EXPLANATION)
			{
				flagCount = false;
				volume = 200;
				gameState = PLAY;
				objectAge = FIRSTSTAGE;
				StopSoundMem(titleBGM);
				PlayerCreate();
				backPos = { 0,0 };
				backPos2 = { 1280,0 };
				backPos3 = { 2569,0 };
			}
			else if (gameState == CLEA || gameState == OVER)
			{
				for (GameObject* gameobject : gameObjectManager->GetGameObjects())
				{
					gameobject->SetDeathFlag(true);
				}
				pNumber = 0;
				sNumber = 0;
				gameState = TITLE;
				gameObjectManager->Update();
				if (CheckSoundMem(clearBGM) == true)
				{
					StopSoundMem(clearBGM);
				}
				if (CheckSoundMem(overBGM) == true)
				{
					StopSoundMem(overBGM);
				}
				overFlag = false;
				Initialize();
			}
			keyCount = true;
		}
	}
	else
	{
		keyCount = false;
	}

}

void GameScene::PlayerCreate()
{
	//プレイヤー生成
	for (int i = 0; i < 5; i++)
	{
		Player* player = nullptr;
		player = new Player();
		player->BaseInitialize(gameObjectManager->GetGameObjects());
		player->Initialize({ (float)300,(float)200 + 100 * i }, i);
		player->Resource(playerGraph, pAttack, kirikae, pDamage, recoverySE);
		pNumber++;
		gameObjectManager->AddGameObject(player);
	}
	EnemyCreate();
	BGM();
}

void GameScene::EnemyCreate()
{
	//敵生成

	if (createFlag == true)return;
	if (objectAge == FIRSTSTAGE)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				Enemy* enemy = nullptr;
				enemy = new Enemy();
				enemy->BaseInitialize(gameObjectManager->GetGameObjects());
				enemy->Initialize({ (float)720 + 100 * x,(float)-100 - 100 * y }, y);
				enemy->Resource(slimeGraph, eDamage, eAttack);
				gameObjectManager->AddGameObject(enemy);
				sNumber++;
			}
		}
	}
	else if (objectAge == SECONDSTAGE)
	{
		BossEnemy* enemy = nullptr;
		enemy = new BossEnemy();
		enemy->BaseInitialize(gameObjectManager->GetGameObjects());
		enemy->Initialize({ (float)1500,(float)300 });
		enemy->Resource(bossGraph, eDamage, eAttack, slimeGraph);
		gameObjectManager->AddGameObject(enemy);
	}
	else if (objectAge == THIRDSTAGE)
	{
		RecoveryEnemy* enemy = nullptr;
		enemy = new RecoveryEnemy();
		enemy->BaseInitialize(gameObjectManager->GetGameObjects());
		enemy->Initialize({ (float)1100,(float)300 });
		enemy->Resource(recoveryBullet);
		gameObjectManager->AddGameObject(enemy);
		for (int i = 1; i <= 3; i++)
		{
			//障害物生成
			Obstacle* obstacle = nullptr;
			obstacle = new Obstacle();
			obstacle->BaseInitialize(gameObjectManager->GetGameObjects());
			obstacle->Initialize({ (float)900 + 32,(float)0 + 32 * i });
			obstacle->Resource(obstacleGraph);
			gameObjectManager->AddGameObject(obstacle);
		}
		for (int i = 1; i <= 3; i++)
		{
			//障害物生成
			Obstacle* obstacle = nullptr;
			obstacle = new Obstacle();
			obstacle->BaseInitialize(gameObjectManager->GetGameObjects());
			obstacle->Initialize({ (float)900 + 32,(float)752 - 32 * i });
			obstacle->Resource(obstacleGraph);
			gameObjectManager->AddGameObject(obstacle);
		}
	}
	else if (objectAge == FORTHSTAGE)
	{
		for (int i = 1; i <= 2; i++)
		{
			SimultaneousEnemy* enemy = nullptr;
			enemy = new SimultaneousEnemy();
			enemy->BaseInitialize(gameObjectManager->GetGameObjects());
			enemy->Initialize({ (float)1500,(float)300 }, i);
			enemy->Resource(recoveryBullet);
			gameObjectManager->AddGameObject(enemy);
		}
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j < 2; j++)
			{
				//障害物生成
				Obstacle* obstacle = nullptr;
				obstacle = new Obstacle();
				obstacle->BaseInitialize(gameObjectManager->GetGameObjects());
				obstacle->Initialize({ (float)900 + 32 * j,(float)50 + 140 * i });
				obstacle->Resource(obstacleGraph);
				gameObjectManager->AddGameObject(obstacle);
			}
		}
	}
	createFlag = true;
}

void GameScene::GameOver(GameObject* gameObject)
{
	if (gameObject->GetObjectMember() == GameObject::OBJECTMEMBER::PLAYER)
	{
		if (gameObject->GetRecoveryFlag() == true)
		{
			pNumber = 5;
			gameObject->SetRecoveryFlag(false);
		}
		if (gameObject->GetObjectState() == GameObject::OBJSTATE::TENTATIVE)
		{
			//ゲームオーバー
			int count = gameObject->GetDeathCount();
			pNumber -= count;
			gameObject->SetDeathCount(0);
			if (pNumber == 0)
			{
				if (CheckSoundMem(playBGM) == 1)
				{
					StopSoundMem(playBGM);
				}
				gameState = OVER;
				backPos = { 0,0 };
				backPos2 = { 1280,0 };
				backPos3 = { 2560,0 };
				if (overFlag == false)
				{
					PlaySoundMem(overBGM, DX_MOVIEPLAYTYPE_NORMAL, TRUE);
					overFlag = true;
				}
			}
		}
	}
}

void GameScene::NextWave(GameObject* gameObject)
{//次のステージ
	if (gameObject->GetObjectMember() == GameObject::OBJECTMEMBER::SLIME)
	{
		if (gameObject->GetObjectState() == GameObject::OBJSTATE::DEATH)
		{
			int count = gameObject->GetDeathCount();
			sNumber -= count;
			gameObject->SetDeathFlag(true);
			if (sNumber != 0)return;
			changeFlag = true;
		}
	}
	else if (gameObject->GetObjectMember() == GameObject::OBJECTMEMBER::BOSSENEMY)
	{
		if (gameObject->GetObjectState() == GameObject::OBJSTATE::DEATH)
		{
			gameObject->SetDeathFlag(true);
			changeFlag = true;
		}
	}
	else if (gameObject->GetObjectMember() == GameObject::OBJECTMEMBER::RECOVERYENEMY)
	{
		if (gameObject->GetObjectState() == GameObject::OBJSTATE::DEATH)
		{
			gameObject->SetDeathFlag(true);
			changeFlag = true;
		}
	}
	else if (gameObject->GetObjectMember() == GameObject::OBJECTMEMBER::SIMULTANEOUSENEMY)
	{
		if (gameObject->GetObjectState() == GameObject::OBJSTATE::DEATH)
		{
			gameObject->SetDeathFlag(true);
			changeFlag = true;
		}
	}
}

void GameScene::GameClearToManager(GameObject* gameObject)
{
	if (backFlag == true)
	{
		backFlag = false;
		changeFlag = false;
		if (objectAge == FORTHSTAGE)//ゲームクリア
		{
			gameState = CLEA;
			changePos.x = 1280;
			if (CheckSoundMem(playBGM) == 1)
			{
				StopSoundMem(playBGM);
			}
		}
		else
		{
			for (GameObject* gameobject2 : gameObjectManager->GetGameObjects())
			{
				if (gameobject2->GetObjectMember() != GameObject::OBJECTMEMBER::PLAYER)
				{
					gameobject2->SetDeathFlag(true);//プレイヤーの一時破壊
				}
			}
			if (objectAge == FIRSTSTAGE)
			{
				objectAge = SECONDSTAGE;//1ステージ目だったら2ステージ目へ
				gameObject->SetObjAge(GameObject::STAGE::SECONDSTAGE);
			}
			else if (objectAge == SECONDSTAGE)
			{
				objectAge = THIRDSTAGE;//2ステージ目だったら3ステージ目へ
				gameObject->SetObjAge(GameObject::STAGE::THIRDSTAGE);
			}
			else if (objectAge == THIRDSTAGE)
			{
				objectAge = FORTHSTAGE;//3ステージ目だったら4ステージ目へ
				gameObject->SetObjAge(GameObject::STAGE::FORTHSTAGE);
			}
			createFlag = false;
			flagCount = false;
			EnemyCreate();
			changePos.x = 1280;
		}
		gameObjectManager->Update();
	}
	if (changePos.x <= 0)
	{
		if (flagCount == false)
		{
			backFlag = true;
			flagCount = true;
		}
	}
}

void GameScene::SceneChange()
{
	for (GameObject* gameobject : gameObjectManager->GetGameObjects())
	{
		GameOver(gameobject);//ゲームオーバー
		NextWave(gameobject);//次のウェーブ
		GameClearToManager(gameobject);//ゲームクリアとゲームシーンクラスのウェーブ管理
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

	PlaySoundMem(playBGM, DX_PLAYTYPE_LOOP, TRUE);
}

void GameScene::LoadResource()
{
	//背景絵
	title = LoadGraph("Resource/title.png"); // �`��
	ancientback = LoadGraph("Resource/background.png"); // �`��
	changeback = LoadGraph("Resource/ageChange.png");
	clear = LoadGraph("Resource/GameClear.png"); // �`��
	over = LoadGraph("Resource/GameOver.png"); // �`��
	yajirusi = LoadGraph("Resource/sentaku.png"); // �`��
	setumei = LoadGraph("Resource/setumei.png"); // �`��

	//キャラクター絵
	playerGraph = LoadGraph("Resource/player.png");
	slimeGraph = LoadGraph("Resource/EnemySlimeAnime.png");
	bossGraph = LoadGraph("Resource/bossEnemy.png");
	recoveryGraph = LoadGraph("Resource/recovery.png");
	//障害物
	obstacleGraph = LoadGraph("Resource/obstacle.png");
	//弾絵
	recoveryBullet = LoadGraph("Resource/enemyBullret.png");

	//音関係
	titleBGM = LoadSoundMem("Resource/titleBGM.mp3");
	overBGM = LoadSoundMem("Resource/overBGM.mp3");
	clearBGM = LoadSoundMem("Resource/clearBGM.mp3");
	playBGM = LoadSoundMem("Resource/gameplayBGM.mp3");
	ketteiSE = LoadSoundMem("Resource/kettei.mp3");
	pAttack = LoadSoundMem("Resource/playerBullet.mp3");
	eAttack = LoadSoundMem("Resource/enemyBullet.mp3");
	kirikae = LoadSoundMem("Resource/playerkirikae.mp3");
	pDamage = LoadSoundMem("Resource/playerHit.mp3");
	eDamage = LoadSoundMem("Resource/enemyHit.mp3");
	recoverySE = LoadSoundMem("Resource/recoverySE.mp3");

	loadFlag = true;
	volume = 50;
	ChangeVolumeSoundMem(volume, titleBGM);
	ChangeVolumeSoundMem(volume, overBGM);
	ChangeVolumeSoundMem(volume, clearBGM);
	ChangeVolumeSoundMem(volume, playBGM);
	ChangeVolumeSoundMem(volume, ketteiSE);
	ChangeVolumeSoundMem(volume, pAttack);
	ChangeVolumeSoundMem(volume, eAttack);
	ChangeVolumeSoundMem(volume, kirikae);
	ChangeVolumeSoundMem(100, pDamage);
	ChangeVolumeSoundMem(volume, eDamage);
	ChangeVolumeSoundMem(100, recoverySE);
}

void GameScene::changeForm()
{
	if (CheckHitKey(KEY_INPUT_E) == 1)
	{
		for (GameObject* gameobject : gameObjectManager->GetGameObjects())
		{
			if (gameobject->GetObjectMember() != GameObject::OBJECTMEMBER::PLAYER)continue;
			if (hitButton != false)return;
			gameobject->changeForm(formPos);
		}
		hitButton = true;
	}
	else
	{
		hitButton = false;
		for (GameObject* gameobject : gameObjectManager->GetGameObjects())
		{
			if (gameobject->GetObjectMember() != GameObject::OBJECTMEMBER::PLAYER)continue;
			int num = gameobject->GetNumber();
			if (num == 2)
			{
				formPos = gameobject->GetPosition();
			}
		}
	}
}
