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
		NONEMEMBER,//����
		PLAYER,//�v���C���[
		PLAYERBULLET,//�v���C���[�̒e
		ENEMY,//�G
		ENEMYBULLET,//�G�̒e(�Ñ�)
		ENEMYFIRE,//�G�̉�(�Ñ�)
		ENEMYBALKAN,//�G�̃o���J��(����)
		ENEMYCANNON,//�G�̑�C(����)
		ENEMYBEAM,//�G�̃r�[��(����)
	};
	enum OBJAGE
	{
		ANCIENT,//�Ñ�
		MODERN,//����
		FUTURE,//����
	};
	enum OBJSTATE
	{
		IDLE,		//�ҋ@
		MOVE,		//�ړ�
		ATTACK,		//�U��
		DEATH,		//���S
		ALIVE,		//���Y
		NONESTATE,	//�Ȃ�
	};

protected:
	bool deathFlag;
	OBJECTMEMBER objectMember;
	OBJAGE objectAge;
	OBJSTATE objState;
	XMFLOAT2 position;
	XMFLOAT2 position2;
	//�ړ���
	XMFLOAT2 vel;
	float r;//���a
	int color;//�F
	//�s���t���O
	bool actionFlag;
	//�����I����t���O
	bool physicsFlag;

	bool timeFlag;//false�Ȃ�܂������ł�
	int time;
	bool balkanFlag;
	int balkanTime;
	bool cannonFlag;

	float ancient;

	int number;

	double angle;

	float bulletSpeed;
	//�_��
	int homingTime;
	int homingCount;

	//����
	float dx;
	float dy;
	float da;
	float L;

	int HP;//�̗�


	bool move;
	bool beamFlag;
	bool predictionFlag;
	bool beamCount;

	int beamCT = 0;

	int animation;
	int animeCount;
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
		position2 = { 0,0 };
		vel = { 0,0 };
		physicsFlag = false;
		actionFlag = false;
		r = 32;

		color = 0;

		timeFlag = false;//false�Ȃ�ł�
		time = 0;
		balkanFlag = false;//false�Ȃ�ł�
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


		move = true;
		beamFlag = false;
		predictionFlag = false;
		beamCount = false;

		animation = 0;
		animeCount = 0;

		std::vector<GameObject*>().swap(addGameObjects);
		this->referenceGameObjects = referenceGameObjects;
	}
	//������
	virtual void Initialize() {}

	virtual void Update() {}

	virtual void Draw() {}

	virtual void HitAction(GameObject* gameObject) {}

	std::vector<GameObject*> addGameObjects;

	std::vector<GameObject*> referenceGameObjects;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	OBJECTMEMBER GetObjectMember() { return objectMember; }


	OBJAGE GetObjectAge() { return objectAge; }

	/// <summary>
	/// �ʒu�擾
	/// </summary>
	/// <returns>�ʒu</returns>
	XMFLOAT2 GetPosition() { return position; }
	XMFLOAT2 GetPosition2() { return position2; }

	/// <summary>
	/// �ʒu�Z�b�g
	/// </summary>
	/// <param name="pos">�ʒu</param>
	void SetPosition(XMFLOAT2 pos) { this->position = pos; }

	/// <summary>
	/// �ړ��ʎ擾
	/// </summary>
	/// <returns>�ړ���</returns>
	XMFLOAT2 GetVelocity() { return vel; }

	/// <summary>
	/// �ړ��ʃZ�b�g
	/// </summary>
	/// <param name="vel">�ړ���</param>
	void SetVelocity(XMFLOAT2 vel) { this->vel = vel; }

	/// <summary>
	/// �����I����t���O�擾
	/// </summary>
	/// <returns>�����I����t���O</returns>
	bool GetPhysicsFlag() { return physicsFlag; }

	/// <summary>
	/// �����I����t���O�Z�b�g
	/// </summary>
	/// <param name="physicsFlag">�����I����t���O</param>
	void SetPhysicsFlag(bool physicsFlag) { this->physicsFlag = physicsFlag; }

	/// <summary>
	/// �s���t���O�擾
	/// </summary>
	/// <returns>�s���t���O</returns>
	bool GetActionFlag() { return actionFlag; }

	/// <summary>
	/// �s���t���O�Z�b�g
	/// </summary>
	/// <param name="actionFlag">�s���t���O</param>
	void SetActionFlag(bool actionFlag) { this->actionFlag = actionFlag; }

	/// <summary>
	/// ���a�擾
	/// </summary>
	/// <returns>���a</returns>
	float GetRadius() { return r; }

	/// <summary>
	/// ���S�t���O�擾
	/// </summary>
	/// <returns>���S�t���O</returns>
	bool GetDeathFlag() { return deathFlag; }

	void SetDeathFlag(bool deathFlag) { this->deathFlag = deathFlag; }

	void SetObjAge(OBJAGE objAge) { this->objectAge = objAge; }

	void SetCannonFlag(bool cannonFlag) { this->cannonFlag = cannonFlag; }

	void SetHP(int HP) { this->HP = HP; }
	bool GetHP() { return HP; }


	void SetAnimation(int animeCount) { this->animeCount = animeCount; }


	void SetMove(bool move) { this->move = move; }
	void SetBeamFlag(bool beamFlag) { this->beamFlag = beamFlag; }
	void SetPredictionFlag(bool predictionFlag) { this->predictionFlag = predictionFlag; }
	void SetBeamCount(bool beamCount) { this->beamCount = beamCount; }

};

