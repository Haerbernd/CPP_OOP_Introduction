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
    room * _room = player->currentRoom;

    if (_room->row == dungeon->rows-1 && _room->col == dungeon->cols-1 && _room->enemies.empty()) {
        std::cout << "Congratulations " << player->getName() << ", you have won and escape the dungeon!" << std::endl;
        isGameOver = true;
        return;
    }

    if (!_room->enemies.empty()) {
        handleEnemyActions();
    } else if (!_room->items.empty()) {
        handleItemActions();
    } else {
        handleMovementActions();
    }
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

void Game::handleEnemyActions() {
    std::cout << "There is an enemy " << player->currentRoom->enemies[0].getName() << " in this room!\nWhat would you like to do?\n";

    std::vector<std::string> actions;
    actions.push_back("Engage enemy");
    actions.push_back("Retreat");
    printActions(actions);

    int input;
    std::cin >> input;
    if (input == 1) {
        engageInCombat();
    } else {
        player->retreat();
    }
}

void Game::engageInCombat() {
    GameCharacter *enemy = &player->currentRoom->enemies[0];
    while (true) {
        enemy->takeDamage(player->getDamage());
        std::cout << "You strike the " << enemy->getName() << ", dealing " << player->getDamage() << " damage.\n";
        if (!enemy->checkIfAlive()) {
            std::cout << "You have defeated the " << enemy->getName() << "!\n\n";
            player->currentRoom->enemies.clear();
            return;
        }

        player->takeDamage(enemy->getDamage());
        std::cout << enemy->getName() << " attacked you! You took " << enemy->getDamage() << " damage.\nYou now have " << player->getHealth() << "/" << player->getMaxHealth() << " health.\n";
        if (!player->checkIfAlive()) {
            isGameOver = true;
            std::cout << "You were killed by " << enemy->getName() << "!" << std::endl;
            return;
        }

        std::cout << "Do you want to continue fighting?\n";

        std::vector<std::string> actions;
        actions.push_back("Yes, keep fighting.");
        actions.push_back("No, retreat");
        printActions(actions);

        int input;
        std::cin >> input;
        if (input != 1) {
            player->retreat();
            return;
        }
    }
}

void Game::handleItemActions() {
    const item _item = player->currentRoom->items[0];
    std::cout << "You find a " << _item.name << " in this room!\nWhat would you like to do?\n";

    std::vector<std::string> actions;
    actions.push_back("Use/pick up item");
    actions.push_back("Ignore item");
    printActions(actions);

    int input;
    std::cin >> input;
    if (input == 1) {
        player->pickUpItem(_item);
        std::cout << "You used/picked up a " << _item.name << ".\nYour damage is now " << player->getDamage() << " and you have " << player->getHealth() << "/" << player->getMaxHealth() << " health.\n";
        player->currentRoom->items.clear();
        handleMovementActions();
    } else {
        handleMovementActions();
    }
}
