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
		NONEMEMBER,//初期
		PLAYER,//プレイヤー
		PLAYERBULLET,//プレイヤーの弾
		ENEMY,//敵
		ENEMYBULLET,//敵の弾(古代)
		ENEMYFIRE,//敵の火(古代)
		ENEMYBALKAN,//敵のバルカン(現代)
	};
	enum OBJAGE
	{
		ANCIENT,//古代
		MODERN,//現代
		FUTURE,//未来
	};
	enum OBJSTATE
	{
		IDLE,		//待機
		MOVE,		//移動
		ATTACK,		//攻撃
		DEATH,		//死亡
		ALIVE,		//生産
		NONESTATE,	//なし
	};

protected:
	bool deathFlag;
	OBJECTMEMBER objectMember;
	OBJAGE objectAge;
	OBJSTATE objState;
	XMFLOAT2 position;
	//移動量
	XMFLOAT2 vel;
	float r;//半径
	int color;//色
	//行動フラグ
	bool actionFlag;
	//物理的判定フラグ
	bool physicsFlag;

	bool timeFlag;//falseならまっすぐ打つ
	int time;


	float ancient;

	int number;

	double angle;

	float bulletSpeed;
public:
	GameObject() {}
	virtual ~GameObject() {
		//std::vector<GameObject*>().swap(addGameObjects);
	}
	void BaseInitialize(std::vector<GameObject*> referenceGameObjects)
	{
		objectMember = OBJECTMEMBER::NONEMEMBER;
		objectAge = OBJAGE::ANCIENT;
		objState = OBJSTATE::IDLE;

		deathFlag = false;
		position = { 0,0 };
		vel = { 0,0 };
		physicsFlag = false;
		actionFlag = false;
		r = 32;

		color = 0;

		timeFlag = false;//falseなら打つ
		time = 0;

		ancient = 0;

		number = 0;

		angle = 0;
		
		bulletSpeed = 0;
		std::vector<GameObject*>().swap(addGameObjects);
		this->referenceGameObjects = referenceGameObjects;
	}
	//初期化
	virtual void Initialize() {}

	virtual void Update() {}

	virtual void Draw() {}

	virtual void HitAction(GameObject* gameObject) {}

	std::vector<GameObject*> addGameObjects;

	std::vector<GameObject*> referenceGameObjects;

	OBJECTMEMBER GetObjectMember() { return objectMember; }
	OBJAGE GetObjectState() { return objectAge; }

	/// <summary>
	/// 位置取得
	/// </summary>
	/// <returns>位置</returns>
	XMFLOAT2 GetPosition() { return position; }

	/// <summary>
	/// 位置セット
	/// </summary>
	/// <param name="pos">位置</param>
	void SetPosition(XMFLOAT2 pos) { this->position = pos; }

	/// <summary>
	/// 移動量取得
	/// </summary>
	/// <returns>移動量</returns>
	XMFLOAT2 GetVelocity() { return vel; }

	/// <summary>
	/// 移動量セット
	/// </summary>
	/// <param name="vel">移動量</param>
	void SetVelocity(XMFLOAT2 vel) { this->vel = vel; }

	/// <summary>
	/// 物理的判定フラグ取得
	/// </summary>
	/// <returns>物理的判定フラグ</returns>
	bool GetPhysicsFlag() { return physicsFlag; }

	/// <summary>
	/// 物理的判定フラグセット
	/// </summary>
	/// <param name="physicsFlag">物理的判定フラグ</param>
	void SetPhysicsFlag(bool physicsFlag) { this->physicsFlag = physicsFlag; }

	/// <summary>
	/// 行動フラグ取得
	/// </summary>
	/// <returns>行動フラグ</returns>
	bool GetActionFlag() { return actionFlag; }

	/// <summary>
	/// 行動フラグセット
	/// </summary>
	/// <param name="actionFlag">行動フラグ</param>
	void SetActionFlag(bool actionFlag) { this->actionFlag = actionFlag; }

	/// <summary>
	/// 半径取得
	/// </summary>
	/// <returns>半径</returns>
	float GetRadius() { return r; }

	/// <summary>
	/// 死亡フラグ取得
	/// </summary>
	/// <returns>死亡フラグ</returns>
	bool GetDeathFlag() { return deathFlag; }

	void SetDeathFlag(bool deathFlag) { this->deathFlag = deathFlag; }

	void SetObjAge(OBJAGE* objAge) { this->objectAge = objectAge; }

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	OBJECTMEMBER GetObjectMenber() { return objectMember; }
};

