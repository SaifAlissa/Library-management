#pragma once

#include <iostream> // For input/output (для ввода/вывода)
#include <string>   // For string handling (для работы со строками)
using namespace std; // Avoid using std:: (чтобы не писать std::)

// BorrowRecord class represents a borrowing transaction (класс BorrowRecord представляет запись выдачи книги)
class BorrowRecord
{
private:
    int memberId; // Member ID who borrowed the book (ID читателя)
    int bookId;   // Book ID that was borrowed (ID книги)
    bool active;  // Indicates if the book is currently borrowed (показывает, активна ли запись)

public:
    // Default constructor initializes default values (конструктор по умолчанию)
    BorrowRecord(){
        memberId = 1001;
        bookId = 1001;
        active = false; // Not active by default (по умолчанию не активна)
    }

    // Parameterized constructor sets member and book IDs and activates record
    // (конструктор с параметрами устанавливает ID и активирует запись)
    BorrowRecord(int member, int book){
        memberId = member;
        bookId = book;
        active = true; // Record becomes active (запись становится активной)
    }

    // Destructor (деструктор)
    ~BorrowRecord(){}

    // Getters return values (геттеры возвращают значения)
    int getMemberId() const { return memberId; }
    int getBookId() const { return bookId; }
    bool isActive() const { return active; }

    // Deactivate borrow record (деактивирует запись выдачи)
    void deactivate() {
        active = false;
    }
};