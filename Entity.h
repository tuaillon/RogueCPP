#pragma once

class Entity
{
public:

    virtual bool isAlive(){return m_hp > 0;}


    virtual void takeDamage(int damage)
    {
        m_hp -= damage;
    }
    virtual void performAttack(Entity& entity)
    {
        entity.takeDamage(m_atk);
    }

protected:

    int m_x;
    int m_y;

    int m_hp;
    int m_atk;
};