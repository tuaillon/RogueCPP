#include "Entity.h"
#include "../Map.h"
#include "../Utility.h"

bool Entity::canPerformMove(const Map & map, char action)
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
        return false;
    }

    if ( newX < 0 || newY < 0 )
    {
        return false;
    }

    if ( newX >= map.m_max_lvlLength || newY >= map.m_max_lvlHeight )
    {
        return false;
    }

    if ( (*map.m_map)[newY][newX] == map.horizontalWall_representation ||
        (*map.m_map)[newY][newX] == map.verticalWall_representation )
    {
        return false;
    }

    return true;
}
