#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Include this header for std::find_if
#include "display.h"
#include "players.h"
#include "properties.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<Property> properties = {
        Property("Start", 0, 0, false, ""),
        Property("Prop 1", 1500, 100, false, ""),
        Property("Penalty", -1000, 0, false, ""),
        Property("Prop 2", 2000, 150, false, ""),
        Property("Prop 3", 2500, 200, false, ""),
        Property("Chance", 0, 0, false, ""),
        Property("Prop 4", 3000, 250, false, ""),
        Property("Prop 5", 3500, 300, false, ""),
        Property("Prop 6", 4000, 350, false, ""),
        Property("Bonus", 5000, 0, false, ""),
        Property("Prop 7", 4500, 400, false, ""),
        Property("Prop 8", 5000, 450, false, ""),
        Property("Prop 9", 5500, 500, false, ""),
        Property("Chance", 0, 0, false, ""),
        Property("Prop 10", 6000, 550, false, ""),
        Property("Prison", 0, 0, false, "")
    };

    vector<Player> players = {
        Player("Player 1", 5000, {}, 0),
        Player("Player 2", 5000, {}, 0)
    };

    int currentPlayerIndex = 0;

    displayBoard(properties, players);

    while (true) {
        Player& currentPlayer = players[currentPlayerIndex];

        cout << "Current player: " << currentPlayer.name << endl;
        cout << "Balance: " << currentPlayer.balance << endl;

        string input;
        cout << "Roll dice or buy property? (r/b): ";
        cin >> input;

        if (input == "r") {
            int roll = rand() % 6 + 1;
            cout << "You rolled a " << roll << endl;
            currentPlayer.currentPosition = (currentPlayer.currentPosition + roll) % properties.size();
            cout << "You moved to " << properties[currentPlayer.currentPosition].name << endl;

            Property& landedProperty = properties[currentPlayer.currentPosition];

            // Handle landing on Penalty or Bonus
            if (landedProperty.name == "Penalty") {
                currentPlayer.balance += landedProperty.price; // Subtracting penalty (price is negative)
                cout << "You landed on a Penalty! You lose $" << -landedProperty.price << endl;
            } else if (landedProperty.name == "Bonus") {
                currentPlayer.balance += landedProperty.price;
                cout << "You landed on a Bonus! You gain $" << landedProperty.price << endl;
            } else if (landedProperty.isOwned && landedProperty.owner != currentPlayer.name) {
                Player& owner = *find_if(players.begin(), players.end(), [&](const Player& p) { return p.name == landedProperty.owner; });
                cout << "Property is owned by " << owner.name << ". Paying rent of $" << landedProperty.rent << endl;
                currentPlayer.balance -= landedProperty.rent;
                owner.balance += landedProperty.rent;
            }
        } else if (input == "b") {
            Property& currentProperty = properties[currentPlayer.currentPosition];
            if (!currentProperty.isOwned && currentProperty.price > 0) {
                if (currentPlayer.balance >= currentProperty.price) {
                    currentPlayer.properties.push_back(currentProperty);
                    currentProperty.isOwned = true;
                    currentProperty.owner = currentPlayer.name;
                    currentPlayer.balance -= currentProperty.price;
                    cout << "You bought " << currentProperty.name << " for $" << currentProperty.price << endl;
                } else {
                    cout << "You don't have enough money to buy " << currentProperty.name << endl;
                }
            } else {
                cout << "You can't buy " << currentProperty.name << " right now" << endl;
            }
        } else {
            cout << "Invalid input. Please enter 'r' or 'b'." << endl;
        }

        displayBoard(properties, players);

        // Check if the game is over
        if (players.size() == 1) {
            cout << players[0].name << " wins the game!" << endl;
            break;
        }

        // Switch to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    return 0;
}
