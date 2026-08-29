#ifndef USER_H
#define USER_H

#include<string>
#include<iostream>
#include "cart.h"
using namespace std;

class User {
private:
    static int nextId;
    int UserId;
    string name;
    string address;
    Cart* cart;
public :
    User(string name, string address) {
        this -> UserId = nextId++;
        this -> name = name;
        this -> address = address;
        this -> cart = new Cart();
    }

    ~User() {
        delete this -> cart;
        cout << "User deleted successfully.\n";
    }

    string setName(const string& newName) {
        name = newName;
        cout << "Name set successfully.\n";
    }

    string getName() const {
        return this -> name;
    }

    void setAddress(const string& address) {
        this -> address = address;
        cout << "Address set successfully.\n";
    }

    string getAddress() const {
        return this -> address;
    }

    Cart* getCart() const {
        return this -> cart;
    }
};

int User::nextId = 0;
#endif