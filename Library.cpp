#ifndef LIBRARY_CPP
#define LIBRARY_CPP

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "Book.cpp"
#include "Member.cpp"
#include "Librarian.cpp"
#include "Admin.cpp"
#include "BorrowRecord.cpp"

class Library {
private:
    Book* books[100];
    Member* members[100];
    Librarian* librarians[50];
    Admin* admins[20];
    BorrowRecord* records[500];

    int bookCount;
    int memberCount;
    int librarianCount;
    int adminCount;
    int recordCount;

    bool isNumber(string text) const {
        if (text.empty()) {
            return false;
        }

        for (int i = 0; i < (int)text.length(); i++) {
            if (!isdigit((unsigned char)text[i])) {
                return false;
            }
        }
        return true;
    }

public:
    Library() {
        bookCount = 0;
        memberCount = 0;
        librarianCount = 0;
        adminCount = 0;
        recordCount = 0;

        for (int i = 0; i < 100; i++) {
            books[i] = nullptr;
            members[i] = nullptr;
        }

        for (int i = 0; i < 50; i++) {
            librarians[i] = nullptr;
        }

        for (int i = 0; i < 20; i++) {
            admins[i] = nullptr;
        }

        for (int i = 0; i < 500; i++) {
            records[i] = nullptr;
        }
    }

    ~Library() {
        for (int i = 0; i < bookCount; i++) {
            delete books[i];
        }

        for (int i = 0; i < memberCount; i++) {
            delete members[i];
        }

        for (int i = 0; i < librarianCount; i++) {
            delete librarians[i];
        }

        for (int i = 0; i < adminCount; i++) {
            delete admins[i];
        }

        for (int i = 0; i < recordCount; i++) {
            delete records[i];
        }
    }

    bool addBook(string title, string author, int copies) {
        if (bookCount >= 100 || copies <= 0) {
            return false;
        }

        books[bookCount] = new Book(title, author, copies);
        bookCount++;
        return true;
    }

    bool addMember(string name, string password) {
        if (memberCount >= 100) {
            return false;
        }

        members[memberCount] = new Member(name, password);
        memberCount++;
        return true;
    }

    bool addLibrarian(string name, string password) {
        if (librarianCount >= 50) {
            return false;
        }

        librarians[librarianCount] = new Librarian(name, password);
        librarianCount++;
        return true;
    }

    bool addAdmin(string name, string password) {
        if (adminCount >= 20) {
            return false;
        }

        admins[adminCount] = new Admin(name, password);
        adminCount++;
        return true;
    }

    int searchBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr && books[i]->getId() == id) {
                return i;
            }
        }
        return -1;
    }

    int searchBook(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr && books[i]->getTitle() == title) {
                return i;
            }
        }
        return -1;
    }

    int searchBookByID(int id) {
        return searchBook(id);
    }

    int searchBookByTitle(string title) {
        return searchBook(title);
    }

    int searchMemberById(int id) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i] != nullptr && members[i]->getId() == id) {
                return i;
            }
        }
        return -1;
    }

    int loginMember(string input, string password) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i] != nullptr) {
                if ((members[i]->getName() == input || to_string(members[i]->getId()) == input) &&
                    members[i]->checkPassword(password)) {
                    return i;
                }
            }
        }
        return -1;
    }

    int loginLibrarian(string input, string password) {
        for (int i = 0; i < librarianCount; i++) {
            if (librarians[i] != nullptr) {
                if ((librarians[i]->getName() == input || to_string(librarians[i]->getId()) == input) &&
                    librarians[i]->checkPassword(password)) {
                    return i;
                }
            }
        }
        return -1;
    }

    int loginAdmin(string input, string password) {
        for (int i = 0; i < adminCount; i++) {
            if (admins[i] != nullptr) {
                if ((admins[i]->getName() == input || to_string(admins[i]->getId()) == input) &&
                    admins[i]->checkPassword(password)) {
                    return i;
                }
            }
        }
        return -1;
    }

    bool borrowBook(int memberId, string bookInput) {
        int memberIndex = searchMemberById(memberId);
        if (memberIndex == -1) {
            cout << "Member not found." << endl;
            return false;
        }

        int bookIndex = -1;

        if (isNumber(bookInput)) {
            bookIndex = searchBookByID(stoi(bookInput));
        } else {
            bookIndex = searchBookByTitle(bookInput);
        }

        if (bookIndex == -1) {
            cout << "Book not found." << endl;
            return false;
        }

        if (!books[bookIndex]->borrowCopy()) {
            cout << "No available copies." << endl;
            return false;
        }

        if (recordCount < 500) {
            records[recordCount] = new BorrowRecord(memberId, books[bookIndex]->getId());
            recordCount++;
        }

        return true;
    }

    bool borrowBook(int memberId, int bookId) {
        return borrowBook(memberId, to_string(bookId));
    }

    bool returnBook(int memberId, int bookId) {
        int memberIndex = searchMemberById(memberId);
        int bookIndex = searchBookByID(bookId);

        if (memberIndex == -1 || bookIndex == -1) {
            cout << "Member or Book not found." << endl;
            return false;
        }

        for (int i = 0; i < recordCount; i++) {
            if (records[i] != nullptr &&
                records[i]->getMemberId() == memberId &&
                records[i]->getBookId() == bookId &&
                records[i]->isActive()) {

                records[i]->deactivate();
                books[bookIndex]->returnCopy();
                return true;
            }
        }

        cout << "No active borrow record found." << endl;
        return false;
    }

    void displayAllBooks() const {
        if (bookCount == 0) {
            cout << "No books available." << endl;
            return;
        }

        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr) {
                cout << "----------------------" << endl;
                books[i]->displayInfo();
            }
        }
    }

    void displayAvailableBooks() const {
        bool found = false;

        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr && books[i]->getAvailableCopies() > 0) {
                cout << "----------------------" << endl;
                books[i]->displayInfo();
                found = true;
            }
        }

        if (!found) {
            cout << "No available books." << endl;
        }
    }

    void searchBooks(string keyword) const {
        bool found = false;

        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr) {
                if (books[i]->getTitle().find(keyword) != string::npos ||
                    books[i]->getAuthor().find(keyword) != string::npos) {
                    cout << "----------------------" << endl;
                    books[i]->displayInfo();
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "No matching books found." << endl;
        }
    }

    void displayMembers() const {
        if (memberCount == 0) {
            cout << "No members available." << endl;
            return;
        }

        for (int i = 0; i < memberCount; i++) {
            if (members[i] != nullptr) {
                cout << "----------------------" << endl;
                members[i]->displayInfo();
            }
        }
    }

    void displayBorrowRecords() const {
        if (recordCount == 0) {
            cout << "No borrow records available." << endl;
            return;
        }

        for (int i = 0; i < recordCount; i++) {
            if (records[i] != nullptr) {
                cout << "----------------------" << endl;
                cout << "Member ID: " << records[i]->getMemberId() << endl;
                cout << "Book ID: " << records[i]->getBookId() << endl;
                cout << "Status: " << (records[i]->isActive() ? "Borrowed" : "Returned") << endl;
            }
        }
    }

    void displayStatistics() const {
        cout << "Books in library: " << bookCount << endl;
        cout << "Members in library: " << memberCount << endl;
        cout << "Librarians in library: " << librarianCount << endl;
        cout << "Admins in library: " << adminCount << endl;
        cout << "Borrow Records in library: " << recordCount << endl;
    }

    void displayAdminInfo(int adminIndex) const {
        if (adminIndex >= 0 && adminIndex < adminCount && admins[adminIndex] != nullptr) {
            admins[adminIndex]->displayInfo();
        } else {
            cout << "Admin not found." << endl;
        }
    }

    void displayLibrarianInfo(int librarianIndex) const {
        if (librarianIndex >= 0 && librarianIndex < librarianCount && librarians[librarianIndex] != nullptr) {
            librarians[librarianIndex]->displayInfo();
        } else {
            cout << "Librarian not found." << endl;
        }
    }

    void displayMemberInfo(int memberIndex) const {
        if (memberIndex >= 0 && memberIndex < memberCount && members[memberIndex] != nullptr) {
            members[memberIndex]->displayInfo();
        } else {
            cout << "Member not found." << endl;
        }
    }

    void displayBorrowedBooksForMember(int memberId) const {
        bool found = false;

        for (int i = 0; i < recordCount; i++) {
            if (records[i] != nullptr &&
                records[i]->getMemberId() == memberId &&
                records[i]->isActive()) {

                int borrowedBookId = records[i]->getBookId();

                for (int j = 0; j < bookCount; j++) {
                    if (books[j] != nullptr && books[j]->getId() == borrowedBookId) {
                        cout << "----------------------" << endl;
                        books[j]->displayInfo();
                        found = true;
                        break;
                    }
                }
            }
        }

        if (!found) {
            cout << "You have not borrowed any books." << endl;
        }
    }

    int getMemberIdByIndex(int memberIndex) const {
        if (memberIndex >= 0 && memberIndex < memberCount && members[memberIndex] != nullptr) {
            return members[memberIndex]->getId();
        }
        return -1;
    }
};

#endif