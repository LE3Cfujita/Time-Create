#include"GameObject.h"
class EnemyBullet : public GameObject
{

public:
	EnemyBullet();
	~EnemyBullet();

	//������
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:

	void Move();
};
