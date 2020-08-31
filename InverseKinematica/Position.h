#pragma once
class Position
{
private:
	double m_x;
	double m_y;

public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	Position(double x, double y);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	double getX();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	double getY();
};
