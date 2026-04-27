

#include "Person.cpp" // Include base class Person (подключаем базовый класс Person)

// Member class inherits from Person (класс Member наследуется от Person)
class Member : public Person {
private:
    static int nextId; // Static counter for unique IDs (статический счётчик для уникальных ID)

public:
    // Default constructor (конструктор по умолчанию)
    Member() : Person() {
        // No custom initialization (без дополнительной инициализации)
    }

    // Parameterized constructor sets name and password and assigns unique ID
    // (конструктор с параметрами задаёт имя, пароль и уникальный ID)
    Member(string memberName, string memberPassword)
        : Person(nextId, memberName, memberPassword) {
        nextId++; // Increment ID for next member (увеличиваем ID для следующего пользователя)
    }

    // Set next available ID manually (установить следующий ID вручную)
    static void setNextId(int value) {
        nextId = value; // Assign new value (присваиваем новое значение)
    }

    // Get next available ID (получить следующий доступный ID)
    static int getNextId() {
        return nextId;
    }

    // Display member information (вывод информации о пользователе)
    void displayInfo() const {
        cout << "===== Member Information =====" << endl; // Header text (заголовок)
        Person::displayInfo(); // Call base class method (вызов метода базового класса)
    }
};

// Initialize static ID counter starting from 60 (инициализация счётчика ID с 60)
int Member::nextId = 60;