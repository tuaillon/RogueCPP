#pragma once

class Entity
{

protected:

    int m_x;
    int m_y;

    int m_hp;
    int m_atk;

public:

    inline static const char representation = ' ';

    virtual bool isAlive(){return m_hp > 0;}


    virtual void takeDamage(int damage)
    {
        m_hp -= damage;
    }
    virtual void performAttack(Entity& entity)
    {
        entity.takeDamage(m_atk);
    }

    std::pair<int, int> getPosition()
    {
        return std::make_pair(m_x, m_y);
    }
};