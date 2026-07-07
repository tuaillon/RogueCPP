#pragma once

#include "IEnemyStrategy.h"

class WalkingStrategy : IEnemyStrategy
{
public:
    void executeStrategy(Enemy &enemy, Map &map, Player &player) override
    {
        enemy.moveRandomly(map, player);
    }
};

