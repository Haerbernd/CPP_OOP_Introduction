cmake_minimum_required(VERSION 3.31)
project(Basic_Dungeon_Crawler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Basic_Dungeon_Crawler main.cpp
        room.cpp
        dungeon.cpp
        dungeon.h
        gameCharacter.cpp
        gameCharacter.h
        player.cpp
        player.h
        game.cpp
        game.h
        item.cpp)
