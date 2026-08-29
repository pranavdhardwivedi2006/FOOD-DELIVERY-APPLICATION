#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

class PaymentStrategy {
public :
    virtual void pay(double) = 0;
    virtual ~PaymentStrategy() {};
};

#endif