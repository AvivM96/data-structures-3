#include <utility>

#ifndef DATA_STRUCTURES_3_BIDDER_H
#define DATA_STRUCTURES_3_BIDDER_H

#include <string>

using namespace std;

class Bidder {
    int bid;
    string name;


public:
    explicit Bidder(int bid, string name): bid(bid), name(std::move(name)) {}

    int getBid() {
        return this->bid;
    }

    string getName() {
        return this->name;
    }
};


#endif //DATA_STRUCTURES_3_BIDDER_H
