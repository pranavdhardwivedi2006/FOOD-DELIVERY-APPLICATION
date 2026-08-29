#include<iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    char gender;
    virtual void Study() = 0;
    virtual void Study(string) = 0;
};

class programmingStudent : public Student {
    void Study() override {
        cout << "Studying programming" << endl;
    }
    void Study(string s) override {
        cout << "Studying programming " + s << endl;
    }
};
class artsStudent : public Student {
    void Study() override {
        cout << "Studying arts" << endl;
    }    
    void Study(string s) override {
        cout << "Studying arts " + s << endl;
    }    
};
class musicStudent : public Student {
    void Study() override {
        cout << "Studying music" << endl;
    }
    void Study(string s) override {
        cout << "Studying music " + s << endl;
    }
};

int main() {
    Student* students[3];
    students[0] = new programmingStudent();
    students[1] = new artsStudent();
    students[2] = new musicStudent();
    string s = "Syllabus";
    for(int i = 0; i < 3; i++) {
        students[i] -> Study();
        students[i] -> Study(s);
    }
    for(int i = 0; i < 3; i++) {
        delete students[i];
    }
}