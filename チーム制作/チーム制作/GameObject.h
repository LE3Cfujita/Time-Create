#pragma once
#include <DirectXMath.h>
#define _USE_MATH_DEFINES
#include"math.h"
#include <vector>
#include"DxLib.h"

using namespace DirectX;
class GameObject
{
public:
	enum OBJECTMEMBER
	{
		NONEMEMBER,//èâä˙
		PLAYER,//ÉvÉåÉCÉÑÅ[
		PLAYERBULLET,//íe
	};
	enum OBJECTSTATE
	{
		ANCIENT,//å√ë„
		MODERN,//åªë„
		FUTURE,//ñ¢óà
	};


protected:
	bool deathFlag;
	OBJECTMEMBER objectMember;
	OBJECTSTATE objectState;
	XMFLOAT2 position;
	float r;

public:
	GameObject() {}
	virtual ~GameObject() {
		//std::vector<GameObject*>().swap(addGameObjects);
	}
	void BaseInitialize(std::vector<GameObject*> referenceGameObjects)
	{
		objectMember = OBJECTMEMBER::NONEMEMBER;
		objectState = OBJECTSTATE::ANCIENT;

		deathFlag = false;
		position = { 0,0 };

		r = 32;


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
	OBJECTSTATE GetObjectState() { return objectState; }
	bool GetDeathFlag() { return deathFlag; }
};

