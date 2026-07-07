#pragma once

class Enemy;
class Map;
class Player;

class IEnemyStrategy
{
public:
    virtual ~IEnemyStrategy() = default;
    virtual void executeStrategy(Enemy& enemy, Map& map, Player& player) = 0;
};
