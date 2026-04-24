#pragma once

#include <stdlib.h>

#include "Entity.h"


enum EnemyBehaviour
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

};

class Kestrel : public Enemy
{
private:
	EnemyBehaviour m_behaviour = EnemyBehaviour::STILL;
	int m_atk = 5;
	int m_hp = 10;

public:
	inline static const char representation = 'K';
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
	Bat() = default;

};


class EnemyCreator
{
	public:

	static Enemy createEnemyByRepresentation(char representation)
	{
		switch ( representation )
		{
		case Kestrel::representation:

			return Kestrel();

		case Bat::representation:
			return Bat();
		default:
			return Enemy();
		}
	}

	static Enemy createRandomEnemy()
	{
		int randomValue = rand() % 2;
		switch ( randomValue )
		{
		case 0:
			return Kestrel();
		case 1:
			return Bat();
		default:
			return Enemy();
		}
	}
};
