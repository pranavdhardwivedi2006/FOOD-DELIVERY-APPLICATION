#include<iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    float *Rates;
    int RatesCounter;
    Book(string title, string author) {
        this -> title = title;
        this -> author = author;

        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 4; Rates[1] = 5;
    }

    Book(const Book& original) {
        this -> title = original.title;
        this -> author = original.author;
        this -> RatesCounter = original.RatesCounter;
        
        this -> Rates = new float[this -> RatesCounter];
        for(int i = 0; i < this -> RatesCounter; i++) {
            this -> Rates[i] = original.Rates[i];
        }
    }

    ~Book() {
        delete [] Rates;
        Rates = nullptr;
        cout << title + " Destructor invoked.\n";
    }

};

int main() {
    Book b1("Godan", "Munshi Prechand");
    Book b2("Ram Charit Manas", "Tulsi Das");
    Book b3(b1); // copy constructor invoked
    Book b4 = b2; // copy constructor invoked
}