#include <vector>
#include "ArmSegment.h"
#include "Position.h"

class RobotArm
{
protected:
	std::vector<ArmSegment*> m_segments;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	ArmSegment* getLastSegment();

public:
	/// <summary>
	/// 
	/// </summary>
	RobotArm();

	/// <summary>
	/// 
	/// </summary>
	void printSegments();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="targetPosition"></param>
	void moveTo(Position* targetPosition);
};
