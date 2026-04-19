#pragma once

#include <vector>
#include <unordered_set>
#include <iostream>

#include "Room.h"

class Player;

class Map
{
public:

	std::vector<std::vector<char>>* m_map;

	Map(Player& player);
	~Map();

	void createRooms();
	void createCorridors();

	void updatePlayerPosition(std::pair<int, int> newPosition);


	void display();	

	static const int m_max_lvlHeight = 50;
	static const int m_max_lvlLength = 100;

private:

	bool canCreateRoom(int x, int y, Room room);
	void drawRoom(int x, int y, Room room);

	std::pair<int, int> randomPlayerPosition();
	std::pair<std::pair<int, int>, char> lastTileVisited;

	int m_numRooms = 10;

	//terminal size
	int m_min_SpacingBetweenRooms = 4;

	inline const static char floor_representation = '.';
	inline const static char door_representation = '+';
	inline const static char horizontalWall_representation = '|';
	inline const static char verticalWall_representation = '-';
	inline const static char path_representation = '#';

};