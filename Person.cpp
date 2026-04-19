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

    Person(string name, string password) {
        id = nextId++;
        this->name = name;
        this->password = password;
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

    bool checkPassword(string password) const {
        return this->password == password;
    }

    virtual void displayInfo() const = 0;
};

int Person::nextId = 1;

#endif