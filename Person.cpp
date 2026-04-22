#pragma once

#include <iostream> // For input/output (для ввода/вывода)
#include <string>   // For string handling (для работы со строками)
using namespace std; // Avoid using std:: (чтобы не писать std::)

class Person {
protected:
    int id;             // unique ID (уникальный ID)
    string name;        // name (имя)
    string password;    // password (пароль)

public:
    // Default constructor (конструктор по умолчанию)
    Person() {
        id = 0;        // initial ID value (начальное значение ID)
        name = "";     // empty name (пустое имя)
        password = ""; // empty password (пустой пароль)
    }

    // Parameterized constructor (конструктор с параметрами)
    Person(int personId, string personName, string personPassword) {
        id = personId;        // set ID (установить ID)
        name = personName;    // set name (установить имя)
        password = personPassword; // set password (установить пароль)
    }

    // Get ID (получить ID)
    int getId() const {
        return id; // return ID (вернуть ID)
    }

    // Get name (получить имя)
    string getName() const {
        return name; // return name (вернуть имя)
    }

    // Get password (получить пароль)
    string getPassword() const {
        return password; // return password (вернуть пароль)
    }

    // Check password (проверка пароля)
    bool checkPassword(string inputPassword) const {
        return password == inputPassword; // compare passwords (сравнить пароли)
    }

    // Set name (установить имя)
    void setName(string newName) {
        name = newName; // update name (обновить имя)
    }

    // Set password (установить пароль)
    void setPassword(string newPassword) {
        password = newPassword; // update password (обновить пароль)
    }

    // Display info (вывод информации)
    virtual void displayInfo() const {
        cout << "ID: " << id << endl;     // print ID (вывод ID)
        cout << "Name: " << name << endl; // print name (вывод имени)
    }
};