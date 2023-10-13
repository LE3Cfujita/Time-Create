#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph, int se,int kirikae,int damage);

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

	bool hitButton = false;

	bool formationFlag = false;

	int drawNumber = 5;//�L�����N�^�[��

	int gap = 100;//�L�����N�^�[��

};

