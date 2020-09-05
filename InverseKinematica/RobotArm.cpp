#include <iostream>
#include "RobotArm.h"

RobotArm::RobotArm() {}

void RobotArm::printSegments() {
	for (size_t i = 0; i < m_segments.size(); i++)
	{
		ArmSegment* segment = m_segments[i];

		std::cout << "Segment #" << i + 1 << "\n";
		std::cout << "  Distance: " << segment->getPosition()->distanceTo(segment->getBasePosition()) << "\n";
		std::cout << "  Angle: " << segment->getAngle() << "\n";
		std::cout << "  Length: " << segment->getLength() << "\n";
		std::cout << "  Base:" << "\n";
		std::cout << "    Position X: " << segment->getBasePosition()->getX() << "\n";
		std::cout << "    Position Y: " << segment->getBasePosition()->getY() << "\n";
		std::cout << "    Position Z: " << segment->getBasePosition()->getZ() << "\n";
		std::cout << "  Hand:" << "\n";
		std::cout << "    Position X: " << segment->getPosition()->getX() << "\n";
		std::cout << "    Position Y: " << segment->getPosition()->getY() << "\n";
		std::cout << "    Position Z: " << segment->getPosition()->getZ() << "\n";
		std::cout << "\n";
	}
}

ArmSegment* RobotArm::getLastSegment() {
	return m_segments[m_segments.size() - 1];
}

void RobotArm::moveTo(Position* targetPosition) {
	int runs = 0;

	std::cout << "Run #" << runs << "\n";
	std::cout << "  Distance: " << getLastSegment()->getPosition()->distanceTo(targetPosition) << "\n";
	std::cout << "\n";
	printSegments();

	int i = m_segments.size();
	while (++runs < (m_segments.size() * 10000) && getLastSegment()->getPosition()->distanceTo(targetPosition) > 0.1) {
		if (--i < 0) {
			i = m_segments.size() - 1;
		}

		m_segments[i]->moveTo(targetPosition, getLastSegment()->getPosition());
	}

	std::cout << "Run #" << runs << "\n";
	std::cout << "  Distance: " << getLastSegment()->getPosition()->distanceTo(targetPosition) << "\n";
	std::cout << "\n";
	printSegments();
}
