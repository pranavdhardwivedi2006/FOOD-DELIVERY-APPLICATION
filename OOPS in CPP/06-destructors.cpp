#include<iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    int *Rates;
    int RatesCounter;
    Book(string title, string author) {
        this -> title = title;
        this -> author = author;

        RatesCounter = 2;
        Rates = new int[RatesCounter];
        Rates[0] = 4; Rates[1] = 5;
    }

    // destructors are invoked in reverse order. For ex. you first made user1 then user2 so the destructor of user2 is invoked first then of user1
    // unless you used pointers, you don't need to create destructors
    // but when you use pointers you need to free thode pointers manually
    ~Book() {
        delete [] Rates;
        Rates = nullptr;
        cout << title + " Destructor invoked.\n";
    }

};

int main() {
    Book b1("Godan", "Munshi Prechand");
    Book b2 = b1; 
    // this will give undefined behavior bcz the destructor tries to free the array while there is no copy constructor due to which both the books points to same array
}