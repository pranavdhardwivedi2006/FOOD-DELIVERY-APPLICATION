#include<iostream>
using namespace std;

class EquilateralTriangle {
    float side, circumference, area;
public:
    void setSide(float a) {
        side = a;
        circumference = 3 * a;
        area = (1.73 * a * a) / 4;
    }

    // friend void PrintResults(EquilateralTriangle&);
    friend class HomeWork;
};

class HomeWork {
public:
    void PrintResults(EquilateralTriangle& eq) {
        cout << "Circumference " << eq.circumference << endl;
        cout << "Area " << eq.area << endl;
    }
};


int main() {
    EquilateralTriangle eq;
    eq.setSide(3);
    HomeWork hw;
    hw.PrintResults(eq);
}