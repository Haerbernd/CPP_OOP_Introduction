#include <iostream>
#include <string>
#include <cstdlib>

class GameCharacter {
    public:
        static std::string type;

        std::string name;
        int currentHealth;
        int damage;
        bool isAlive;

    GameCharacter(std::string, int, int);
    void takeDamage(int);
};



GameCharacter::GameCharacter(std::string _name, int _health, int _damage): name(_name), currentHealth(_health), damage(_damage) {
    isAlive = true;
}

void GameCharacter::takeDamage(int amount) {
    currentHealth -= amount;
    if (currentHealth <= 0) {
        currentHealth = 0;
        isAlive = false;
    }
}

void attack(GameCharacter * attacker, GameCharacter * target) {
    target->takeDamage(attacker->damage);
}

class Player: public GameCharacter {
    public:
        static std::string type;

        int maxHealth;
        int armor;

    Player(std::string, int, int, int);
    void heal(int);
    void takeDamage(int);
};

Player::Player(std::string _name, int _maxHealth, int _currentHealth, int _damage): GameCharacter(_name, _currentHealth, _damage) {
    maxHealth = _maxHealth;
    armor = 5;
}

void Player::takeDamage(int amount) {
    if (amount - armor) {
        return;
    }
    currentHealth -= (amount - armor);
    if (currentHealth <= 0) {
        currentHealth = 0;
        isAlive = false;
    }
}


void Player::heal(int amount) {
    currentHealth += amount;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}

int main() {
    GameCharacter alice = Player("Alice", 100, 100, 10);
    GameCharacter goblin1 = GameCharacter("Goblin", 50, 5);
    GameCharacter goblin2 ("Goblin", 50, 5);
    GameCharacter goblin3 {"Goblin", 50, 5};
    GameCharacter goblin4 = {"Goblin", 50, 5};

    return EXIT_SUCCESS;
}