#pragma once
#include"GameObject.h"
class DownEffec : public GameObject
{

public:

	DownEffec();
	~DownEffec();
	void Initialize(XMFLOAT2 pos);

	void Update();

	void Draw();
private:
	int effect1;
	int a = 0;
};

