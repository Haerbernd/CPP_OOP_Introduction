#include <iostream>
#include <cstdlib>

class GameCharacter {
    public:
        std::string name;
        int maxHealth;
        int currentHealth;
        int damage;

    GameCharacter(std::string, int, int, int);
    GameCharacter(std::string, int, int);
};

GameCharacter::GameCharacter(std::string _name, int _maxHealth, int _currentHealth, int _damage) {
    name = _name;
    maxHealth = _maxHealth;
    currentHealth = _currentHealth;
    damage = _damage;
}

GameCharacter::GameCharacter(std::string _name, int _health, int _damage): name(_name), maxHealth(_health), currentHealth(_health), damage(_damage) {}



int main() {
    GameCharacter alice = GameCharacter("Alice", 100, 100, 10);
    GameCharacter goblin1 = GameCharacter("Goblin", 50, 5);
    GameCharacter goblin2 ("Goblin", 50, 5);
    GameCharacter goblin3 {"Goblin", 50, 5};
    GameCharacter goblin4 = {"Goblin", 50, 5};

    return EXIT_SUCCESS;
}