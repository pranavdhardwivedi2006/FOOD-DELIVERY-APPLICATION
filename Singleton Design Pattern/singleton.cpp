#include<iostream>
#include<mutex>
using namespace std;

class Singleton {
private :
    static Singleton* instance;
    // static mutex mtx;

    Singleton() {
        cout << "Object is created\n";
    }
public :
    static Singleton* getInstance() {
        // if (instance == nullptr) {
        //     lock_guard<mutex> lock(mtx);
        //     if(instance == nullptr) {
        //         instance = new Singleton();
        //     }
        // }
        return instance;
    }
    // a static method belongs to the class not the object that is why we can call the without the object of the class
};

// initialize static members
// static variavle need to be declare outside the class
// Singleton* Singleton::instance = nullptr; 
// mutex Singleton::mtx;
Singleton* Singleton::instance = new Singleton();  // this is a good way for the multithread problem but in case when the object is not used in future this operation is very heavy so on that case we use the mutex way 

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl;
}