#pragma once

#include <cstdlib>

inline int maxLengthRoom = 21;
inline int maxHeightRoom = 7;
inline int maxDoors = 4;


struct Room
{
public:

	int m_length;
	int m_height;
	int m_nbDoors;

	Room();
};
