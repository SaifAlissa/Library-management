#pragma once

#include <iostream> // For input/output 
#include <string>   // For string handling 
using namespace std; // Avoid using std:: 

class Person {
protected:
    int id;             // unique ID 
    string name;        // name 
    string password;    // password 

public:
    // Default constructor 
    Person() {
        id = 0;        // initial ID value 
        name = "";     // empty name 
        password = ""; // empty password 
    }

    // Parameterized constructor 
    Person(int personId, string personName, string personPassword) {
        id = personId;        // set ID 
        name = personName;    // set name 
        password = personPassword; // set password 
    }

    // Get ID 
    int getId() const {
        return id; // return ID 
    }

    // Get name 
    string getName() const {
        return name; // return name 
    }

    // Get password 
    string getPassword() const {
        return password; // return password 
    }

    // Check password 
    bool checkPassword(string inputPassword) const {
        return password == inputPassword; // compare passwords 
    }

    // Set name 
    void setName(string newName) {
        name = newName; // update name 
    }

    // Set password 
    void setPassword(string newPassword) {
        password = newPassword; // update password 
    }

    // Display info 
    virtual void displayInfo() const {
        cout << "ID: " << id << endl;     // print ID 
        cout << "Name: " << name << endl; // print name 
    }
};