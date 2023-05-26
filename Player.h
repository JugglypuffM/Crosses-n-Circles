//
// Created by Jugglyuser on 23.05.2023.
//
#pragma once
#include "iostream"
#include "string"

using namespace std;

class Player{
    bool human = false;
public:
    void humanize();
    bool is_human() const;
    string make_decision(int, int, int) const;
};
