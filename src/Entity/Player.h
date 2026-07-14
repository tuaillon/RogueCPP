#pragma once

#include <iostream>

#include "../Utility.h"
#include "Entity.h"

class Map;

enum Status
{
	WEAK,
	HUNGRY,
	EXHAUSTED,
	NORMAL

};

inline std::ostream& operator<<(std::ostream& os, Status s)
{
	switch ( s )
	{
	case WEAK:      return os << "WEAK";
	case HUNGRY:    return os << "HUNGRY";
	case EXHAUSTED: return os << "EXHAUSTED";
	case NORMAL:    return os << "NORMAL";
	default:        return os << "UNKNOWN";
	}
}

class Player : public Entity
{

private:

	int m_def;
	int m_level;
	int m_gold;
	Status m_status;

public:

	inline static const char representation = '@';

	void takeDamage(int damage) override;

	void performMove(Map& map, char action);
		
	Player();

	void addHealth(int amount)
	{
		m_hp += amount;
	}

	void addDefense(int amount)
	{
		m_def += amount;
	}
	
	void addAttack(int amount)
	{
		m_atk += amount;
	}

	void logStats() const;

};