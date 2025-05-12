#include "game.h"
#include <cstdlib>

int main() {
    std::string name;
    std::cout << "Welcome to the dungeon!\nWhat is your name?" << std::endl;
    std::cin >> name;

    Player player {name, 100, 10};
    Dungeon dungeon;
    Game game {&player, &dungeon};

    std::cout << "Good luck, " << name << "!\nBeware the monsters in the dungeon.\n\n";

    while (!game.isGameOver) {
        game.initiateRoomSequence();
    }

    return EXIT_SUCCESS;
}