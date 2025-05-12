#ifndef GAME_H
#define GAME_H

#include "dungeon.h"
#include "player.h"

#include <iostream>
#include <vector>

class Game {
    private:
        Dungeon * dungeon;
        Player * player;

    public:
        bool isGameOver;

        Game(Player *, Dungeon *);

        std::vector<std::string> getMovementActions();
        void handleMovementActions();
        static void printActions(std::vector<std::string> actions);
        void initiateRoomSequence();
        void handleEnemyActions();
        void engageInCombat();
};

#endif