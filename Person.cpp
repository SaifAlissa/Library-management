#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;             // уникальный ID (unique id)
    string name;        // имя (name)
    string password;    // пароль (password)

public:
    // Конструктор по умолчанию (default constructor)
    Person() {
        id = 0;
        name = "";
        password = "";
    }

    // Конструктор с параметрами (parameterized constructor)
    Person(int personId, string personName, string personPassword) {
        id = personId;
        name = personName;
        password = personPassword;
    }

    // Получить ID (get id)
    int getId() const {
        return id;
    }

    // Получить имя (get name)
    string getName() const {
        return name;
    }

    // Получить пароль (get password)
    string getPassword() const {
        return password;
    }

    // Проверка пароля (check password)
    bool checkPassword(string inputPassword) const {
        return password == inputPassword;
    }

    // Установить имя (set name)
    void setName(string newName) {
        name = newName;
    }

    // Установить пароль (set password)
    void setPassword(string newPassword) {
        password = newPassword;
    }

    // Вывод информации (display info)
    virtual void displayInfo() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};