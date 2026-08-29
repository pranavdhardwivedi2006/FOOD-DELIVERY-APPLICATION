#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include "../models/user.h"
#include "../models/restaurant.h"
#include "../models/cart.h"
#include "../models/orders.h"
#include "../strategies/paymentStrategies.h"
#include<vector>
#include<string>
using namespace std;

class OrderFactory {
public:
    virtual Order* createOrder(User*, Restaurant*, Cart*, const vector<MenuItem>&, PaymentStrategy*, const string&) = 0;

    virtual ~OrderFactory() {}
};

#endif