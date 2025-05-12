#include "dungeon.h"

void Dungeon::setUpDungeon() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            room room{};
            room.row = r;
            room.col = c;
            rooms[r] [c] = room;
        }
    }

    GameCharacter bat1 {"Bat", 20, 5};
    GameCharacter bat2 {"Bat", 20, 5};
    GameCharacter rat1 {"Rat", 20, 10};
    GameCharacter rat2 {"Rat", 20, 10};
    GameCharacter rat3 {"Rat", 20, 10};
    GameCharacter goblin1 {"Goblin", 50, 15};
    GameCharacter goblin2 {"Goblin", 50, 15};
    GameCharacter troll {"Troll", 100, 20};

    /* As a little Help a Map:
     *  0 0 |   0 1 |   0 2
     *  1 0 |   1 1 |   1 2
     *  2 0 |   2 1 |   2 2
     */

    rooms[0][1].enemies.push_back(bat1);
    rooms[1][0].enemies.push_back(bat2);
    rooms[0][2].enemies.push_back(rat1);
    rooms[1][1].enemies.push_back(rat2);
    rooms[2][0].enemies.push_back(rat3);
    rooms[1][2].enemies.push_back(goblin1);
    rooms[2][1].enemies.push_back(goblin2);
    rooms[2][2].enemies.push_back(troll);
}
