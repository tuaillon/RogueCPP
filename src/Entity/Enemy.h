#pragma once

#include "Entity.h"
#include "Map.h"
#include "Player.h"
#include "Strategies/IEnemyStrategy.h"
#include "Strategies/AttackStrategy.h"
#include "Strategies/WalkingStrategy.h"


#include <cmath>


class Enemy : public Entity
{
  protected:
    IEnemyStrategy *m_strategy;

  public:
    virtual ~Enemy()
    {
        delete m_strategy;
    }

    Enemy(int hp = 10, int atk = 2, IEnemyStrategy *strategy = nullptr)
        : m_strategy(strategy)
    {
        m_hp = hp;
        m_atk = atk;
    }

    void executeStrategy(Map &map, Player &player)
    {
        if ( m_strategy )
            m_strategy->executeStrategy(*this, map, player);
    }

    void takeDamage(int damage) override
    {
        Entity::takeDamage(damage);
    }

    [[nodiscard]] virtual char getRepresentation() const { return 'E'; }

    bool isNextToPlayer(Map &map, Player &player)
    {
        std::pair<int, int> playerPos = player.getPosition();
        std::pair<int, int> enemyPos = getPosition();

        int dx = std::abs(enemyPos.first - playerPos.first);
        int dy = std::abs(enemyPos.second - playerPos.second);

        return (dx <= 1 && dy <= 1) && !(dx == 0 && dy == 0);
    }

    void moveRandomly(Map &map)
    {
        bool valid = false;

        int nx = m_x;
        int ny = m_y;
        int attempts = 0;

        while ( !valid && attempts < 10 )
        {
            nx = m_x;
            ny = m_y;
            int dir = rand() % 4;
            if ( dir == 0 ) ny--;
            if ( dir == 1 ) ny++;
            if ( dir == 2 ) nx--;
            if ( dir == 3 ) nx++;

            if ( map.isMoveValid(std::make_pair(nx, ny)) )
                valid = true;
            attempts++;
        }

        if ( valid )
            this->performMove(map, nx, ny);
    }

    void performMove(Map &map, int newX, int newY)
    {
        std::pair<int, int> oldPos = getPosition();
        m_x = newX;
        m_y = newY;
        map.updateEnemyPosition(oldPos, std::make_pair(newX, newY), *this);
    }
};

class Kestrel : public Enemy
{
  public:
    inline static const char representation = 'K';

    char getRepresentation() const override { return representation; }

    Kestrel() : Enemy(10, 5, new AttackStrategy()) {}
};

class Bat : public Enemy
{
  public:
    inline static const char representation = 'B';

    char getRepresentation() const override { return representation; }

    Bat() : Enemy(9, 2, new WalkingStrategy()) {}
};

class EnemyCreator
{
  public:
    static Enemy *createEnemyByRepresentation(char representation)
    {
        switch ( representation )
        {
        case Kestrel::representation:
            return new Kestrel();

        case Bat::representation:
            return new Bat();

        default:
            return new Enemy();
        }
    }

    static Enemy *createRandomEnemy()
    {
        int randomValue = rand() % 2;
        switch ( randomValue )
        {
        case 0:
            return new Kestrel();
        case 1:
            return new Bat();
        default:
            return new Enemy();
        }
    }
};