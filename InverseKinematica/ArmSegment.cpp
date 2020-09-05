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

double DotProduct(Position* pos1, Position* pos2) {
	return pos1->getX() * pos2->getX() + pos1->getY() * pos2->getY() + pos1->getZ() * pos2->getZ();
}

Position* CrossProduct(Position* pos1, Position* pos2) {
	return new Position(pos1->getY() * pos2->getZ() - pos1->getZ() * pos2->getY(),
		pos1->getZ() * pos2->getX() - pos1->getX() * pos2->getZ(),
		pos1->getX() * pos2->getY() - pos1->getY() * pos2->getX());
}

void ArmSegment::moveTo(Position* targetPosition, Position* clawPosition) {
	Position* curVector = clawPosition->subtract(getBasePosition())->normalize();
	Position* targetVector = targetPosition->subtract(getBasePosition())->normalize();

	double cosAngle = DotProduct(targetVector, curVector);
	if (cosAngle < 0.99999) {
		Position* crossResult = CrossProduct(targetVector, curVector);
		if (crossResult->getZ() > 0.0f) {
			m_angle += acos(cosAngle) * 180.0 / PI;
		}
		else if (crossResult->getZ() < 0.0f) {
			m_angle -= acos(cosAngle) * 180.0 / PI;
		}
	}
}
