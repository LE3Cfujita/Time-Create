#pragma once
class Collision
{
public:
	/// <summary>
/// â~Ç∆éläpå`
/// </summary>
	bool CircleToSquare(float pPos_x, float pPos_y, float ePos_x, float ePos_y, float r, float width, float height);


	/// <summary>
	/// éläpå`Ç∆éläpå`
	/// </summary>
	bool SquareToSquare(float pPos_x, float pPos_y, float ePos_x, float ePos_y, float width1, float height1, float width2, float height2);
};

