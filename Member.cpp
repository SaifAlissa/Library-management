

#include "Person.cpp"

class Member : public Person {
private:
    static int nextId;

public:
    Member() : Person() {
    }

    Member(string memberName, string memberPassword)
        : Person(nextId, memberName, memberPassword) {
        nextId++;
    }

    static void setNextId(int value) {
        nextId = value;
    }

    static int getNextId() {
        return nextId;
    }

    void displayInfo() const {
        cout << "Member Information" << endl;
        Person::displayInfo();
    }
};

int Member::nextId = 60;

