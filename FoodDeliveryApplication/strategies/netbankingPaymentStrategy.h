#ifndef NETBANKINGPAYMENTSTRATEGY_H
#define NETBANKINGPAYMENTSTRATEGY_H

#include <iostream>
#include "paymentStrategies.h"
using namespace std;

class NetBankingPaymentStrategy : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << amount << " $ Payed through Net Banking.\n";
    }
};

#endif