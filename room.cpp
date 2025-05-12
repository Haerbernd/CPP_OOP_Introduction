#ifndef ROOM_CPP
#define ROOM_CPP

#include "gameCharacter.h"
#include <vector>

struct room {
    int row;
    int col;

    std::vector<GameCharacter> enemies;
};

#endif