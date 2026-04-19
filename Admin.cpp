
#ifndef ADMIN_CPP
#define ADMIN_CPP

#include "Person.cpp"

class Admin : public Person {
public:
    Admin() : Person() {}

    Admin(string name, string password)
        : Person(name, password) {}

    void displayInfo() const override {
        cout << "Admin Information" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

#endif
>>>>>>> eca626f (work before switching to library)
