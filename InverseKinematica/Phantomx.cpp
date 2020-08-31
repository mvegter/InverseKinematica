#include "Phantomx.h"

Phantomx::Phantomx() {
	m_segments.push_back(new ArmSegment(nullptr, 10, 0));
	m_segments.push_back(new ArmSegment(getLastSegment(), 10, 0));
	m_segments.push_back(new ArmSegment(getLastSegment(), 10, 0));
}
