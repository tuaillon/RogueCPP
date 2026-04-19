#pragma once

#include <iostream>

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

class Player
{

private:

	int m_x;
	int m_y;
	int m_level;
	int m_gold;
	int m_hp;
	int m_str;
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

	void logStats();


	inline static const char representation = '@';

};