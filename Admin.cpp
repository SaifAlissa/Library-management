#ifndef ADMIN_CPP
#define ADMIN_CPP

#include <iostream>
#include <string>
using namespace std;

// Admin inherits from Person
class Admin : public Person {
private:
    // Static variable for generating Admin IDs
    static int nextId;

public:
    // Default constructor
    Admin() : Person() {
        // Override the ID assigned by Person and use Admin's own nextId
        id = nextId++;
    }

    // Constructor with name and password
    Admin(string adminName, string adminPassword) : Person(adminName, adminPassword) {
        // Override the ID assigned by Person and use Admin's own nextId
        id = nextId++;
    }

    // Destructor
    ~Admin() {}

    // Set the next available Admin ID manually
    static void setNextId(int value) {
        if (value > 0) {
            nextId = value;
        }
    }

    // Get the next available Admin ID
    static int getNextId() {
        return nextId;
    }

    // Display admin information
    void displayInfo() const override {
        cout << "===== Admin Information =====" << endl;
        cout << "Admin ID: " << id << endl;
        cout << "Admin Name: " << name << endl;
        cout << "Admin Password: " << password << endl;
    }
};

// Initial value of static member
int Admin::nextId = 1;

#endif