#ifndef LIBRARIAN_CPP
#define LIBRARIAN_CPP
#include "Person.cpp" // Librarian inherits common (id, name, password) from Person

class Librarian : public Person {
private:
    static int nextId; // Shared counter to generate unique librarian IDs

public:
    Librarian() : Person() {
    }

    Librarian(string librarianName, string librarianPassword)
        : Person(nextId, librarianName, librarianPassword) { // Sends ID, name and password to Person constructor
        nextId++; // Prepare next unique ID for the next librarian
    }

    static void setNextId(int value) {
        nextId = value;
    }

    static int getNextId() {
        return nextId;
    }

    void displayInfo() const {
        cout << "===== Librarian Information =====" << endl;
        Person::displayInfo(); // Reuse Person display for ID and name
    }
};

int Librarian::nextId = 20; // Librarian IDs starts from 20

#endif
