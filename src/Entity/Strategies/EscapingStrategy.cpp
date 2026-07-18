#include "EscapingStrategy.h"

#include "Entity/Enemy.h"

void EscapingStrategy::executeStrategy(Enemy &enemy, Map &map, Player &player)
{
    if ( enemy.isNextToPlayer(map, player) )
        enemy.performAttack(player);
    else
        enemy.moveRandomly(map);
}