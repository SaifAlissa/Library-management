#pragma once

#include <iostream> // For input/output (для ввода/вывода)
#include <string>   // For string handling (для работы со строками)
using namespace std; // Avoid using std:: (чтобы не писать std::)

// Book class represents a library book (класс Book представляет книгу в библиотеке)
class Book
{
private:
    static int nextId; // Static counter for unique IDs (статический счётчик для уникальных ID)
    int id; // Unique book ID (уникальный ID книги)
    string title; // Book title (название книги)
    string author; // Book author (автор книги)
    int totalCopies; // Total number of copies (общее количество копий)
    int availableCopies; // Available copies (доступные копии)

public:
    // Default constructor creates empty book (конструктор по умолчанию создаёт пустую книгу)
    Book(){
        id = nextId++; // Assign unique ID (присваиваем уникальный ID)
        title = "Unknown";
        author = "Unknown";
        totalCopies = 0;
        availableCopies = 0;
    }

    // Parameterized constructor creates a specific book (конструктор с параметрами создаёт книгу)
    Book(string bookTitle, string bookAuthor, int copies){
        id = nextId++; // Assign unique ID (присваиваем уникальный ID)
        title = bookTitle;
        author = bookAuthor;
        totalCopies = copies;
        availableCopies = copies; // All copies are available initially (все копии сначала доступны)
    }

    // Getters return values without modifying object (геттеры возвращают значения)
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getTotalCopies() const { return totalCopies; }
    int getAvailableCopies() const { return availableCopies; }

    // Borrow a copy if available (взять книгу если есть доступные копии)
    bool borrowCopy(){
        if(availableCopies > 0){
            availableCopies--; // Decrease available copies (уменьшаем количество)
            return true;
        }
        return false; // No copies left (нет доступных копий)
    }

    // Return a copy if not full (вернуть книгу если есть место)
    bool returnCopy(){
        if(availableCopies < totalCopies){
            availableCopies++; // Increase available copies (увеличиваем количество)
            return true;
        }
        return false; // All copies already returned (все копии уже в библиотеке)
    }

    // Display book information (вывод информации о книге)
    void displayInfo() const{
        cout << "ID: " << id
             << ", Title: " << title
             << ", Author: " << author
             << ", Available: "
             << availableCopies << "/" << totalCopies << endl;
    }
};

// Initialize static ID counter (инициализация статического счётчика)
int Book::nextId = 1000;