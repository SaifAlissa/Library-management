#ifndef MEMBER_CPP
#define MEMBER_CPP

#include "Person.cpp"

class Member : public Person {
public:
    Member() : Person() {
    }

    Member(string memberName, string memberPassword)
        : Person(memberName, memberPassword) {
    }

    void displayInfo() const override {
        cout << "Member Information" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

#endif