#include <iostream>
#include <ctime>
#include <string>

#ifdef _WIN32

  #include <conio.h>

#else
  
  #include <termios.h>
  #include <unistd.h>
  #include <stdio.h>

  inline static int _getch()
  {
    struct termios oldattr, newattr;

    int ch;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;

    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
  }

#endif

#include "Entity/Player.h"
#include "Map.h"
#include "SaveHandler.h"
#include "Utility.h"

int main()
{
	srand(time(nullptr));
	/*
	char choice;
	do
	{
		std::cout << gGameLogo << "\n\n";
		std::cout << "[1] Start Game\n";
		std::cout << "[2] Load Save\n";
		std::cout << "[3] Instructions\n";
		std::cout << "[4] Exit\n";

		choice = _getch();

		switch ( choice )
		{
		case '1':
			break;
		case '2':
			std::cout << "Load Save not implemented yet.\n";
			break;
		case '3':
			std::cout << "Instructions not implemented yet.\n";
			break;
		case '4':
			return 0;

		}
	} while ( choice != '1' );
	*/

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



#ifdef __linux__
		system("clear");
#elif _WIN32
		system("cls");
#endif

	}

	return 0;
}
