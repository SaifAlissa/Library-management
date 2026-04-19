#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

#include "Library.cpp"

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

void adminMenu(Library &lib, int adminIndex) {
    int choice;

    do {
        clearScreen();
        cout << "\nAdmin Menu" << endl;
        cout << "1. Add Admin" << endl;
        cout << "2. Add Librarian" << endl;
        cout << "3. View Statistics" << endl;
        cout << "4. View My Information" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1: {
                string name, password;
                cout << "Enter admin name: ";
                getline(cin, name);
                cout << "Enter admin password: ";
                getline(cin, password);

                if (lib.addAdmin(name, password)) {
                    cout << "Admin added successfully." << endl;
                } else {
                    cout << "Cannot add more admins." << endl;
                }
                pauseScreen();
                break;
            }
            case 2: {
                string name, password;
                cout << "Enter librarian name: ";
                getline(cin, name);
                cout << "Enter librarian password: ";
                getline(cin, password);

                if (lib.addLibrarian(name, password)) {
                    cout << "Librarian added successfully." << endl;
                } else {
                    cout << "Cannot add more librarians." << endl;
                }
                pauseScreen();
                break;
            }
            case 3:
                lib.displayStatistics();
                pauseScreen();
                break;
            case 4:
                lib.displayAdminInfo(adminIndex);
                pauseScreen();
                break;
            case 0:
                cout << "Logging out..." << endl;
                pauseScreen();
                break;
            default:
                cout << "Invalid choice." << endl;
                pauseScreen();
        }
    } while (choice != 0);
}

void librarianMenu(Library &lib, int librarianIndex) {
    int choice;

    do {
        clearScreen();
        cout << "\nLibrarian Menu" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View All Books" << endl;
        cout << "3. Search Books" << endl;
        cout << "4. Add Member" << endl;
        cout << "5. View Members" << endl;
        cout << "6. View Borrow Records" << endl;
        cout << "7. View My Information" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1: {
                string title, author;
                int copies;
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                clearInput();

                if (lib.addBook(title, author, copies)) {
                    cout << "Book added successfully." << endl;
                } else {
                    cout << "Book could not be added." << endl;
                }
                pauseScreen();
                break;
            }
            case 2:
                lib.displayAllBooks();
                pauseScreen();
                break;
            case 3: {
                string keyword;
                cout << "Enter title or author keyword: ";
                getline(cin, keyword);
                lib.searchBooks(keyword);
                pauseScreen();
                break;
            }
            case 4: {
                string name, password;
                cout << "Enter member name: ";
                getline(cin, name);
                cout << "Enter member password: ";
                getline(cin, password);

                if (lib.addMember(name, password)) {
                    cout << "Member added successfully." << endl;
                } else {
                    cout << "Cannot add more members." << endl;
                }
                pauseScreen();
                break;
            }
            case 5:
                lib.displayMembers();
                pauseScreen();
                break;
            case 6:
                lib.displayBorrowRecords();
                pauseScreen();
                break;
            case 7:
                lib.displayLibrarianInfo(librarianIndex);
                pauseScreen();
                break;
            case 0:
                cout << "Logging out..." << endl;
                pauseScreen();
                break;
            default:
                cout << "Invalid choice." << endl;
                pauseScreen();
        }
    } while (choice != 0);
}

void memberMenu(Library &lib, int memberIndex) {
    int choice;
    int memberId = lib.getMemberIdByIndex(memberIndex);

    do {
        clearScreen();
        cout << "\nMember Menu" << endl;
        cout << "1. View My Information" << endl;
        cout << "2. View Available Books" << endl;
        cout << "3. Search Books" << endl;
        cout << "4. Borrow Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. View My Borrowed Books" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1:
                lib.displayMemberInfo(memberIndex);
                pauseScreen();
                break;
            case 2:
                lib.displayAvailableBooks();
                pauseScreen();
                break;
            case 3: {
                string keyword;
                cout << "Enter title or author keyword: ";
                getline(cin, keyword);
                lib.searchBooks(keyword);
                pauseScreen();
                break;
            }
            case 4: {
                int bookId;
                cout << "Enter book ID: ";
                cin >> bookId;
                clearInput();

                if (lib.borrowBook(memberId, bookId)) {
                    cout << "Book borrowed successfully." << endl;
                } else {
                    cout << "Borrow failed." << endl;
                }
                pauseScreen();
                break;
            }
            case 5: {
                int bookId;
                cout << "Enter book ID: ";
                cin >> bookId;
                clearInput();

                if (lib.returnBook(memberId, bookId)) {
                    cout << "Book returned successfully." << endl;
                } else {
                    cout << "Return failed." << endl;
                }
                pauseScreen();
                break;
            }
            case 6:
                lib.displayBorrowedBooksForMember(memberId);
                pauseScreen();
                break;
            case 0:
                cout << "Logging out..." << endl;
                pauseScreen();
                break;
            default:
                cout << "Invalid choice." << endl;
                pauseScreen();
        }
    } while (choice != 0);
}

int main() {
    Library lib;
    lib.addAdmin("admin", "1234");
    lib.addLibrarian("librarian", "1234");
    lib.addMember("member", "1234");
    lib.addBook("C++ Basics", "Bjarne", 3);
    lib.addBook("OOP in C++", "Author2", 2);

    int choice;

    do {
        clearScreen();
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Librarian" << endl;
        cout << "3. Member" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1: {
                string input, password;
                cout << "Enter name or ID: ";
                getline(cin, input);
                cout << "Enter password: ";
                getline(cin, password);

                int adminIndex = lib.loginAdmin(input, password);
                if (adminIndex != -1) {
                    adminMenu(lib, adminIndex);
                } else {
                    cout << "Invalid admin login." << endl;
                    pauseScreen();
                }
                break;
            }
            case 2: {
                string input, password;
                cout << "Enter name or ID: ";
                getline(cin, input);
                cout << "Enter password: ";
                getline(cin, password);

                int librarianIndex = lib.loginLibrarian(input, password);
                if (librarianIndex != -1) {
                    librarianMenu(lib, librarianIndex);
                } else {
                    cout << "Invalid librarian login." << endl;
                    pauseScreen();
                }
                break;
            }
            case 3: {
                string input, password;
                cout << "Enter name or ID: ";
                getline(cin, input);
                cout << "Enter password: ";
                getline(cin, password);

                int memberIndex = lib.loginMember(input, password);
                if (memberIndex != -1) {
                    memberMenu(lib, memberIndex);
                } else {
                    cout << "Invalid member login." << endl;
                    pauseScreen();
                }
                break;
            }
            case 0:
                cout << "Program ended." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                pauseScreen();
        }
    } while (choice != 0);

    return 0;
}