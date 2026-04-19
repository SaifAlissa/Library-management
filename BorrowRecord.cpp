#ifndef BORROWRECORD_CPP
#define BORROWRECORD_CPP

#include <iostream>
using namespace std;

class BorrowRecord {
private:
    int memberId;
    int bookId;
    bool active;

public:
    BorrowRecord() {
        memberId = 0;
        bookId = 0;
        active = false;
    }

    BorrowRecord(int member, int book) {
        memberId = member;
        bookId = book;
        active = true;
    }

    int getMemberId() const {
        return memberId;
    }

    int getBookId() const {
        return bookId;
    }

    bool isActive() const {
        return active;
    }

    void deactivate() {
        active = false;
    }
};

#endif