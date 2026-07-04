#pragma once

#include <vector>
#include <unordered_set>
#include <iostream>
#include <map>
#include <sstream>

#include "Room.h"
#include "Item.h"
#include "Utility.h"
#include "Enemy.h"

class Player;

class Map
{
public:

	std::vector<std::vector<char>>* m_map;

	Map(Player& player);
	~Map();

	void createCorridors();

	void updatePlayerPosition(std::pair<int, int> newPosition, Player& player);


	void display();	
	
	//terminal size
	static const int m_max_lvlHeight = 50;
	static const int m_max_lvlLength = 100;

	inline const static char floor_representation = '.';
	inline const static char door_representation = '+';
	inline const static char horizontalWall_representation = '|';
	inline const static char verticalWall_representation = '-';
	inline const static char path_representation = '#';


private:

	void initEnemies();
	void initItems();
	void createRooms();
	bool canCreateRoom(int x, int y, Room room);
	void drawRoom(int x, int y, Room room);

	std::pair<int, int> randomReachablePosition();
	std::pair<std::pair<int, int>, char> lastTileVisited;
	std::map<std::pair<int, int>, Item*> m_itemsOnMap;
	std::map<std::pair<int, int>, Enemy*> m_enemiesOnMap;

	int m_minEnemies = 4;
	int m_numRooms = 10;
	int m_minItems = 2;
	int m_min_SpacingBetweenRooms = 4;

};