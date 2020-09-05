#include <math.h>
#include "ArmSegment.h"

#define PI 3.14159265

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

	double posX = baseX + (getLength() * sin(getTotalAngle() * (PI / 180.0)));
	double posY = baseY + (getLength() * cos(getTotalAngle() * (PI / 180.0)));

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

void ArmSegment::transformAngle(double angle) {
	double damping = 30.0;
	double freedom = 90.0;

	// No need to do anything
	if (angle == 0) return;

	// Damping the diff
	angle = fmin(damping, fmax(-1.0 * damping, angle));
	m_angle += angle;

	// Freedom
	m_angle = fmin(freedom, fmax(-1.0 * freedom, m_angle));
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
	Position* curVector = clawPosition->subtract(getBasePosition())->normalize();
	Position* targetVector = targetPosition->subtract(getBasePosition())->normalize();

	double cosAngle = Position::DotProduct(targetVector, curVector);
	if (!(cosAngle < 0.99999)) {
		return;
	}

	Position* crossResult = Position::CrossProduct(targetVector, curVector);
	double angle = 0;
	if (crossResult->getZ() > 0.0f) {
		angle += acos(cosAngle) * 180.0 / PI;
	}
	else if (crossResult->getZ() < 0.0f) {
		angle -= acos(cosAngle) * 180.0 / PI;
	}

	transformAngle(angle);
}
