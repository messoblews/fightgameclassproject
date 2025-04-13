#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>

class Fighter {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Fighter(std::string name, int health, int attackPower);
    std::string getName() const;
    int getHealth() const;
    int getAttackPower() const;
    void takeDamage(int damage);
    bool isDefeated() const;

    // For roundtest.cpp support
    void displayMoves() const;
    int useMove(int choice);
};

void player1FightingRound(Fighter& player1, Fighter& opponent);

#endif