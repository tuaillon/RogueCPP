#include "Room.h"

Room::Room()
{
	m_height = rand() % maxHeightRoom;
	m_length = rand() % maxLengthRoom;
	m_nbDoors = rand() % maxDoors;
}
