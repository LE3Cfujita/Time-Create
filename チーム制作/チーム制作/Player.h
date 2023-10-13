#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	//初期化
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void Resource(int graph, int se,int kirikae,int damage);

private:
	void Move();//移動
	void Attack();//攻撃
	void Invincible();//無敵
	void HitAction(GameObject* gameObject);
	void Animation();


	int player;//描画用
	int attackSE;
	int kirikaeSE;
	int damageSE;

	bool invincibleFlag = false;
	int invincibleTime = 0;
	bool animationFlag = false;

	bool hitButton = false;

	bool formationFlag = false;

	int drawNumber = 5;//キャラクター数

	int gap = 100;//キャラクター間

};

