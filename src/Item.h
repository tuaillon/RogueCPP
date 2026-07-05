#pragma once

#include "Entity/Player.h"

class Item
{
protected:
	int m_x = 0;
	int m_y = 0;

public:

	virtual ~Item() = default;

	virtual char getRepresentation() const { return ' '; };
	virtual void use(Player& player) {};

	inline static int max_items = 10;
};


class Potion : public Item
{
private:
	int m_healingAmount = 12;

public:

	char getRepresentation() const override { return '!'; }

	void use(Player& player) override
	{
		player.addHealth(m_healingAmount);
	}
};

class Weapon : public Item
{
private:
	int m_atkBuff = 13;

public:

	char getRepresentation() const override { return '/'; }

	void use(Player& player) override
	{
		player.addAttack(m_atkBuff);
	}
};


class Armor : public Item
{
private:
	int m_defBuff = 13;

public:
	char getRepresentation() const override { return '['; }

	void use(Player& player) override
	{
		player.addDefense(m_defBuff);
	}
};


class ItemCreator
{

private:
	ItemCreator();

public:

	static Item* createRandomItem()
	{
		int itemType = rand() % 3;
		switch ( itemType )
		{
		case 0:
			return new Potion();
		case 1:
			return new Weapon();
		case 2:
			return new Armor();
		default:
			return new Item();
		}
	}
};