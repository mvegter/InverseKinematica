#include <iostream>
#include "RobotArm.h"

RobotArm::RobotArm() {}

void RobotArm::printSegments() {
	for (size_t i = 0; i < m_segments.size(); i++)
	{
		ArmSegment* segment = m_segments[i];

		std::cout << "Segment #" << i + 1 << "\n";
		std::cout << "  Position X: " << segment->getX() << "\n";
		std::cout << "  Position Y: " << segment->getY() << "\n";
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
	while (++runs < 10 && getLastSegment()->getPosition()->distanceTo(targetPosition) > 0) {
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
