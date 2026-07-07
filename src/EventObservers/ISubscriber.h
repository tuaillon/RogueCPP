#pragma once
#include "Entity/Player.h"
#include "LogPublisher.h"
#include "Map.h"

class ISubscriber
{
public:
    virtual void onUpdate(Map& map, Player& player, Enemy& enemy, EventType eventType);
    virtual ~IEnemyStrategy() = default;
};

