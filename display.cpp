#include <iostream>
#include <iomanip>
#include <vector>
#include "display.h"
#include "properties.h" // Assuming this header defines the Property struct
#include "players.h"    // Assuming this header defines the Player struct

using namespace std;

string getPlayerAtPosition(int position, const vector<Player>& players);

void displayBoard(const vector<Property>& properties, const vector<Player>& players) {
    int size = properties.size();
    int side = size / 4;

    // Top row
    for (int i = 0; i < side; ++i) {
        cout << "+-------------";
    }
    cout << "+" << endl;

    for (int i = 0; i < side; ++i) {
        cout << "| " << setw(11) << left << properties[i].name;
    }
    cout << "|" << endl;

    for (int i = 0; i < side; ++i) {
        cout << "| $" << setw(10) << left << properties[i].price;
    }
    cout << "|" << endl;

    for (int i = 0; i < side; ++i) {
        cout << "| R$" << setw(9) << left << properties[i].rent;
    }
    cout << "|" << endl;

    for (int i = 0; i < side; ++i) {
        cout << "| " << setw(11) << left << getPlayerAtPosition(i, players);
    }
    cout << "|" << endl;

    for (int i = 0; i < side; ++i) {
        cout << "+-------------";
    }
    cout << "+" << endl;

    // Middle rows
    for (int i = 1; i < side - 1; ++i) {
        cout << "| " << setw(11) << left << properties[size - i].name;
        for (int j = 1; j < side - 1; ++j) {
            cout << "|             ";
        }
        cout << "| " << setw(9) << left << properties[side + i - 1].name;
        cout << "|" << endl;

        cout << "| $" << setw(9) << left << properties[size - i].price;
        for (int j = 1; j < side - 1; ++j) {
            cout << "|             ";
        }
        cout << "| $" << setw(9) << left << properties[side + i - 1].price;
        cout << "|" << endl;

        cout << "| R$" << setw(9) << left << properties[size - i].rent;
        for (int j = 1; j < side - 1; ++j) {
            cout << "|             ";
        }
        cout << "| R$" << setw(7) << left << properties[side + i - 1].rent;
        cout << "|" << endl;

        for (int j = 0; j < side; ++j) {
            cout << "| " << setw(11) << left << getPlayerAtPosition(size - i + j, players);
        }
        cout << "|" << endl;

        for (int j = 0; j < side; ++j) {
            cout << "+-------------";
        }
        cout << "+" << endl;
    }

    // Bottom row
    for (int i = size - side; i < size; ++i) {
        cout << "| " << setw(11) << left << properties[i].name;
    }
    cout << "|" << endl;

    for (int i = size - side; i < size; ++i) {
        cout << "| $" << setw(10) << left << properties[i].price;
    }
    cout << "|" << endl;

    for (int i = size - side; i < size; ++i) {
        cout << "| R$" << setw(9) << left << properties[i].rent;
    }
    cout << "|" << endl;

    for (int i = size - side; i < size; ++i) {
        cout << "| " << setw(11) << left << getPlayerAtPosition(i, players);
    }
    cout << "|" << endl;

    for (int i = 0; i < side; ++i) {
        cout << "+-------------";
    }
    cout << "+" << endl;
}

string getPlayerAtPosition(int position, const vector<Player>& players) {
    for (const auto& player : players) {
        if (player.currentPosition == position) {
            return player.name;
        }
    }
    return "";
}
