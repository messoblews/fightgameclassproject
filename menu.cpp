#include <iostream>
#include "startgame.h"
using namespace std;

void GameMenu() {
    int option;
    bool validChoice = false;

    while (!validChoice) {
        cout << "== FIGHTING SPIRIT ==" << endl;
        cout << "1. BEGIN GAME" << endl;
        cout << "2. OPTIONS" << endl;
        cout << "3. QUIT GAME" << endl;
        cout << "Input a number: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "BOOTING UP YOUR GAME..." << endl;
                startGame();
                validChoice = true;
                break;
            case 2:
                cout << "OPENING YOUR LIST OF OPTIONS..." << endl;
                validChoice = true;
                break;
            case 3:
                cout << "GOODBYE!" << endl;
                validChoice = true;
                break;
            default:
                cout << "INVALID CHOICE! TRY AGAIN." << endl;
        }
    }
}

void gameOptions() {
    cout << "OPENING YOUR LIST OF OPTIONS..." << endl;
}

void exitGame() {
    cout << "GOODBYE" << endl;
    exit(0);
}