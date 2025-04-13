#include "Fighter.h"
#include <iostream>
using namespace std;

void startRound(Fighter &player1, Fighter &player2) {
    int moveChoice;
    bool roundOngoing = true;

    while (roundOngoing) {
        // Player 1's turn
        player1.displayMoves();
        std::cout << player1.getName() << ", select your move (1-4): ";
        std::cin >> moveChoice;

        while (moveChoice < 1 || moveChoice > 4) {
            std::cout << "Invalid input! Please choose a move between 1 and 4: ";
            std::cin >> moveChoice;
        }

        int damage = player1.useMove(moveChoice);
        player2.takeDamage(damage);

        std::cout << player1.getName() << " attacks " << player2.getName() << " for " << damage << " damage!\n";
        std::cout << player2.getName() << "'s health: " << player2.getHealth() << "\n";

        if (player2.isDefeated()) break;

        // Player 2's turn
        player2.displayMoves();
        std::cout << player2.getName() << ", select your move (1-4): ";
        std::cin >> moveChoice;

        while (moveChoice < 1 || moveChoice > 4) {
            std::cout << "Invalid input! Please choose a move between 1 and 4: ";
            std::cin >> moveChoice;
        }

        damage = player2.useMove(moveChoice);
        player1.takeDamage(damage);

        std::cout << player2.getName() << " attacks " << player1.getName() << " for " << damage << " damage!\n";
        std::cout << player1.getName() << "'s health: " << player1.getHealth() << "\n";

        if (player1.isDefeated()) break;
    }

    // End-of-round results
    if (player1.isDefeated() && player2.isDefeated()) {
        std::cout << "It's a tie! Starting sudden death round!\n";

        // Reset health for sudden death
        player1 = Fighter(player1.getName(), 30, player1.getAttackPower());
        player2 = Fighter(player2.getName(), 30, player2.getAttackPower());

        startRound(player1, player2); // Call recursively for sudden death
    } else if (player1.isDefeated()) {
        std::cout << player1.getName() << " has been defeated! " << player2.getName() << " wins!\n";
    } else if (player2.isDefeated()) {
        std::cout << player2.getName() << " has been defeated! " << player1.getName() << " wins!\n";
    }

    while (player1.isDefeated() && player2.isDefeated()) {
        cout << "It's a tie! Sudden death begins!\n";
        player1 = Fighter(player1.getName(), 30, player1.getAttackPower());
        player2 = Fighter(player2.getName(), 30, player2.getAttackPower());
    }    
}


