#include "Collision.h"


bool Collision::CircleToSquare(float pPos_x, float pPos_y, float ePos_x, float ePos_y, float r, float width, float height)
{
	float x1 = ePos_x - (width / 2);
	float y1 = ePos_y + (height / 2);
	float x2 = ePos_x + (width / 2);
	float y2 = ePos_y - (height / 2);

	float potX1 = (x1 - pPos_x) * (x1 - pPos_x);
	float potY1 = (y1 - pPos_y) * (y1 - pPos_y);
	float potX2 = (x2 - pPos_x) * (x2 - pPos_x);
	float potY2 = (y2 - pPos_y) * (y2 - pPos_y);
	float potR = r * r;

	//�̈�A
	float regionA = (pPos_x > x1) &&
		(pPos_x < x2) &&
		(pPos_y > y2 - r) &&
		(pPos_y < y1 + r);
	//�̈�B
	float regionB = (pPos_x > x1 - r) &&
		(pPos_x < x2 + r) &&
		(pPos_y < y1) &&
		(pPos_y > y2);
	//�̈�C
	float regionC = potX1 + potY1 < potR;
	//�̈�D
	float regionD = potX2 + potY1 < potR;
	//�̈�E
	float regionE = potX2 + potY2 < potR;
	//�̈�F
	float regionF = potX1 + potY2 < potR;

	//�Փ˔���
	if (regionA || regionB || regionC || regionD || regionE || regionF)
	{
		return true;
	}
	return false;
}


bool Collision::SquareToSquare(float pPos_x, float pPos_y, float ePos_x, float ePos_y, float width1, float height1, float width2, float height2)
{
	float aX1 = pPos_x - (width1 / 2);
	float aY1 = pPos_y + (height1 / 2);
	float aX2 = pPos_x + (width1 / 2);
	float aY2 = pPos_y - (height1 / 2);

	float bX1 = ePos_x - (width2 / 2);
	float bY1 = ePos_x + (height2 / 2);
	float bX2 = ePos_x + (width2 / 2);
	float bY2 = ePos_y - (height2 / 2);

	if ((bX1 <= aX2) && (aX1 <= bX2) && (bY1 >= aY2) && (aY1 >= bY2))
	{
		return true;
	}
}