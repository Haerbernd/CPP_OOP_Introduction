#include "game.h"

Game::Game(Player * _player, Dungeon * _dungeon) {
    player = _player;
    dungeon = _dungeon;
    isGameOver = false;

    dungeon->setUpDungeon();
    // player->currentRoom = &dungeon->rooms[dungeon->rows-1] [dungeon->cols-1]; // In case I want to change the starting location
    player->currentRoom = &dungeon->rooms[0] [0];
}

void Game::initiateRoomSequence() {
    handleMovementActions();
}


void Game::printActions(std::vector<std::string> actions) {
    for (int i = 0; i < actions.size(); i++) {
        std::cout << i + 1 << ". " << actions[i] << std::endl;
    }
}

std::vector<std::string> Game::getMovementActions() {
    std::vector<std::string> actions;

    room * currentRoom = player->currentRoom;
    if (currentRoom->col > 0) {
        actions.push_back("Move left");
    }
    if (currentRoom->row > 0) {
        actions.push_back("Move up");
    }
    if (currentRoom->col < (dungeon->cols-1)) {
        actions.push_back("Move right");
    }
    if (currentRoom->row < (dungeon->rows-1)) {
        actions.push_back("Move down");
    }
    return actions;
}

void Game::handleMovementActions() {
    std::cout << "Where do you want to go next?" << '\n';
    const std::vector<std::string> actions = getMovementActions();
    printActions(actions);

    // Would normally extract the next 3 "paragraphs" into (a) new function(s) but they are so interconnected that it would be messy
    int input;
    std::cin >> input;
    const std::string& chosenAction = actions[input - 1];

    int horizontalMovement = 0;
    int verticalMovement = 0;

    if (chosenAction == "Move left") {
        horizontalMovement = -1;
    } else if (chosenAction == "Move right") {
        horizontalMovement = 1;
    } else if (chosenAction == "Move up") {
        verticalMovement = -1;
    } else if (chosenAction == "Move down") {
        verticalMovement = 1;
    }

    room * newRoom = &dungeon->rooms[player->currentRoom->row + verticalMovement][player->currentRoom->col + horizontalMovement];
    player->moveToRoom((newRoom));

    std::cout << "You are now in room " << newRoom->row << " " << newRoom->col << std::endl;
}
