#pragma once
#include"GameObject.h"
class HitEffect : public GameObject
{
public:

	HitEffect();
	~HitEffect();
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:
	int effect1;
	int effect2;
	int effect3;
};