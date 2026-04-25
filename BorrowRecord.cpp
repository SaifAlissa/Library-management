#ifndef BORROWRECORD_CPP
#define BORROWRECORD_CPP
#include <iostream> // For the input or the output
#include <string> // Used to handle the strings
using namespace std; // to avoid using std::

class BorrowRecord
{
private:
    int memberId; // to keep the members' particular ID.
    int bookId; // to keep the books' particular ID.
    bool active; // to keep the book's activity statue.
public:
    // Default constructor to intialize the values as the starting point.
    BorrowRecord(){
        memberId=1001;
        bookId=1001;
        active=false;
    }

    // Parameterized constructor to intialize member's ID and book's ID, and setting the specific book activity statue to active.
    BorrowRecord(int member, int book){
        memberId=member;
        bookId=book;
        active=true;
    }
    // Destructor to clean up the object.
    ~BorrowRecord(){}

    // Getters for the variables memberId, bookId and active. 
    int getMemberId() const { return memberId; }
    int getBookId() const { return bookId; }
    bool isActive() const { return active; }

    // Deactives the the current borrow record.
    void deactivate(){
        active=false;
    }
};
#endif
