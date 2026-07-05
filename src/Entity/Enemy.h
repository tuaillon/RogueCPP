#pragma once

#include "Entity.h"
#include "Strategies/IEnemyStrategy.h"

enum class EnemyBehaviour
{
	STILL,
	RANDOM,
	AGGRESSIVE
};

class Enemy : public Entity
{
private:
	EnemyBehaviour m_behaviour;
    IEnemyStrategy* m_strategy;

public:
	virtual ~Enemy() = default;
    Enemy(IEnemyStrategy* strategy) : m_strategy(strategy) {}

    void executeStrategy(Map& map, Player& player){ m_strategy->executeStrategy(map, player); }

	virtual char getRepresentation() const { return 'E'; }

    bool isNextToPlayer(Map& map, Player& player)
    {
        std::pair<int, int> playerPos = player.getPosition();

        

    }


protected:



};

class Kestrel : public Enemy
{
private:
	EnemyBehaviour m_behaviour = EnemyBehaviour::STILL;
	int m_atk = 5;
	int m_hp = 10;

public:
	inline static const char representation = 'K';

	char getRepresentation() const override { return representation; }

	Kestrel() = default;
};

class Bat : public Enemy
{
private:
	EnemyBehaviour m_behaviour = EnemyBehaviour::RANDOM;
	int m_atk = 2;
	int m_hp = 9;

public:
	inline static const char representation = 'B';

	char getRepresentation() const override { return representation; }

	Bat() = default;
};

class EnemyCreator
{
public:
	static Enemy* createEnemyByRepresentation(char representation)
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

	static Enemy* createRandomEnemy()
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