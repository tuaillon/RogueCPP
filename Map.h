#pragma once

#include <vector>
#include <iostream>

class Map
{
public:

	std::vector<std::vector<char>>* m_map;


	Map();

	void display();

private:

	//terminal size
	int m_max_lvlHeight = 50;
	int m_max_lvlLength = 100;

	inline static std::string floor_representation = ".";
	inline static std::string door_representation = "+";
	inline static std::string horizontalWall_representation = "|";
	inline static std::string verticalWall_representation = "-";
	inline static std::string path_representation = "#";


};