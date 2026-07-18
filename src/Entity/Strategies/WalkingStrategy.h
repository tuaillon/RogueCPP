#pragma once
#include "IEnemyStrategy.h"

class WalkingStrategy : public IEnemyStrategy
{
public:
    void executeStrategy(Enemy &enemy, Map &map, Player &player) override;
};

