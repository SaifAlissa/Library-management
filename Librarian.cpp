#pragma once

#include "Person.cpp" // Include base class Person (подключаем базовый класс Person)

// Librarian class inherits from Person (класс Librarian наследуется от Person)
class Librarian : public Person {
private:
    static int nextId; // Static counter for unique IDs (статический счётчик для уникальных ID)

public:
    // Default constructor (конструктор по умолчанию)
    Librarian() : Person() {
    }

    // Parameterized constructor sets name and password and assigns unique ID
    // (конструктор с параметрами устанавливает имя, пароль и уникальный ID)
    Librarian(string librarianName, string librarianPassword)
        : Person(nextId, librarianName, librarianPassword) {
        nextId++; // Increment ID for next librarian (увеличиваем ID для следующего библиотекаря)
    }

    // Set next available ID manually (установить следующий ID вручную)
    static void setNextId(int value) {
        nextId = value;
    }

    // Get next available ID (получить следующий доступный ID)
    static int getNextId() {
        return nextId;
    }

    // Display librarian information (вывод информации о библиотекаре)
    void displayInfo() const {
        cout << "Librarian Information" << endl;
        Person::displayInfo(); // Call base class method (вызов метода базового класса)
    }
};

// Initialize static ID counter starting from 20 (инициализация счётчика ID с 20)
int Librarian::nextId = 20;