#include <string>
#include <cstdlib>

class GameCharacter {
    public:
        std::string name;
        int maxHealth;
        int currentHealth;
        int damage;
        bool isAlive;

    GameCharacter(std::string, int, int, int);
    GameCharacter(std::string, int, int);
    void takeDamage(int);
    void heal(int);
};

GameCharacter::GameCharacter(std::string _name, int _maxHealth, int _currentHealth, int _damage) {
    name = _name;
    maxHealth = _maxHealth;
    currentHealth = _currentHealth;
    damage = _damage;
    isAlive = true;
}

GameCharacter::GameCharacter(std::string _name, int _health, int _damage): name(_name), maxHealth(_health), currentHealth(_health), damage(_damage) {
    isAlive = true;
}

void GameCharacter::takeDamage(int amount) {
    currentHealth -= amount;
    if (currentHealth <= 0) {
        currentHealth = 0;
        isAlive = false;
    }
}

void GameCharacter::heal(int amount) {
    currentHealth += amount;
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}





int main() {
    GameCharacter alice = GameCharacter("Alice", 100, 100, 10);
    GameCharacter goblin1 = GameCharacter("Goblin", 50, 5);
    GameCharacter goblin2 ("Goblin", 50, 5);
    GameCharacter goblin3 {"Goblin", 50, 5};
    GameCharacter goblin4 = {"Goblin", 50, 5};

    return EXIT_SUCCESS;
}