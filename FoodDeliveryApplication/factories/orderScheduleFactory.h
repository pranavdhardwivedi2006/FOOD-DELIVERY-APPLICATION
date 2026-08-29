#ifndef ORDERSCHEDULEFACTORY_H
#define ORDERSCHEDULEFACTORY_H

#include "orderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utilities/timeUtils.h"
using namespace std;

class OrderScheduleFactory : public OrderFactory {
private :
    string scheduleTime;
public :
    OrderScheduleFactory(string scheduleTime) {
        this -> scheduleTime = scheduleTime;
    }

    Order* createOrder(User* user, Restaurant* restaurant, Cart*, const vector<MenuItem>& items, PaymentStrategy* paymentStrategy, const string& orderType) override {

        Order* order = nullptr;

        if (orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder -> setUserAddress(user->getAddress());
            order = deliveryOrder;
        } else {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        }

        order -> setUser(user);
        order -> setRestaurant(restaurant);
        order -> setItems(items);
        order -> setPaymentStrategy(paymentStrategy);
        order -> setScheduled(TimeUtils::getCurrentTime());

        return order;
    }
};

#endif