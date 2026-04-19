#include "Map.h"
#include "Player.h"

Map::Map(Player& player)
{
	m_map = new std::vector<std::vector<char>>( m_max_lvlHeight, 
		std::vector<char>(m_max_lvlLength, ' ' ));
	
	createRooms();

	std::pair<int, int> playerPosition = randomPlayerPosition();
	player.setPosition(playerPosition.first, playerPosition.second);
	
	updatePlayerPosition(playerPosition);


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

void Map::updatePlayerPosition(std::pair<int, int> newPosition)
{

	(*m_map)[lastTileVisited.first.second][lastTileVisited.first.first] = lastTileVisited.second;
	lastTileVisited = std::make_pair(std::make_pair(newPosition.first, newPosition.second), 
		(*m_map)[newPosition.second][newPosition.first]);

	(*m_map)[newPosition.second][newPosition.first] = Player::representation;
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
			if ((*m_map)[i][j] != ' ')
				return false;

		}
	}

	return true;
}

void Map::drawRoom(int x, int y, Room room)
{
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

	for ( int i = 0; i < room.m_length; i++ )
	{
		(*m_map)[y + room.m_height - 1][x + i] = verticalWall_representation;
	}

	std::unordered_set<int> sidesPicked = {};

	for ( int i = 0; i < room.m_nbDoors; i++ )
	{
		int pickedSide = rand() % 4;

		while ( sidesPicked.contains(pickedSide) )
		{
			pickedSide = rand() % 4;
		}

		sidesPicked.insert(pickedSide);

		int position;

		switch ( pickedSide )
		{
		case 0: //top
			position = (rand() % (room.m_length - 2)) + 1;
			(*m_map)[y][x + position] = door_representation;
			break;

		case 1: //bottom
			position = (rand() % (room.m_height - 2)) + 1;
			(*m_map)[y + position][x + room.m_length - 1] = door_representation;
			break;

		case 2: //right
			position = (rand() % (room.m_length - 2)) + 1;
			(*m_map)[y + room.m_height - 1][x + position] = door_representation;
			break;

		case 3: //left
			position = (rand() % (room.m_height - 2)) + 1;
			(*m_map)[y + position][x] = door_representation;
			break;
		}
	}
}

std::pair<int, int> Map::randomPlayerPosition()
{
	int x, y;

	while ( true )
	{
		x = rand() % m_max_lvlLength;
		y = rand() % m_max_lvlHeight;
		if ( (*m_map)[y][x] == floor_representation )
			return std::pair<int, int>(x, y);
	}
}
 