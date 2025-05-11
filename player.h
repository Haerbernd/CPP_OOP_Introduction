#ifndef PLAYER_H
#define PLAYER_H

#include "gameCharacter.h"
#include "room.cpp"

class Player: public GameCharacter {
    private:
        room * previousRoom;

    public:
        room * currentRoom;

        Player(std::string, int, int);
        void heal(int);
        void moveToRoom(room *);
        void retreat();
};

#endif
