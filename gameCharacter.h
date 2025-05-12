#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>

class GameCharacter {
    private:
        std::string name;
        int damage;

    protected:
        int maxHealth;
        int currentHealth;

    public:
        GameCharacter(std::string _name, int _health, int _damage);
        void takeDamage(int amount);
        bool checkIfAlive();
        std::string getName();
        int getHealth();
        int getDamage();
};

#endif
