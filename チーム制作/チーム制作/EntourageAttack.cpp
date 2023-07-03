#include "EntourageAttack.h"

EntourageAttack::EntourageAttack()
{
}

EntourageAttack::~EntourageAttack()
{
}

void EntourageAttack::Initialize(XMFLOAT2 pos)
{
	objectMember = GameObject::ENEMY;
	objectAge = GameObject::ANCIENT;
	objState = GameObject::IDLE;
	position = pos;
}

void EntourageAttack::Update()
{
}

void EntourageAttack::Draw()
{
}
