#include <vector>
#include "ArmSegment.h"
#include "Position.h"

class RobotArm
{
protected:
	std::vector<ArmSegment*> m_segments;

public:
	/// <summary>
	/// 
	/// </summary>
	RobotArm();

	/// <summary>
	/// 
	/// </summary>
	void printSegments();
};
