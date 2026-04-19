#include "Player.h"

bool player::Player::canPerformAction(Map& map, char action)
{
	switch (action)
	{
		case action::UP:
			break;

		case action::DOWN:
			break;

		case action::LEFT:
			break;

		case action::RIGHT:
			break;
	}

	return true;
}

player::Player::Player()
{
	m_level = 1;
	m_gold = 0;
	m_status = player::status::NORMAL;
	m_str = 16;
	m_hp = 12;
}

void player::Player::logStats()
{
	std::cout << "Level " << m_level << "   Gold: " << m_gold <<
		"   Hp: " << m_hp << "   Str: " << m_str << "   Status : " << m_status << "\n";

}
 