#include "Person.cpp" // Include base class Person 

// Member class inherits from Person 
class Member : public Person {
private:
    static int nextId; // Static counter for unique IDs 

public:
    // Default constructor 
    Member() : Person() {
        // No custom initialization
    }

    // Parameterized constructor sets name and password and assigns unique ID
    
    Member(string memberName, string memberPassword)
        : Person(nextId, memberName, memberPassword) {
        nextId++; // Increment ID for next member
    }

    // Set next available ID manually 
    static void setNextId(int value) {
        nextId = value; // Assign new value 
    }

    // Get next available ID 
    static int getNextId() {
        return nextId;
    }

    // Display member information 
    void displayInfo() const {
        cout << "===== Member Information =====" << endl; 
        Person::displayInfo(); // Call base class method 
    }
};

// Initialize static ID counter starting from 60 
int Member::nextId = 60;