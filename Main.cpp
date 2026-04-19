#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>

#include "Player.h"
#include "Map.h"

int main()
{
	srand(time(nullptr));

	Map map;
	player::Player player;
	bool gameRunning = true;

	while ( gameRunning )
	{
		map.display();
		player.logStats();

		std::cout << "Awaiting for input...\n";

		char input;
		input = _getch();
	}

}