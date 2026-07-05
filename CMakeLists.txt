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
        src/Entity/Strategies/AttackStrategy.h)

target_include_directories(RogueCPP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")