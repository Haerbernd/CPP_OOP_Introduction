#ifndef GAME_H
#define GAME_H

#include "dungeon.h"
#include "player.h"

class Game {
    private:
        Dungeon * dungeon;
        Player * player;

    public:
        bool isGameOver;

        Game(Player *, Dungeon *);
};

#endif