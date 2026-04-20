#pragma once

#include "Player.h"

class Item
{
protected:
	int m_x;
	int m_y;

public:

	virtual ~Item();

	char representation;
	virtual void use(Player& player);
};


class Potion : Item
{
private:
	int m_healingAmount = 12;

public:
	char representation = '!';

	void use(Player& player) override
	{
		player.addHealth(m_healingAmount);
	}
};

class Weapon : Item
{
private:
	int m_atkBuff = 13;

public:
	char representation = '/';

	void use(Player& player) override
	{
		player.addAttack(m_atkBuff);
	}
};


class Armor : Item
{
private:
	int m_defBuff = 13;

public:
	char representation = '/';

	void use(Player& player) override
	{
		player.addDefense(m_defBuff);
	}
};