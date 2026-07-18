#pragma once
#include "IEnemyStrategy.h"

class EscapingStrategy : public IEnemyStrategy
{
public:
    void executeStrategy(Enemy& enemy, Map& map, Player& player) override;
};