#pragma once

#include <vector>
#include <unordered_set>
#include <iostream>

#include "Room.h"

class Map
{
public:

	std::vector<std::vector<char>>* m_map;


	Map();
	~Map();

	void createRooms();
	void createCorridors();

	void display();	

private:

	bool canCreateRoom(int x, int y, Room room);
	void drawRoom(int x, int y, Room room);


	int m_numRooms = 10;

	//terminal size
	int m_max_lvlHeight = 50;
	int m_max_lvlLength = 100;
	int m_min_SpacingBetweenRooms = 4;

	inline const static char floor_representation = '.';
	inline const static char door_representation = '+';
	inline const static char horizontalWall_representation = '|';
	inline const static char verticalWall_representation = '-';
	inline const static char path_representation = '#';

};