#include <iostream> // For the input or the output
#include <string> // Used to handle the strings
using namespace std; // to avoid using std::

class Book
{
private:
    int static nextId; // Static member to generate unique IDs for all Book instances
    int id; // To store unique id for the books.
    string title; // To store titles for the books.
    string author; // To store the authors' of the books.
    int totalCopies; // To store the Total Copies of the books.
    int availableCopies; // To store the Available Copies of the books.
public:
    // Default constructor that initializes an empty book record and assigns a unique ID.
    Book(){
        id=nextId++;
        title="Unknown";
        author="Unknown";
        totalCopies=0;
        availableCopies=0;

    }
    // Parameterized constructor to add a new specific book to the library.
    Book(string bookTitle, string bookAuthor, int copies){
        id=nextId++;
        title= bookTitle;
        author= bookAuthor;
        totalCopies= copies;
        availableCopies= copies;
    }

    // Getters for variables and set as 'const' to guarantee they do not modify object state.
    int getId() const { return id;}
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getTotalCopies() const { return totalCopies; }
    int getAvailableCopies() const { return availableCopies; }

    // Returns true if a copy was successfully borrowed, and false if it is out of stock.
    bool borrowCopy(){
        if(availableCopies>0){
            availableCopies--; // To decrease available inventory
            return true;
        }
        return false;
    }

    // Returns true if successfully returned, and false if the library has all its copies.
    bool returnCopy(){
        if(availableCopies<totalCopies){
            availableCopies++; // To increase available inventory
            return true;
        }
        return false;
    }

    // Displays the formatted book details to the console
    void displayInfo() const{ cout<<"ID: "<<id<<", Title: "<<title
        <<", Author: "<<author<<", Available: "
        <<availableCopies<<"/"<<totalCopies<<endl;}
};

// Initialize the static ID counter to start at 1000
int Book::nextId=1000;