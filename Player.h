#pragma once

#include <iostream>

#include "Entity.h"

class Map;

enum status
{
	WEAK,
	HUNGRY,
	EXHAUSTED,
	NORMAL

};

enum action
{
	UP = 'z',
	DOWN = 's',
	LEFT = 'q',
	RIGHT = 'd'
};


inline std::ostream& operator<<(std::ostream& os, status s)
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

class Player : Entity
{

private:

	int m_level;
	int m_gold;
	status m_status;

	bool canPerformMove(Map& map, char action);


public:

	void performMove(Map& map, char action);
		
	Player();

	void setPosition(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

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

	void logStats();


	inline static const char representation = '@';

};