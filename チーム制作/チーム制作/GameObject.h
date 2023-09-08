#pragma once
#include <DirectXMath.h>
#define _USE_MATH_DEFINES
#include"math.h"
#include <vector>
#include"DxLib.h"
#include"stdlib.h"

using namespace DirectX;
class GameObject
{
public:
	enum OBJECTMEMBER
	{
		NONEMEMBER,//初期
		PLAYER,//プレイヤー
		PLAYERBULLET,//プレイヤーの弾
		SLIME,//敵
		BOSSENEMY,//ボス敵
		SLIMEBULLET,//スライムの攻撃
		BOSSBULLET,//ボスの攻撃
		HITEFFECT,//ヒットエフェクト
	};
	enum STAGE
	{
		STAND,
		FIRSTSTAGE,//1ステージ目
		SECONDSTAGE,//現代
	};
	enum OBJSTATE
	{
		IDLE,		//待機
		MOVE,		//移動
		ATTACK,		//攻撃
		DEATH,		//死亡
		ALIVE,		//生産
		EFFECT,		//死亡エフェクト
		NONESTATE,	//なし
	};

protected:
	bool deathFlag;
	OBJECTMEMBER objectMember;
	STAGE objectStage;
	OBJSTATE objState;
	XMFLOAT2 position;
	XMFLOAT2 position2;
	//移動量
	XMFLOAT2 vel;
	float r;//半径
	int color;//色
	//行動フラグ
	bool actionFlag;
	//物理的判定フラグ
	bool physicsFlag;

	bool timeFlag;//falseならまっすぐ打つ
	int timer;
	bool balkanFlag;
	int balkanTime;
	bool cannonFlag;

	float ancient;

	int number;

	double angle;

	float bulletSpeed;
	//狙う
	int homingTime;
	int homingCount;

	//距離
	float dx;
	float dy;
	float da;
	float L;

	float HP;//体力


	bool move;
	bool beamFlag;
	bool predictionFlag;
	bool beamCount;

	int beamCT = 0;

	int animation;
	int animeCount;

	int deathCount;

public:
	GameObject() {}
	virtual ~GameObject() {
		//std::vector<GameObject*>().swap(addGameObjects);
	}
	void BaseInitialize(std::vector<GameObject*> referenceGameObjects)
	{
		objectMember = OBJECTMEMBER::NONEMEMBER;
		objectStage = STAGE::FIRSTSTAGE;
		objState = OBJSTATE::IDLE;

		deathFlag = false;
		position = { 0,0 };
		position2 = { 0,0 };
		vel = { 0,0 };
		physicsFlag = false;
		actionFlag = false;
		r = 32;

		color = 0;

		timeFlag = false;//falseなら打つ
		timer = 0;
		balkanFlag = false;//falseなら打つ
		balkanTime = 0;
		cannonFlag = false;

		ancient = 0;


		number = 0;

		angle = 0;
		bulletSpeed = 0;
		homingTime = 0;
		homingCount = 0;

		dx = 0;
		dy = 0;
		da = 0;
		L = 0;

		HP = 10;
		move = true;
		beamFlag = false;
		predictionFlag = false;
		beamCount = false;

		animation = 0;
		animeCount = 0;

		deathCount = 0;

		number = 0;

		std::vector<GameObject*>().swap(addGameObjects);
		this->referenceGameObjects = referenceGameObjects;
	}
	//初期化
	virtual void Initialize() {}

	virtual void Update() {}

	virtual void Draw() {}

	virtual void HitAction(GameObject* gameObject) {}

	virtual void Resource(){}

	virtual void FormationX(XMFLOAT2 pos){}
	virtual void FormationZ(XMFLOAT2 pos){}

	std::vector<GameObject*> addGameObjects;

	std::vector<GameObject*> referenceGameObjects;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	OBJECTMEMBER GetObjectMember() { return objectMember; }


	STAGE GetObjectAge() { return objectStage; }
	OBJSTATE GetObjectState() { return objState; }
	void SetObjectState(OBJSTATE objState) { this->objState = objState; }

	/// <summary>
	/// 位置取得
	/// </summary>
	/// <returns>位置</returns>
	XMFLOAT2 GetPosition() { return position; }
	XMFLOAT2 GetPosition2() { return position2; }

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

	void SetObjAge(STAGE objAge) { this->objectStage = objAge; }

	void SetCannonFlag(bool cannonFlag) { this->cannonFlag = cannonFlag; }

	void SetHP(float HP) { this->HP = HP; }
	int GetHP() { return HP; }


	void SetAnimation(int animeCount) { this->animeCount = animeCount; }
	void SetNumber(int number) { this->number = number; }
	int GetNumber() { return number; }


	void SetMove(bool move) { this->move = move; }
	void SetBeamFlag(bool beamFlag) { this->beamFlag = beamFlag; }
	void SetPredictionFlag(bool predictionFlag) { this->predictionFlag = predictionFlag; }
	void SetBeamCount(bool beamCount) { this->beamCount = beamCount; }


	int GetDeathCount() { return deathCount; }

};

