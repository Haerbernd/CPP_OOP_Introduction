#include "player.h"

Player::Player(std::string _name, int _health, int _damage): GameCharacter(_name, _health, _damage) {}

void Player::heal(int amount) {
    currentHealth += amount;

    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}

void Player::moveToRoom(room * nextRoom) {
    previousRoom = currentRoom;
    currentRoom = nextRoom;
}

void Player::retreat() {
    room * tempRoom = currentRoom;
    currentRoom = previousRoom;
    previousRoom = tempRoom;
}

void Player::pickUpItem(item _item) {
    heal(_item.health);
    damage += _item.damage;
}

int Player::getMaxHealth() {
    return maxHealth;
}
