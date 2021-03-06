#include "Position.h"

#pragma once
class ArmSegment
{
private:
	ArmSegment* m_base;
	double m_length;
	double m_angle;

protected:
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	ArmSegment* getBase();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	double getTotalAngle();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="angle"></param>
	void transformAngle(double angle);

public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="base"></param>
	/// <param name="length"></param>
	/// <param name="angle"></param>
	ArmSegment(ArmSegment* base, double length, double angle);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Position* getPosition();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Position* getBasePosition();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	double getLength();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	double getAngle();

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
	/// <param name="targetPosition"></param>
	/// <param name="clawPosition"></param>
	void moveTo(Position* targetPosition, Position* clawPosition);
};
