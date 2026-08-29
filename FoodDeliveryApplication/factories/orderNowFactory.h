#ifndef ORDERNOWFACTORY_H
#define ORDERNOWFACTORY_H

#include "orderFactory.h"
#include "../models/pickupOrder.h"
#include "../models/deliveryOrder.h"
#include "../utilities/timeUtils.h"

class orderNowFactory : public OrderFactory {
public:
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