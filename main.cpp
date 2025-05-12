#include "game.h"
#include <cstdlib>

int main() {
    Player player {"Alice", 100, 10};
    Dungeon dungeon;
    Game game {&player, &dungeon};

    while (!game.isGameOver) {
        game.initiateRoomSequence();
    }

    return EXIT_SUCCESS;
}