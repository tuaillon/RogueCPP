#pragma once
#include "IEnemyStrategy.h"

class AttackStrategy : public IEnemyStrategy
{
public:
    void executeStrategy(Enemy& enemy, Map& map, Player& player) override;
};