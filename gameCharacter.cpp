#include "gameCharacter.h"

GameCharacter::GameCharacter(std::string _name, int _health, int _damage): name(_name), maxHealth(_health), currentHealth(_health), damage(_damage) {}

bool GameCharacter::checkIfAlive() {
    return currentHealth > 0;
}

int GameCharacter::getDamage() {
    return damage;
}

int GameCharacter::getHealth() {
    return currentHealth;
}

std::string GameCharacter::getName() {
    return name;
}

void GameCharacter::takeDamage(int amount) {
    currentHealth -= amount;
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}
