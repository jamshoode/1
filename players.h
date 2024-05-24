#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <vector>
#include "properties.h"

struct Player {
    std::string name;
    int balance;
    std::vector<Property> properties;
    int currentPosition;

    Player(const std::string& n, int b, const std::vector<Property>& p, int pos) 
        : name(n), balance(b), properties(p), currentPosition(pos) {}
};

#endif
