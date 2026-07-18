cmake_minimum_required(VERSION 3.15)
project(RogueCPP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE TOUS_LES_FICHIERS CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

add_executable(RogueCPP ${TOUS_LES_FICHIERS}
        src/Entity/Strategies/IEnemyStrategy.h
        src/Entity/Strategies/AttackStrategy.h
        src/Entity/Strategies/WalkingStrategy.h
        src/EventObservers/ISubscriber.h
        src/EventObservers/LogPublisher.h
        src/Entity/Strategies/EscapingStrategy.h
        src/Views/GameLogger.h
        src/Entity/Strategies/AttackStrategy.cpp
        src/Entity/Strategies/EscapingStrategy.cpp
        src/Entity/Strategies/WalkingStrategy.cpp)

target_include_directories(RogueCPP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")