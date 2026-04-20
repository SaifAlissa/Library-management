#ifndef ADMIN_CPP
#define ADMIN_CPP

#include "Person.cpp"

class Admin : public Person {
private:
    static int nextId;

public:
    Admin() : Person() {
    }

    Admin(string adminName, string adminPassword)
        : Person(nextId, adminName, adminPassword) {
        nextId++;
    }

    static void setNextId(int value) {
        nextId = value;
    }

    static int getNextId() {
        return nextId;
    }

    void displayInfo() const {
        cout << "Admin Information" << endl;
        Person::displayInfo();
    }
};

int Admin::nextId = 1;

#endif