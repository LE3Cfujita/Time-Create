#include "RecoveryBeam.h"

RecoveryBeam::RecoveryBeam()
{
}

RecoveryBeam::~RecoveryBeam()
{
}

void RecoveryBeam::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::RECOVERYBEAM;
	beam = LoadGraph("Resource/beam.png"); // •`‰æ
	omen = LoadGraph("Resource/omenBeam.png"); // •`‰æ
	position = pos;
	position2.x = position.x;
	position2.y = 0;
	r = 180;
}

void RecoveryBeam::Update()
{
	time++;
	if (time >= 60)
	{
		position.y += 20;
		if (position.y >= 730)
		{
			deathFlag = true;
		}
	}
}

void RecoveryBeam::Draw()
{
	DrawGraph(position2.x - r, position2.y, omen, true);
	DrawGraph(position.x - r, position.y, beam, true);
}

void RecoveryBeam::HitAction(GameObject* gameObject)
{
}
