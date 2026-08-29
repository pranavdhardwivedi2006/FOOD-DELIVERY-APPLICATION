#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<string>
#include<vector>
#include<iostream>
#include "menuItem.h"
using namespace std;

class Restaurant {
private:
    static int nextRestaurantId;
    int RestaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

public :
    Restaurant(string name, string location) {
        this -> RestaurantId = nextRestaurantId++;
        this -> name = name;
        this -> location = location;
    }

    ~Restaurant() {
        cout << "Restaurant deleted successfully\n";
    }

    int getRestaurantId() const {
        return this -> RestaurantId;
    }

    void setRestaurantName(const string& s) {
        this -> name = s;
        cout << "Restaurant name successfully set.\n";
    }
    
    string getRestaurantName() const {
        return this -> name;
    }
    
    void setLocation(const string& s) {
        this -> location = s;
        cout << "Restaurant location successfully set.\n";
    }

    string getLocation() const {
        return this -> location;
    }

    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
        cout << "Item added successfully\n";
    }

    const vector<MenuItem>& getMenu() const {
        return this -> menu;
    }

    void deleteItem(const MenuItem& item) {
        erase(this -> menu, item);
        cout << "Item deleted successfully\n";
    }
};

int Restaurant::nextRestaurantId = 0;

#endif