#pragma once

#include "Entity.h"

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

public:
	virtual ~Enemy() = default;

	virtual char getRepresentation() const { return 'E'; }
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