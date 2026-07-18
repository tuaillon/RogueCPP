#include "WalkingStrategy.h"

#include "Entity/Enemy.h"

void WalkingStrategy::executeStrategy(Enemy &enemy, Map &map, Player &player)
{
    enemy.moveRandomly(map);
}