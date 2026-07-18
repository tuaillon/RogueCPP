#include "AttackStrategy.h"

#include "Entity/Enemy.h"

void AttackStrategy::executeStrategy(Enemy &enemy, Map &map, Player &player)
{
    if ( enemy.isNextToPlayer(map, player) )
        enemy.performAttack(player);
    else
        enemy.moveRandomly(map);
}