#pragma once

#include <cstdlib>

inline int maxLengthRoom = 21;
inline int maxHeightRoom = 7;
inline int maxDoors = 4;
inline int minLengthRoom = 5;
inline int minHeightRoom = 4;
inline int minNbDoors = 1;

struct Room
{
public:

	int m_length;
	int m_height;
	int m_nbDoors;

	Room();
};
