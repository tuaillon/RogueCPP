#include "Player.h"

#include "../Map.h"
#include "Enemy.h"

void Player::takeDamage(int damage)
{
	int actualDamage = damage - m_def;
	if ( actualDamage > 0 )
	{
		m_hp -= actualDamage;
	}
	else
	{

	}
}

void Player::performMove(Map& map, char action)
{
	int newX = m_x;
	int newY = m_y;

	switch ( static_cast<Action>(action) )
	{
	case Action::UP:
		newY--;
		break;

	case Action::DOWN:
		newY++;
		break;

	case Action::LEFT:
		newX--;
		break;

	case Action::RIGHT:
		newX++;
		break;

	default:
		return;
	}

	std::pair<int, int> newPos = std::make_pair(newX, newY);
	if ( map.hasEnemyAt(newPos) )
	{
        Entity* enemy = map.getEnemyAt(newPos);
		std::cout << YELLOW << "You attack the enemy!" << RESET << "\n";
		this->performAttack(*enemy);
		if ( enemy->isAlive() )
		{
			std::cout << GREEN << "The enemy is dead!" << RESET << "\n";
			map.removeEnemy(newPos);
		}
		return;
	}

	if ( !canPerformMove(map, action) )
		return;

	m_y = newY;
	m_x = newX;

	map.updatePlayerPosition(std::make_pair(newX, newY), *this);
}

Player::Player()
{
	m_level = 1;
	m_gold = 0;
	m_status = Status::NORMAL;
	m_atk = 16;
	m_hp = 12;
	m_x = 0;
	m_y = 0;
	m_def = 0;

}

void Player::logStats()
{
	std::cout << "Level " << BLUE << m_level << RESET << "   Gold: " << 
		YELLOW << m_gold << RESET <<
		"   Hp: " << RED << m_hp << RESET << "   Str: " << MAGENTA <<
		m_atk << RESET << "   Def: " << WHITE << m_def << RESET <<
		"   Status : " << BOLDCYAN << m_status << RESET << "\n";

}