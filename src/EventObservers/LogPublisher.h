#pragma once
#include "ISubscriber.h"

#include <vector>
#include <algorithm>

class LogPublisher
{
private:
    std::vector<ISubscriber*> m_subscribers;

    LogPublisher() = default;
    ~LogPublisher() = default;

    LogPublisher(const LogPublisher&) = delete;
    LogPublisher& operator=(const LogPublisher&) = delete;

public:
    static LogPublisher& getInstance()
    {
        static LogPublisher instance;
        return instance;
    }

    void subscribe(ISubscriber* subscriber)
    {
        m_subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber)
    {
        m_subscribers.erase(std::remove(m_subscribers.begin(), m_subscribers.end(), subscriber), m_subscribers.end());
    }

    void publish(Map& map, Player& player, Enemy* enemy, const EventType eventType) const
    {
        for ( auto& subscriber : m_subscribers )
            subscriber->onUpdate(map, player, *enemy, eventType);
    }
};
