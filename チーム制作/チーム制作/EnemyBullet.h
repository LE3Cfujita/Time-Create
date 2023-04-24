#include"GameObject.h"
class EnemyBullet : public GameObject
{

public:
	EnemyBullet();
	~EnemyBullet();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();
};
