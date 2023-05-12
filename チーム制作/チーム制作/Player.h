#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
#include"PlayerModernBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//������
	void Initialize();

	void Update();

	void Draw();
private:
	void Move();//�ړ�
	void Attack();//�U��
	void Invincible();//���G
	void HitAction(GameObject* gameObject);

	int player;//�`��p
	int ancientHP;//�`��p
	int modernHP;//�`��p
	int futureHP;//�`��p

	XMFLOAT2 hpPos = { 0,0 };

	int invincibleFlag = false;
	int invincibleTime = 0;
};

