#ifndef BOOK_CPP
#define BOOK_CPP

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    static int nextId;
    int id;
    string title;
    string author;
    int totalCopies;
    int availableCopies;

public:
    Book() {
        id = 0;
        title = "";
        author = "";
        totalCopies = 0;
        availableCopies = 0;
    }

    Book(string bookTitle, string bookAuthor, int copies) {
        id = nextId++;
        title = bookTitle;
        author = bookAuthor;
        totalCopies = copies;
        availableCopies = copies;
    }

    int getId() const {
        return id;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getTotalCopies() const {
        return totalCopies;
    }

    int getAvailableCopies() const {
        return availableCopies;
    }

    bool borrowCopy() {
        if (availableCopies > 0) {
            availableCopies--;
            return true;
        }
        return false;
    }

    bool returnCopy() {
        if (availableCopies < totalCopies) {
            availableCopies++;
            return true;
        }
        return false;
    }

    void displayInfo() const {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Total Copies: " << totalCopies << endl;
        cout << "Available Copies: " << availableCopies << endl;
    }
};

int Book::nextId = 1;

#endif