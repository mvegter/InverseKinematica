#include <math.h>
#include "Position.h"

Position::Position(double x, double y) {
	m_x = x;
	m_y = y;
	m_z = 0;
}

Position::Position(double x, double y, double z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

double Position::getX() {
	return m_x;
}

double Position::getY() {
	return m_y;
}

double Position::getZ() {
	return m_z;
}

double Position::distanceTo(Position* otherPosition) {
	return sqrt(pow(otherPosition->getX() - getX(), 2) +
		pow(otherPosition->getY() - getY(), 2) +
		pow(otherPosition->getZ() - getZ(), 2) * 1.0);
}

Position* Position::subtract(Position* otherPosition) {
	return new Position(getX() - otherPosition->getX(),
		getY() - otherPosition->getY(),
		getZ() - otherPosition->getZ());
}

Position* Position::normalize() {
	float len = sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());

	if (len != 0.)
	{
		return new Position(getX() / len, getY() / len, getZ() / len);
	}

	return new Position(getX(), getY(), getZ());
}
