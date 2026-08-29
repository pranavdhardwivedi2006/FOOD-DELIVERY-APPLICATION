#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include<string>
#include "orders.h"
using namespace std;

class DeliveryOrder : public Order {
private:
    string userAddress;
public :
    DeliveryOrder() {
        this -> userAddress = "";
    }

    string getType() const override {
        return "Delivery";
    }

    void setUserAddress(const string& s) {
        this -> userAddress = s;
    }

    string getUserAddress() const {
        return this -> userAddress;
    }
};

#endif