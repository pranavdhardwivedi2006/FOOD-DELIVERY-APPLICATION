#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include<vector>
#include<mutex>
#include<algorithm>
#include "../models/restaurant.h"
using namespace std;

class RestaurantManager {
private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* manager;
    static mutex mtx;

    RestaurantManager() {}
public :
    static RestaurantManager* getInstance() {
        if(!manager) {
            lock_guard<mutex> lock(mtx);
            if(!manager) {
                manager = new RestaurantManager();
            }
        }
        return manager;
    }

    void addRestaurant(Restaurant* rs) {
        this -> restaurants.push_back(rs);
    }

    const vector<Restaurant*>& getRestaurants() const {
        return this -> restaurants;
    }

    vector<Restaurant*> searchByLocation(string loc) {
        vector<Restaurant*> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for (auto r : restaurants) {
            string rl = r -> getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if (rl == loc) {
                result.push_back(r);
            }
        }
        return result;
    }
};

#endif