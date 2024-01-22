#pragma once
#include"GameObject.h"
class RecoveryBeam : public GameObject
{
public:
	RecoveryBeam();
	~RecoveryBeam();

	//‰Šú‰»
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();

	void HitAction(GameObject* gameObject);
private:
	int beam;
	int omen;//‘O’›

	int time;
};

