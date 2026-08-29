#ifndef UPIPAYMENTSTRATEGY_H
#define UPIPAYMENTSTRATEGY_H

#include <iostream>
#include "paymentStrategies.h"
using namespace std;

class UPIPaymentStrategy : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << amount << " $ Payed through UPI.\n";
    }
};

#endif