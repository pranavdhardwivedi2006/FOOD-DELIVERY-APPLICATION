#ifndef ORDERS_H
#define ORDERS_H

#include<string>
#include "user.h"
#include "restaurant.h"
#include "menuItem.h"
#include "../strategies/paymentStrategies.h"
using namespace std;

class Order {
protected :
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem> items;
    PaymentStrategy* ps;
    double total;
    string scheduled;

public :
    Order() {
        this -> user = nullptr;
        this -> restaurant = nullptr;
        this -> ps = nullptr;
        total = 0;
        orderId = nextOrderId++;
    }

    virtual ~Order() {
        delete ps;
        cout << "Order deleted successfully.\n";
    }

    bool processPayment() {
        if(ps) {
            ps->pay(total);
            return true;
        } else {
            cout << "Choose a payment mode first.\n";
            return false;
        }
    }

    virtual string getType() const = 0;

    int getOrderId() const {
        return this -> orderId;
    }

    void setUser(User* user) {
        this -> user = user;
    }

    User* getUser() const {
        return this -> user;
    }

    void setRestaurant(Restaurant* rs) {
        this -> restaurant = rs;
    }

    Restaurant* getRestaurant() const {
        return this -> restaurant;
    }

    void setPaymentStrategy(PaymentStrategy* ps) {
        this -> ps = ps;
    }

    PaymentStrategy* getPaymentStrategy() const {
        return this -> ps;
    }

    void setItems(const vector<MenuItem>& items) {
        this -> items = items;
        total = 0;
        for(auto& it : items) total += it.getPrice();
    }

    const vector<MenuItem>& getItems() const {
        return this -> items;
    }

    void setScheduled(const string& s) {
        this -> scheduled = s;
    }

    string getScheduled() const {
        return this -> scheduled;
    }

    double getTotal() const {
        return this -> total;
    }
};

int Order::nextOrderId = 0;

#endif