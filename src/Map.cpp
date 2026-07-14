#include "Map.h"
#include "Entity/Player.h"
#include "Entity/Enemy.h"
#include "Item.h"

Map::Map(Player& player)
{
	m_map = new std::vector<std::vector<char>>( m_max_lvlHeight, 
		std::vector<char>(m_max_lvlLength, ' ' ));
	
	createRooms();

	std::pair<int, int> playerPosition = randomReachablePosition();
	player.setPosition(playerPosition.first, playerPosition.second);
	lastTileVisited = std::make_pair(playerPosition, floor_representation);

	initItems();
	initEnemies();
	
	updatePlayerPosition(playerPosition, player);

}

Map::~Map()
{
	delete m_map;
	for ( auto& pair : m_enemiesOnMap )
	{
		delete pair.second;
	}
	for ( auto& pair : m_itemsOnMap )
	{
		delete pair.second;
	}
}

void Map::initEnemies()
{
	int nbEnemiesOnMap = rand() % m_minEnemies + m_minEnemies;

	for ( int i = 0; i < nbEnemiesOnMap; i++ )
	{
		auto enemy = EnemyCreator::createRandomEnemy();
		std::pair<int, int> enemyPos = randomReachablePosition();
		enemy->setPosition(enemyPos.first, enemyPos.second);
		(*m_map)[enemyPos.second][enemyPos.first] = enemy->getRepresentation();
		m_enemiesOnMap.insert({ enemyPos, enemy });
	}
}


void Map::initItems()
{
	int nbItemsOnMap = rand() % Item::max_items + m_minItems;

	for ( int i = 0; i < nbItemsOnMap; i++ ) 
	{
		auto item = ItemCreator::createRandomItem();
		std::pair<int, int> itemPos = randomReachablePosition();
		(*m_map)[itemPos.second][itemPos.first] = item->getRepresentation();
		m_itemsOnMap.insert({ itemPos, item });
	}
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

void Map::updatePlayerPosition(std::pair<int, int> newPosition, Player& player)
{
	(*m_map)[lastTileVisited.first.second][lastTileVisited.first.first] = lastTileVisited.second;
	lastTileVisited = std::make_pair(std::make_pair(newPosition.first, newPosition.second), 
		(*m_map)[newPosition.second][newPosition.first]);
	
	//item handling
	if ( const auto it = m_itemsOnMap.find(newPosition); it != m_itemsOnMap.end() )
	{
		it->second->use(player);
		m_itemsOnMap.erase(it);
		lastTileVisited.second = floor_representation;
	}

	(*m_map)[newPosition.second][newPosition.first] = Player::representation;
}
void Map::updateEnemyPosition(std::pair<int, int> oldPosition, std::pair<int, int> newPosition, Enemy& enemy)
{
	(*m_map)[oldPosition.second][oldPosition.first] = floor_representation;
	(*m_map)[newPosition.second][newPosition.first] = enemy.getRepresentation();
	
	m_enemiesOnMap.erase(oldPosition);
	m_enemiesOnMap.insert({ newPosition, &enemy });
}

void Map::updateEnemies(Player& player)
{
	std::vector<Enemy*> enemies;
	for ( const auto& pair : m_enemiesOnMap )
	{
		enemies.push_back(pair.second);
	}

	for ( Enemy* enemy : enemies )
		if ( enemy->isAlive() )
			enemy->executeStrategy(*this, player);
}

bool Map::hasEnemyAt(std::pair<int, int> pos) const
{
	return m_enemiesOnMap.find(pos) != m_enemiesOnMap.end();
}

Enemy* Map::getEnemyAt(std::pair<int, int> pos)
{
    const auto it = m_enemiesOnMap.find(pos);
	if ( it != m_enemiesOnMap.end() )
	{
		return it->second;
	}
	return nullptr;
}

void Map::removeEnemy(std::pair<int, int> pos)
{
	auto it = m_enemiesOnMap.find(pos);
	if ( it != m_enemiesOnMap.end() )
	{
		(*m_map)[pos.second][pos.first] = floor_representation;
		delete it->second;
		m_enemiesOnMap.erase(it);
	}
}

bool Map::isMoveValid(std::pair<int, int> pos)
{
	if ( pos.first < 0 || pos.first >= m_max_lvlLength || pos.second < 0 || pos.second >= m_max_lvlHeight )
	{
		return false;
	}
	return (*m_map)[pos.second][pos.first] == floor_representation;
}

void Map::display()
{
	std::stringstream buffer;

	for ( const auto& row : *m_map )
	{
		for ( const auto& cell : row )
		{
			switch ( cell ) //color handling
			{
			case Player::representation:
				buffer << YELLOW << cell << RESET;
				break;
			case floor_representation:
				buffer << GREEN << cell << RESET;
				break;
			case door_representation:
				buffer << BOLDYELLOW << cell << RESET;
				break;
			case horizontalWall_representation:
				buffer << BROWN << cell << RESET;
				break;
			case verticalWall_representation:
				buffer << BROWN << cell << RESET;
				break;
			case path_representation:
				buffer << BOLDMAGENTA << cell << RESET;
				break;
			default:
				buffer << BOLDWHITE << cell << RESET;
			}
		}
		buffer << "\n";
	}
	std::cout << buffer.str();
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

std::pair<int, int> Map::randomReachablePosition() const
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
 