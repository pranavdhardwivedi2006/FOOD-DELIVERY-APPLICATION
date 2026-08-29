#include <iostream>
using namespace std;

class Instrument {
public:
    /* virtual void MakeSound() {
        cout << "Instrument is playing ...\n";
    }  // this is a virtual function means when we call it using base class pointer then it find the latest version of the function and execute that now we will study what is pure virtual function
    */

    virtual void MakeSound() = 0; // this means there are no definition here but in each class which inherit this class would need to give the definition of this function and this will give the definition of abstract class in cpp. An abstract class in cpp must have atleast one pure virtual function.

};

class Piano : public Instrument {
public:
    void MakeSound() {
        cout << "Piano is playing ...\n";
    }
};

class Tabla : public Instrument {
public:
    void MakeSound() {
        cout << "Tabla is playing ...\n";
    }
};


int main() {
    Instrument* p = new Piano();
    Instrument* t = new Tabla();
    p -> MakeSound();
    t -> MakeSound();
    Instrument* instruments[2] = {p, t};
    instruments[0] -> MakeSound();
    instruments[1] -> MakeSound();
}
