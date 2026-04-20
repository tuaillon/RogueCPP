#pragma once

class Entity
{
public:

    virtual bool isAlive()
    {
        return m_hp > 0;
    }

protected:

    int m_x;
    int m_y;

    int m_hp;
    int m_def;
    int m_atk;
};