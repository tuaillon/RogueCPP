#include "Player.h"
#include "Map.h"

bool Player::canPerformMove(Map& map, char action)
{
	int newX = m_x;
	int newY = m_y;

	switch ( action )
	{
	case action::UP:
		newY--;
		break;

	case action::DOWN:
		newY++;
		break;

	case action::LEFT:
		newX--;
		break;

	case action::RIGHT:
		newX++;
		break;

	default:
		return false;
	}

	if ( newX < 0 || newY < 0 )
		return false;

	if ( newX >= map.m_max_lvlLength || newY >= map.m_max_lvlHeight )
		return false;

	if ((*map.m_map)[newY][newX] == map.horizontalWall_representation || 
		(*map.m_map)[newY][newX] == map.verticalWall_representation)
		return false;

	return true;
}

void Player::takeDamage(int damage)
{
	int actualDamage = damage - m_def;
	if ( actualDamage > 0 )
		m_hp -= actualDamage;
}

void Player::performMove(Map& map, char action)
{
	if ( !canPerformMove(map, action) )
		return;

	int newX = m_x;
	int newY = m_y;

	switch ( action )
	{

	case action::UP:
		newY--;
		break;

	case action::DOWN:
		newY++;
		break;

	case action::LEFT:
		newX--;
		break;

	case action::RIGHT:
		newX++;
		break;
	}
	m_y = newY;
	m_x = newX;

	map.updatePlayerPosition(std::make_pair(newX, newY));
}

Player::Player()
{
	m_level = 1;
	m_gold = 0;
	m_status = status::NORMAL;
	m_atk = 16;
	m_hp = 12;
	m_x = 0;
	m_y = 0;
	m_def = 0;

}

void Player::logStats()
{
	std::cout << "Level " << m_level << "   Gold: " << m_gold <<
		"   Hp: " << m_hp << "   Str: " << m_atk << "   Status : " << m_status << "\n";

}