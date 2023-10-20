#include "RecoveryEnemy.h"

RecoveryEnemy::RecoveryEnemy()
{
}

RecoveryEnemy::~RecoveryEnemy()
{
}

void RecoveryEnemy::Initialize()
{
	objectMember = GameObject::RECOVERYENEMY;
	HP = 50;
	r = 32;
	recovery = LoadGraph("Resource/Playeranime.png");
}

void RecoveryEnemy::Update()
{
	Move();
}

void RecoveryEnemy::Draw()
{
	DrawRectGraph(position.x - r, position.y - r, animeCount * 64, 0, 64, 62, recovery, TRUE, FALSE);
}

void RecoveryEnemy::Move()
{
	if (position.y <= 16)moveFlag = true;//trueÇæÇ¡ÇΩÇÁâ∫à⁄ìÆ
	if (position.y >= 704)moveFlag = false;//falseÇæÇ¡ÇΩÇÁè„à⁄ìÆ
	if (moveFlag == true)position.y += 5;
	else position.y -= 5;
}
