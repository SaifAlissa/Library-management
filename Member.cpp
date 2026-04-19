#ifndef MEMBER_CPP
#define MEMBER_CPP

#include "Person.cpp"

class Member : public Person {
public:
    Member() : Person() {}

    Member(string name, string password)
        : Person(name, password) {}

    void displayInfo() const override {
        cout << "Member Information" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

#endif