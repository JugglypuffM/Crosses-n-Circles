//
// Created by Jugglyuser on 23.05.2023.
//
#pragma once
#include "iostream"
#include "string"
#include "Player.h"

using namespace std;

class Interface {
public:
    void initiate();
    void make_turn();
    void print_state();
    bool check_end();
    bool quit();
};

class Game{
    int x, o, difficulty;
    Player x_player, o_player;
    Player* current_turn;
public:
    void set_options(int, Player, Player);
    void do_turn(string);
    int check_winner();
    bool check_emptiness(int, int);
    string return_state();
    Player* whose_turn();
};

extern Game game;
extern string input;