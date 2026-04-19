#ifndef LIBRARIAN_CPP
#define LIBRARIAN_CPP

#include "Person.cpp"

class Librarian : public Person {
public:
    Librarian() : Person() {}

    Librarian(string name, string password)
        : Person(name, password) {}

    void displayInfo() const override {
        cout << "Librarian Information" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

#endif