#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "startgame.h"
#include "Fighter.h"
#include "round.h"

using namespace std;

struct Stage {
    string stageName;
};

// List of characters (fighters)
 vector<Fighter> fighters = {
    Fighter("Urameshi", 100, 30),
    Fighter("Kuwabara", 100, 20),
    Fighter("Ryu", 100, 25),
    Fighter("Ken", 100, 25),
    Fighter("Gohan", 100, 30),
    Fighter("Krillin", 100, 25)
};

vector<Stage> stages = {
    {"Tenkaichi Tournament"},
    {"Dark Tournament Field"},
    {"Night Field"}
};

void playerFight(Fighter &player1, Fighter &player2);

void startGame() {
    int mode, player1option, player2option, stageSelection;

    cout << "== GAME MODE ==" << endl;
    cout << "1. ARCADE MODE (SINGLEPLAYER)" << endl;
    cout << "2. 1v1 MULTIPLAYER MODE" << endl;
    cout << "Choose your game mode: ";
    while (!(cin >> mode)) {
        cin.clear(); // clear error flags
        cin.ignore(10000, '\n'); // discard invalid input
        cout << "Invalid input! Enter a number: ";
    }
    

    cout << "== PLAYER 1 CHARACTER SELECT ==" << endl;
    for (size_t i = 0; i < fighters.size(); ++i) {
        cout << i + 1 << ". " << fighters[i].getName()
             << " (HP: " << fighters[i].getHealth()
             << ", ATK: " << fighters[i].getAttackPower() << ")" << endl;
    }
    cout << "Select your character (1-6): ";
    while (!(cin >> mode)) {
        cin.clear(); // clear error flags
        cin.ignore(10000, '\n'); // discard invalid input
        cout << "Invalid input! Enter a number: ";
    }    

    cout << "== PLAYER 2 CHARACTER SELECT ==" << endl;
    for (size_t i = 0; i < fighters.size(); ++i) {
        cout << i + 1 << ". " << fighters[i].getName()
             << " (HP: " << fighters[i].getHealth()
             << ", ATK: " << fighters[i].getAttackPower() << ")" << endl;
    }
    cout << "Select your character (1-6): ";
    cin >> player2option;

    cout << "== CHOOSE YOUR BATTLEFIELD ==" << endl;
    for (size_t i = 0; i < stages.size(); ++i) {
        cout << i + 1 << ". " << stages[i].stageName << endl;
    }

    cout << "Pick your battlefield (1-3): ";
    cin >> stageSelection;

    cout << "\n** " << fighters[player1option - 1].getName()
         << " vs " << fighters[player2option - 1].getName()
         << " at " << stages[stageSelection - 1].stageName << " **\n";

    Fighter p1 = fighters[player1option - 1];
    Fighter p2 = fighters[player2option - 1];
    startRound(p1, p2);         

}

void playerFight(Fighter &player1, Fighter &player2) {
    srand(time(0));

    while (!player1.isDefeated() && !player2.isDefeated()) {
        cout << "\n" << player1.getName() << " HP: " << player1.getHealth()
             << " | " << player2.getName() << " HP: " << player2.getHealth() << endl;

        int player1damage = player1.getAttackPower() - rand() % 5;
        cout << player1.getName() << " attacks! Deals " << player1damage << " damage!\n";
        player2.takeDamage(player1damage);

        if (player2.isDefeated()) {
            cout << player2.getName() << " is defeated! " << player1.getName() << " wins!\n";
            break;
        }

        int player2damage = player2.getAttackPower() - rand() % 5;
        cout << player2.getName() << " attacks! Deals " << player2damage << " damage!\n";
        player1.takeDamage(player2damage);

        if (player1.isDefeated()) {
            cout << player1.getName() << " is defeated! " << player2.getName() << " wins!\n";
            break;
        }
    }
}