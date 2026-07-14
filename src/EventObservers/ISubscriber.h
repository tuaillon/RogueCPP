#pragma once

class Map;
class Player;
class Enemy;

enum class EventType
{
    PLAYER_ATTACKING,
    ENEMY_ATTACKING_PLAYER,
    PICKING_ITEM,
    GAME_OVER,
    EXIT_FOUND,
    ENEMY_DEAD
};

class ISubscriber
{
public:
    virtual void onUpdate(Map& map, Player& player, Enemy& enemy, EventType eventType) = 0;
    virtual ~ISubscriber() = default;
};


