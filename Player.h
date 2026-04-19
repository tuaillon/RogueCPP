#pragma once

#include <iostream>
#include "map.h"

namespace player
{
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
		switch (s)
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

		bool canPerformAction(Map& map, char action);

	public:

		inline static std::string representation = "@";
		
		Player();

		void logStats();
	};

}