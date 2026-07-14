#include "Player.h"

#include "../Map.h"
#include "Enemy.h"
#include "EventObservers/LogPublisher.h"

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

	switch ( static_cast<global_game_rules::Action>(action) )
	{
	case global_game_rules::Action::UP:
		newY--;
		break;

	case global_game_rules::Action::DOWN:
		newY++;
		break;

	case global_game_rules::Action::LEFT:
		newX--;
		break;

	case global_game_rules::Action::RIGHT:
		newX++;
		break;

	default:
		return;
	}

	std::pair<int, int> newPos = std::make_pair(newX, newY);
	if ( map.hasEnemyAt(newPos) )
	{
        Enemy* enemy = map.getEnemyAt(newPos);
		LogPublisher::getInstance().publish(map, *this, enemy, EventType::PLAYER_ATTACKING);
		this->performAttack(*enemy);
		if ( enemy->isAlive() )
		{
		    LogPublisher::getInstance().publish(map, *this, enemy, EventType::ENEMY_DEAD);
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

void Player::logStats() const
{
	std::cout << "Level " << BLUE << m_level << RESET << "   Gold: " << 
		YELLOW << m_gold << RESET <<
		"   Hp: " << RED << m_hp << RESET << "   Str: " << MAGENTA <<
		m_atk << RESET << "   Def: " << WHITE << m_def << RESET <<
		"   Status : " << BOLDCYAN << m_status << RESET << "\n";

}