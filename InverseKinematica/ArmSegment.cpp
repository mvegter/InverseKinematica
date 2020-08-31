#include <math.h>
#include "ArmSegment.h"

ArmSegment::ArmSegment(ArmSegment* base, double length, double angle) {
	m_base = base;
	m_length = length;
	m_angle = angle;
}

Position* ArmSegment::getPosition() {
	double baseX = 0;
	double baseY = 0;
	if (getBase() != nullptr) {
		baseX = getBase()->getPosition()->getX();
		baseY = getBase()->getPosition()->getY();
	}

	double posX = baseX + (getLength() * sin(getTotalAngle() * (3.14 / 180)));
	double posY = baseY + (getLength() * cos(getTotalAngle() * (3.14 / 180)));

	return new Position(posX, posY);
}

ArmSegment* ArmSegment::getBase() {
	return m_base;
}

Position* ArmSegment::getBasePosition() {
	if (getBase() == nullptr) {
		return new Position(0, 0, 0);
	}

	return getBase()->getPosition();
}

double ArmSegment::getAngle() {
	return m_angle;
}

double ArmSegment::getTotalAngle() {
	if (getBase() == nullptr) {
		return getAngle();
	}

	return getBase()->getTotalAngle() + getAngle();
}

double ArmSegment::getLength() {
	return m_length;
}

double ArmSegment::getX() {
	return getPosition()->getX();
}

double ArmSegment::getY() {
	return getPosition()->getY();
}

void ArmSegment::moveTo(Position* targetPosition, Position* clawPosition) {
	// TODO: implement
}
