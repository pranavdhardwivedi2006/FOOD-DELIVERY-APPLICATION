#include<iostream>
using namespace std;

class smartPhone {
public:
    virtual void takeASelfie() = 0;
};

class android : public smartPhone {
public:
    void takeASelfie() override {
        cout << "Selfie by android\n";
    }
};

class iPhone : public smartPhone {
public:
    void takeASelfie() override {
        cout << "Selfie by iPhone\n";
    }
};

int main() {
    android* a = new android();
    smartPhone* s1 = a;
    s1->takeASelfie();
}