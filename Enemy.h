#pragma once

#include "Entity.h"

enum Behaviour
{
	STILL,
	AGRESSIVE,
	RANDOM
};


class Enemy : Entity
{
public:
	Enemy();
	~Enemy();
};
