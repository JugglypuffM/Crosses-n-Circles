#include <iostream>
#include "Interface.h"

using namespace std;

Game game;
Player* current_turn;
string input;

int main() {
    Interface interface;
    do {
        interface.initiate();
        do {
            interface.make_turn();
            interface.print_state();
        }while(!interface.check_end());
    } while (!interface.quit());
}
