#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "../models/orders.h"
#include<vector>
#include<mutex>
using namespace std;

class OrderManager {
private :
    static OrderManager* manager;
    static mutex mtx;
    vector<Order*> orders;

    OrderManager() {}
public :
    static OrderManager* getInstance() {
        if(!manager) {
            lock_guard<mutex> lock(mtx);
            if(!manager) {
                manager = new OrderManager();
            }
        }
        return manager;
    }

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void listOrders() {
        cout << "\n-----------All Orders-----------\n";
        for(auto order : orders) {
            cout << order -> getType() << " order for " << order -> getUser() -> getName()
                << " | Total: ₹" << order -> getTotal()
                << " | At: " << order -> getScheduled() << endl;
        }
    }
};

#endif