#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include "properties.h"
#include "players.h"

void displayBoard(const std::vector<Property>& properties, const std::vector<Player>& players);
std::string getPlayerAtPosition(int position, const std::vector<Player>& players);

#endif
