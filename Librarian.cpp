#ifndef LIBRARIAN_CPP
#define LIBRARIAN_CPP

#include "Person.cpp"

class Librarian : public Person {
private:
    static int nextId;

public:
    Librarian() : Person() {
    }

    Librarian(string librarianName, string librarianPassword)
        : Person(nextId, librarianName, librarianPassword) {
        nextId++;
    }

    static void setNextId(int value) {
        nextId = value;
    }

    static int getNextId() {
        return nextId;
    }

    void displayInfo() const {
        cout << "Librarian Information" << endl;
        Person::displayInfo();
    }
};

int Librarian::nextId = 20;

#endif