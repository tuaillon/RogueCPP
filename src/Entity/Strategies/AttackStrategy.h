#pragma once
#include "IEnemyStrategy.h"
#include "../Enemy.h"

class AttackStrategy : public IEnemyStrategy
{
public:
    void executeStrategy(Enemy& enemy, Map& map, Player& player) override
    {
        if ( enemy.isNextToPlayer(map, player) )
            enemy.performAttack(player);
        else
            enemy.moveRandomly(map);
    }
};