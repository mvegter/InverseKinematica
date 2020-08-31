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
