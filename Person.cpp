#ifndef PERSON_CPP
#define PERSON_CPP

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    static int nextId;
    int id;
    string name;
    string password;

public:
    Person() {
        id = nextId++;
        name = "";
        password = "";
    }

    Person(string personName, string personPassword) {
        id = nextId++;
        name = personName;
        password = personPassword;
    }

    virtual ~Person() {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getPassword() const {
        return password;
    }

    bool checkPassword(string inputPassword) const {
        return password == inputPassword;
    }

    virtual void displayInfo() const = 0;
};

int Person::nextId = 1;

#endif