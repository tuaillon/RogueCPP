#pragma once

#include "Entity.h"
#include "Player.h";

enum Behaviour
{
	STILL,
	AGRESSIVE,
	RANDOM
};

class Enemy : Entity
{
private:
	Behaviour m_behaviour;

public:

	Enemy();
	~Enemy();
};
