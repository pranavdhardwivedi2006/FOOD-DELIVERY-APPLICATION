#ifndef CART_H
#define CART_H

#include<string>
#include "restaurant.h"
#include "menuItem.h"
using namespace std;

class Cart {
private:
    Restaurant* restaurant;
    vector<MenuItem> items;
public:
    Cart() {
        this -> restaurant = nullptr;
    }

    ~Cart() {
        cout << "Cart deleted successfully.\n";
    }

    void addItem(const MenuItem& item) {
        if(this -> restaurant == nullptr) {
            cout << "Set the restaurant first.\n";
            return ;
        }
        this -> items.push_back(item);
        cout << "Item added successfully.\n";
    }

    void deleteItem(const MenuItem& item) {
        erase(this -> items, item);
        cout << "Successfully deleted the item from cart.\n";
    }

    bool isEmpty() const {
        return !restaurant || !items.size();
    }

    void clear() {
        this -> items.clear();
        this -> restaurant = nullptr;
        cout << "Cart cleared successfully.\n";
    }

    double getToatal() const {
        double total = 0;
        for(const auto& item : this -> items) {
            total += item.getPrice();
        }
        return total;
    }

    void setRestaurant(Restaurant* rs) {
        this -> restaurant = rs;
        cout << "Restaurant name set successfully.\n";
    }

    Restaurant* getRestaurant() const {
        return this -> restaurant;
    }

    const vector<MenuItem>& getItems() const {
        return this -> items;
    }
};

#endif