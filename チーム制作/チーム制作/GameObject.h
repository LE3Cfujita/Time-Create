#pragma once
#include <DirectXMath.h>
#include"math.h"
#include <vector>
#include"DxLib.h"

#define _USE_MATH_DEFINES
using namespace DirectX;
class GameObject
{
public:
	enum OBJECTMEMBER
	{
		NONEMEMBER,//初期
		PLAYER,//プレイヤー
		PLAYERBULLET,//プレイヤー弾
	};

	//キャラクターの時代
	enum OBJSTATE
	{
		AncientTimes,//古代
		ModernTime,//現代
		Future//未来
	};

protected:
	bool deathFlag;
	OBJECTMEMBER objectMember;
	OBJSTATE objState;

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
		objState = OBJSTATE::AncientTimes;

		deathFlag = false;

		position = { 0,0 };

		r = 12;

		std::vector<GameObject*>().swap(addGameObjects);
		this->referenceGameObjects = referenceGameObjects;
	}
	//初期化
	virtual void Initialize() {}

	virtual void Update() {}

	virtual void Draw() {}


	std::vector<GameObject*> addGameObjects;

	std::vector<GameObject*> referenceGameObjects;

	OBJECTMEMBER GetObjectMember() { return objectMember; }
	OBJSTATE GetObjectState() { return objState; }
	bool GetDeathFlag() { return deathFlag; }
};

