cmake_minimum_required(VERSION 3.31)
project(CPP_OOP_Introduction)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_Intro_Game main.cpp
        room.cpp
        dungeon.cpp
        dungeon.h
        gameCharacter.cpp
        gameCharacter.h
        player.cpp
        player.h
        game.cpp
        game.h)
