#pragma once

#include "../Player.h"

class IEnemyStrategy
{
public:
    inline virtual void executeStrategy(Map& map, Player& player);
};
