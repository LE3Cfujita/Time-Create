#pragma once
#include <DirectXMath.h>

#define _USE_MATH_DEFINES
#include"math.h"

using namespace DirectX;
class GameObject
{
public:
	enum OBJECTMEMBER
	{
		PLAYER,
		NONEMEMBER,
	};

protected:
	bool deathFlag;
	OBJECTMEMBER objectMember;
public:

	GameObject() {}
	virtual ~GameObject() {
		//std::vector<GameObject*>().swap(addGameObjects);
	}
	void BaseInitialize(std::vector<GameObject*> referenceGameObjects)
	{
		objectMember = OBJECTMEMBER::NONEMEMBER;

		deathFlag = false;



		std::vector<GameObject*>().swap(addGameObjects);
		this->referenceGameObjects = referenceGameObjects;
	}
	//èâä˙âª
	virtual void Initialize() {}

	virtual void Update() {}

	virtual void Draw() {}

	
	std::vector<GameObject*> addGameObjects;

	std::vector<GameObject*> referenceGameObjects;

	OBJECTMEMBER GetObjectMember() { return objectMember; }
	bool GetDeathFlag() { return deathFlag; }
};

