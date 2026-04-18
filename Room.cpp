#include "Room.h"

Room::Room()
{
	m_height = (rand() % maxHeightRoom) + minHeightRoom;
	m_length = (rand() % maxLengthRoom) + minLengthRoom;
	m_nbDoors = (rand() % maxDoors) + minNbDoors;
}
