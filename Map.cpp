#include "Map.h"
#include "Room.h"

Map::Map()
{
	m_map = new std::vector<std::vector<char>>( m_max_lvlHeight, 
		std::vector<char>(m_max_lvlLength, ' ' ));
	createRooms();
}

Map::~Map()
{
	delete m_map;
}

void Map::createRooms()
{
	for ( int i = 0; i < m_numRooms; i++ )
	{
		Room room;
		
		bool placed = false;

		while ( !placed )
		{
			int x = rand() % m_max_lvlLength;
			int y = rand() % m_max_lvlHeight;

			if ( canCreateRoom(x, y, room) )
			{
				drawRoom(x, y, room);
				placed = true;
			}

		}
	}
}

void Map::createCorridors()
{

}


void Map::display()
{
	for ( const auto& row : *m_map )
	{
		for ( const auto& cell : row )
		{
			std::cout << cell;
		}
		std::cout << "\n";
	}
}

bool Map::canCreateRoom(int x, int y, Room room)
{
	if ( room.m_height + y >= m_max_lvlHeight || room.m_length + x >= m_max_lvlLength )
		return false;

	for ( int i = y; i < room.m_height + y; i++ )
	{
		for ( int j = x; j < room.m_length + x; j++ )
		{
			if ( (*m_map)[i][j] != ' ' )
				return false;
		}
	}

	return true;
}

void Map::drawRoom(int x, int y, Room room)
{
	(*m_map)[y][x] = horizontalWall_representation;
	for ( int i = 0; i < room.m_length; i++ )
	{
		(*m_map)[y][x + i] = verticalWall_representation;
	}

	for ( int i = 1; i < room.m_height - 1; i++ )
	{
		(*m_map)[y + i][x] = horizontalWall_representation;
		for ( int j = 1; j < room.m_length - 1; j++ )
		{
			(*m_map)[y + i][x + j] = floor_representation;
		}
		(*m_map)[y + i][x + room.m_length - 1] = horizontalWall_representation;
	}

	(*m_map)[y + room.m_height - 1][x] = horizontalWall_representation;
	for ( int i = 1; i < room.m_length; i++ )
	{
		(*m_map)[y + room.m_height - 1][x + i] = verticalWall_representation;
	}

	for ( int i = 0; i < room.m_nbDoors; i++ )
	{
		int doorX = 1;
		int doorY = 1;

		if (room.m_length > 2)
			doorX = (rand() % (room.m_length - 2)) + 1;
			
		if (room.m_height > 2)
			doorY = (rand() % (room.m_height - 2)) + 1;

		(*m_map)[y + doorY][x + doorX] = door_representation;
	}
}
 