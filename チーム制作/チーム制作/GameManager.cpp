#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	std::vector<GameObject*>().swap(gameObjects);
}

void GameManager::Initialize()
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->BaseInitialize(gameObjects);
		gameObject->Initialize();
	}
}

void GameManager::Update()
{
	std::vector<GameObject*> addGameObjects;
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();

		gameObjects[i]->referenceGameObjects = gameObjects;

		if (gameObjects[i]->addGameObjects.size() != 0)//�ǉ��������Q�[���I�u�W�F�N�g�������
		{
			for (GameObject* addGameObject : gameObjects[i]->addGameObjects)
			{
				addGameObjects.push_back(addGameObject);//�ǉ��������I�u�W�F�N�g���ꎞ�I�ȕϐ��ɑ��
			}
		}
		std::vector<GameObject*>().swap(gameObjects[i]->addGameObjects);//�f�[�^�̓���ւ�
	}

	for (GameObject* addGameObject : addGameObjects)
	{
		AddGameObject(addGameObject);//�G���[��h������
	}
	std::vector<GameObject*>().swap(addGameObjects);

	auto it = std::partition(gameObjects.begin(), gameObjects.end(), [](GameObject* gameObject)
		{ return gameObject->GetDeathFlag() == true; });

	std::for_each(gameObjects.begin(), it, [](GameObject* gameObject) {delete gameObject; });
	gameObjects.erase(gameObjects.begin(), it);

}

void GameManager::Draw()
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw();
	}
}

void GameManager::AddGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}
