#include "Map.h"

Map::Map()
{
	m_map = new std::vector<std::vector<char>>( m_max_lvlHeight, 
		std::vector<char>(m_max_lvlLength, ' ' ));
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
