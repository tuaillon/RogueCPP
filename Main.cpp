#include <iostream>
#include <ctime>

#include "Player.h"
#include "Map.h"

int main()
{
    srand(time(nullptr));

	Map map;
    map.display();
    player::Player player;
    player.logStats();

}
