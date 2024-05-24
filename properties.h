#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>

struct Property {
    std::string name;
    int price;
    int rent;
    bool isOwned;
    std::string owner;

    Property(const std::string& n, int p, int r, bool owned, const std::string& o) 
        : name(n), price(p), rent(r), isOwned(owned), owner(o) {}
};

#endif
