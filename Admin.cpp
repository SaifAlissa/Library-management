#pragma once

#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

// Класс Admin наследуется от Person
// Admin class inherits from Person
class Admin : public Person {
private:
    static int nextId; // следующий доступный ID (next available ID)

public:
    // Конструктор по умолчанию
    // Default constructor
    Admin() : Person(nextId, "", "") {
        nextId++; // увеличиваем ID (increment ID)
    }

    // Конструктор с параметрами (имя и пароль)
    // Constructor with parameters (name and password)
    Admin(string adminName, string adminPassword)
        : Person(nextId, adminName, adminPassword) {
        nextId++; // увеличиваем ID (increment ID)
    }

    // Получить следующий ID
    // Get next available ID
    static int getNextId() {
        return nextId;
    }

    // Установить следующий ID
    // Set next available ID
    static void setNextId(int value) {
        if (value > 0) nextId = value;
    }

    // Вывод информации об администраторе
    // Display admin information
    void displayInfo() const {
        cout << "===== Admin Information =====" << endl;
        cout << "Admin ID: " << id << endl;
        cout << "Admin Name: " << name << endl;
    }
};

// Инициализация статической переменной
// Initialization of static variable
int Admin::nextId = 1;