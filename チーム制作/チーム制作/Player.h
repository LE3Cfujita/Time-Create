#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//������
	void Initialize(XMFLOAT2 pos, int number);

	void Update();

	void Draw();

	void Resource(int graph, int se,int kirikae,int damage, int recovery);

	void changeForm(XMFLOAT2 pos);

	void FormationQ(XMFLOAT2 pos);
	void FormationE(XMFLOAT2 pos);

private:
	void Move();//�ړ�
	void Attack();//�U��
	void Invincible();//���G
	void HitAction(GameObject* gameObject);
	void Animation();
	void Action();
	void AnotherP(GameObject* gameObject);//�ʂ̃v���C���[�L����
	void Distance();//�v���C���[�Ԃ̋���
	void Limit();//�ړ����E

	int player;//�`��p
	int attackSE;
	int kirikaeSE;
	int damageSE;
	int recoverySE;

	bool invincibleFlag = false;
	int invincibleTime = 0;
	bool animationFlag = false;

	bool chargeFlag = false;
	int chargeAnimation = 0;
	int chargeAnimationCount = 0;

	bool attackFlag = false;
	int coolTime = 0;

	int chargeTime = 0;
	int pushTime = 0;

	bool X = false;

	bool actionFlag = false;

	int speed = 5;

	int subNumber = 0;
	XMFLOAT2 subPos = { 0,0 };
	bool moveFlag = true;

	XMFLOAT2 oldPos = { 0,0 };//1�t���[���O�̍��W

	bool formFlag = false;

	int bullet;
};

