#include <iostream>
#include "Fighter.h"
#include "menu.h"
#include "startgame.h"
#include "round.h"
using namespace std;

int main() {
    GameMenu();

    // Add this part to prevent the window from closing
    cout << "Press Enter to close the game..." << endl;
    cout << "To play again, open the main application found in my GitHub." << endl;
    cout << "Nice playing with you!" << endl;
    cin.ignore(); // Flush leftover newline from previous input
    cin.get();    // Waits for Enter key

    return 0;
}
