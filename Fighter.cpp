#include <iostream>
#include "Fighter.h"
using namespace std;

Fighter::Fighter(std::string name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

string Fighter::getName() const { return name; }
int Fighter::getHealth() const { return health; }
int Fighter::getAttackPower() const { return attackPower; }

void Fighter::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

bool Fighter::isDefeated() const {
    return health <= 0;
}

void Fighter::displayMoves() const {
    string moves[4] = { "Punch", "Kick", "Special Attack", "Ultimate Move" };
    int moveDamages[4] = { 10, 15, 25, 35 };
    for (int i = 0; i < 4; ++i) {
        cout << (i + 1) << ". " << moves[i] << " (Damage: " << moveDamages[i] << ")\n";
    }
}

int Fighter::useMove(int choice) {
    int moveDamages[4] = { 10, 15, 25, 35 };
    if (choice < 1 || choice > 4) return 0;
    return moveDamages[choice - 1];
}