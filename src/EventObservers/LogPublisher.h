#pragma once
#include "ISubscriber.h"

#include <vector>

enum class EventType
{
    PLAYER_ATTACKING,
    ENEMY_ATTACKING_PLAYER,
    PICKING_ITEM,
    GAME_OVER,
    EXIT_FOUND
};


class LogPublisher
{
private:
    std::vector<ISubscriber*> m_subscribers;

    LogPublisher() = default;
    LogPublisher instance = nullptr;

public:

    static LogPublisher& getInstance()
    {
        if ( instance == nullptr )
            LogPublisher instance();

        return *instance;
    }

    void subscribe(ISubscriber* subscriber)
    {
        m_subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber)
    {
        m_subscribers.remove(subscriber);
    }

    void publish(Map& map, Player& player, Enemy& enemy, EventType eventType)
    {
        for ( const auto& subscriber : m_subscribers )
            subscriber->onEvent(map, player, eventType);
    }


};

