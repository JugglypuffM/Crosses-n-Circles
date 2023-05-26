//
// Created by Jugglyuser on 23.05.2023.
//

#include "Player.h"

void Player::humanize() {
    human = true;
}

string Player::make_decision(int x, int o, int diff) const {
    string decision;
    if (human){
        cin >> decision;
        return decision;
    }else{
        if (diff == 0){
            for (int i = 0; i < 9; ++i) {
            }
        }
    }
}

bool Player::is_human() const {
    return human;
}
