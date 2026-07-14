#pragma once
#include "Entity/Player.h"
#include "EventObservers/ISubscriber.h"
#include "Utility.h"

#include <ctime>
#include <format>
#include <iostream>
#include <string>

#include "Item.h"

#include <vector>
#include "Item.h"

class GameLogger : public ISubscriber
{
private:
    std::vector<std::string> m_logs;
    static const size_t m_maxLogs = 5;

    void onUpdate(Map &map, Player &player, Enemy &enemy, EventType eventType) override
    {
        switch ( eventType )
        {
        case EventType::ENEMY_ATTACKING_PLAYER:
            log(std::format("{} is being attacked!", global_game_rules::gPlayerName));
            break;

        case EventType::PLAYER_ATTACKING:
            log(std::format("{} dealt {} dmg to an enemy!",global_game_rules::gPlayerName,
                player.getAtk()));
            break;

        case EventType::EXIT_FOUND:
            log(std::format("{} found a way out for this level!", global_game_rules::gPlayerName));
            break;

        case EventType::GAME_OVER:
            log(std::format("{} perished!", global_game_rules::gPlayerName));
            break;

        case EventType::ENEMY_DEAD:
            log(std::format("The Enemy perished!"));
            break;

        }
    }

    void onUpdate(Map &map, Player &player, Item &item, EventType eventType) override
    {
        if ( eventType == EventType::PICKING_ITEM )
        {
            log(std::format("{} picked up a {}!", global_game_rules::gPlayerName, item.getName()));
        }
    }

    void log(const std::string& info)
    {
        time_t now = time(nullptr);
        struct tm tstruct;
        char buff[80];
        tstruct = *localtime(&now);
        strftime(buff, sizeof(buff), "%X", &tstruct);

        std::string formattedMsg = std::format("[{}] {}", buff, info);
        m_logs.push_back(formattedMsg);
    }

public:
    void displayLogs()
    {
        if ( m_logs.size() >= m_maxLogs )
            emptyLogs();

        for ( const auto& msg : m_logs )
            std::cout << msg << "\n";
    }

    void emptyLogs()
    {
        m_logs.clear();
    }
};

