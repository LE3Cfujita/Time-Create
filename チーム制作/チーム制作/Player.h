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

	void Resource(int graph, int se,int kirikae,int damage);

	void FormationX(XMFLOAT2 pos);
	void FormationZ(XMFLOAT2 pos);

private:
	void Move();//�ړ�
	void Attack();//�U��
	void Invincible();//���G
	void HitAction(GameObject* gameObject);
	void Animation();

	int player;//�`��p
	int attackSE;
	int kirikaeSE;
	int damageSE;

	bool invincibleFlag = false;
	int invincibleTime = 0;
	bool animationFlag = false;

	bool chargeFlag = false;
	int chargeAnimation = 0;
	int chargeAnimationCount = 0;

	bool hitButton = false;

	int chargeTime = 0;
	int pushTime = 0;

	bool X = false;

};

