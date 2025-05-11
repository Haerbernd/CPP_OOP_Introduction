#include "game.h"

Game::Game(Player * _player, Dungeon * _dungeon) {
    player = _player;
    dungeon = _dungeon;
    isGameOver = false;

    dungeon->setUpDungeon();
    player->currentRoom = &dungeon->rooms[dungeon->rows-dungeon->rows] [dungeon->cols-dungeon->cols];
}