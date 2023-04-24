#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	objectMember = GameObject::ENEMY;
	objectState = GameObject::ANCIENT;
	position = { 1000,300 };
	r = 32;
	color= GetColor(255, 255, 255);
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	DrawCircle(position.x, position.y, r, color, true);
}

void Enemy::Move()
{
}

void Enemy::Attack()
{
}

void Enemy::HitAction(GameObject* gameObject)
{
}
