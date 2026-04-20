#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>

#include "Player.h"
#include "Map.h"

int main() 
{
	srand(time(nullptr));

	Player player;
	Map map(player);

	bool gameRunning = true;

	while ( gameRunning )
	{
		map.display();
		player.logStats();

		std::cout << "Awaiting for input...\n";

		char input;
		input = _getch();

		player.performMove(map, input);

		system("cls"); //cear console

	}

	return 0;
}