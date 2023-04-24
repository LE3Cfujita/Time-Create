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
	//�ǉ��������I�u�W�F�N�g���ꎞ�I�ɕۊǂ���ϐ�
	std::vector<GameObject*> addGameObjects;

	//�S�ẴQ�[���I�u�W�F�N�g����
	for (int i = 0; i < gameObjects.size(); i++)
	{
		//�Q�Ɨp�̃Q�[���I�u�W�F�N�g����
		gameObjects[i]->referenceGameObjects = gameObjects;
		gameObjects[i]->Update();

		#pragma region �Փ˔��肱������

		for (int j = 0; j < gameObjects.size(); j++)
		{
			//for����i��j�������Ȃ甲��,����gameObject��
			if (i == j)
				continue;

			#pragma region �����p�ϐ���������
			const XMFLOAT2 axPosition = { gameObjects[i]->GetPosition() };	//�I�u�W�F�N�gA��x�����|�W�V����
			const XMFLOAT2 ayPosition = { gameObjects[i]->GetPosition() };	//�I�u�W�F�N�gA��y�����|�W�V����
			const XMFLOAT2 axVelocity = { gameObjects[i]->GetVelocity().x, 0.0f};	//�I�u�W�F�N�gA��x�����ړ���
			const XMFLOAT2 ayVelocity = { 0.0f, gameObjects[i]->GetVelocity().y};	//�I�u�W�F�N�gA��y�����ړ���
			const float aRadius = gameObjects[i]->GetRadius();	//�I�u�W�F�N�gA�̔��a
			const bool aPhysicsFlag = gameObjects[i]->GetPhysicsFlag();	//�I�u�W�F�N�gA�̕����I����t���O
			const XMFLOAT2 velocityXNone = { 0.0f, gameObjects[i]->GetVelocity().y};	//�I�u�W�F�N�gA��x�����ړ��ʂ�0�ɂ���
			const XMFLOAT2 velocityYNone = { gameObjects[i]->GetVelocity().x, 0.0f};	//�I�u�W�F�N�gA��y�����ړ��ʂ�0�ɂ���
			const XMFLOAT2 bxPosition = { gameObjects[j]->GetPosition() };	//�I�u�W�F�N�gB��x�����|�W�V����
			const XMFLOAT2 byPosition = { gameObjects[j]->GetPosition() };	//�I�u�W�F�N�gB��y�����|�W�V����
			const float bRadius = gameObjects[j]->GetRadius();	//�I�u�W�F�N�gB�̔��a
			const bool bPhysicsFlag = gameObjects[j]->GetPhysicsFlag();	//�I�u�W�F�N�gB�̕����I����t���O
			#pragma endregion �����܂�

			//�Փ˔���_x����
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
			//�Փ˔���_y����
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

		#pragma endregion �����܂�

		//�ǉ��������Q�[���I�u�W�F�N�g�������
		if (gameObjects[i]->addGameObjects.size() != 0)
		{
			for (GameObject* addGameObject : gameObjects[i]->addGameObjects)
			{
				//�ǉ��������Q�[���I�u�W�F�N�g���ꎞ�I�ȕϐ��ɑ������
				addGameObjects.push_back(addGameObject);
			}
		}
		//��񂾂��ǉ��������̂Œǉ��������Q�[���I�u�W�F�N�g�̔z�����ɂ���
		std::vector<GameObject*>().swap(gameObjects[i]->addGameObjects);
	}

	//�ǉ��������Q�[���I�u�W�F�N�g��{�̂ɒǉ�����
	for (GameObject* addGameObject : addGameObjects)
	{
		AddGameObject(addGameObject);
	}

	std::vector<GameObject*>().swap(addGameObjects);

	//�z��̍ŏ�����Ō�܂Œ��ׁAdeathFlag��true�̃I�u�W�F�N�g��z��̑O�Ɏ����Ă���
	auto it = std::partition(gameObjects.begin(), gameObjects.end(), [](GameObject* gameObject)
		{ return gameObject->GetDeathFlag() == true; });

	//�O�Ɏ����Ă����I�u�W�F�N�g��delete���ĉ������������
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
