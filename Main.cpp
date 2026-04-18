#include <iostream>
#include <ctime>

#include "Player.h"
#include "Map.h"

int main()
{
    srand(time(nullptr));

	Map map;
    player::Player player;
	bool gameRunning = true;

	while (gameRunning)
	{
		map.display();
		player.logStats();

		std::cout << "Awaiting for input...\n";
		
		char input;
		std::cin >> input;
	}

}
