#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//èâä˙âª
	void Initialize(XMFLOAT2 pos, int number);

	void Update();

	void Draw();

	void Resource(int graph, int se,int kirikae,int damage, int recovery);

	void FormationX(XMFLOAT2 pos);
	void FormationZ(XMFLOAT2 pos);

private:
	void Move();//à⁄ìÆ
	void Attack();//çUåÇ
	void Invincible();//ñ≥ìG
	void HitAction(GameObject* gameObject);
	void Animation();
	void Action();

	int player;//ï`âÊóp
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
};

