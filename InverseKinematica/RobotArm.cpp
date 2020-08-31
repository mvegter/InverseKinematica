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
