#ifndef MENUITEM_H
#define MENUITEM_H

#include<string>
#include<iostream>
using namespace std;

class MenuItem {

private:
    int code;
    string name;
    double price;
    string imgPath;

public:
    MenuItem(int code, string name, double price, string imgPath) {
        this -> code = code;
        this -> name = name;
        this -> price = price;
        this -> imgPath = imgPath;
    }

    ~MenuItem() {
        cout << "Item deleted successfully\n";
    }

    bool operator==(const MenuItem& item) const {
        return this -> code == item.code;
    }

    void setName(const string& name) {
        this -> name = name;
        cout << "Item name set successfully.\n";
    }

    string getName() const {
        return this -> name;
    }

    void setPrice(const double newPrice) {
        this -> price = newPrice;
    }

    double getPrice() const {
        return this -> price;
    }

    void setImage(string path) {
        this -> imgPath = path;
        cout << "Image path set successfully.\n";
    }

    string getImage() const {
        return this -> imgPath;
    }
};

#endif