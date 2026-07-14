#pragma once
#include "Entity/Player.h"
#include "EventObservers/ISubscriber.h"
#include "Utility.h"

#include <ctime>
#include <format>
#include <iostream>
#include <string>

class GameLogger : public ISubscriber
{
private:
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

        case EventType::PICKING_ITEM:
            log(std::format("{} picked up an item!", global_game_rules::gPlayerName));
            break;

        case EventType::GAME_OVER:
            log(std::format("{} perished!", global_game_rules::gPlayerName));
            break;

        case EventType::ENEMY_DEAD:
            log(std::format("The Enemy perished!"));
            break;

        }
    }
public:

    void log(const std::string& info) const
    {
        time_t now = time(nullptr);
        struct tm tstruct;
        char buff[80];
        tstruct = *localtime(&now);
        strftime(buff, sizeof(buff), "%X", &tstruct);

        std::cout << "[" << buff << "] " << info << "\n";

    }
};

