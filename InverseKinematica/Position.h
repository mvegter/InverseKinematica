#pragma once
class Position
{
private:
	double m_x;
	double m_y;
	double m_z;

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
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	Position(double x, double y, double z);

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

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	double getZ();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="otherPosition"></param>
	/// <returns></returns>
	double distanceTo(Position* otherPosition);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="otherPosition"></param>
	/// <returns></returns>
	Position* subtract(Position* otherPosition);
};
