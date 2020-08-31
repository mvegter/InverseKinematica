#include "Position.h"

Position::Position(double x, double y) {
	m_x = x;
	m_y = y;
}

double Position::getX() {
	return m_x;
}

double Position::getY() {
	return m_y;
}
