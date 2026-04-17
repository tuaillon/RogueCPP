#pragma once
#include <iostream>


namespace player
{
	enum status
	{
		WEAK,
		HUNGRY,
		EXHAUSTED,
		NORMAL

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

		int m_level;
		int m_gold;
		int m_hp;
		int m_str;
		status m_status;

	public:

		inline static std::string representation = "@";
		
		Player();

		void logStats();
	};

}