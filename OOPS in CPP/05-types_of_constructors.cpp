#include<iostream>
using namespace std;

class User {
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;

    User(){} // default
    // we loose cpp's default constructor at that second when we make our own constructor
};

ostream& operator<<(ostream& out, User& u) {
    out << "First Name :" << u.FirstName << endl;
    out << "Last Name :" << u.LastName << endl;
    out << "Age :" << u.Age << endl;
    out << "Email :" << u.Email << endl;
}

int main() {

}