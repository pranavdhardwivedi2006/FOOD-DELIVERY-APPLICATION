#ifndef PICKUPORDER_H
#define PICKUPORDER_H

#include<string>
#include "orders.h"
using namespace std;

class PickupOrder : public Order {
private:
    string restaurantAddress;
public :
    PickupOrder() {
        this -> restaurantAddress = "";
    }

    string getType() const override {
        return "Pickup";
    }

    void setRestaurantAddress(const string& s) {
        this -> restaurantAddress = s;
    }

    string getRestaurantAddress() const {
        return this -> restaurantAddress;
    }
};

#endif