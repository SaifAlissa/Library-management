#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "Book.cpp"
#include "Member.cpp"
#include "Librarian.cpp"
#include "Admin.cpp"
#include "BorrowRecord.cpp"

// Класс библиотеки (library manager)
class Library {
private:
    // Массивы для хранения объектов (arrays for storing objects)
    Book* books[100];
    Member* members[100];
    Librarian* librarians[50];
    Admin* admins[20];
    BorrowRecord* records[500];

    // Счётчики объектов (object counters)
    int bookCount;
    int memberCount;
    int librarianCount;
    int adminCount;
    int recordCount;

    // Проверка: строка это число или нет (check if string is numeric)
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
    // Конструктор: начальная инициализация (initial setup)
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

    // Деструктор: очистка памяти (free allocated memory)
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

    // Добавить книгу (add a new book)
    bool addBook(string title, string author, int copies) {
        if (bookCount >= 100 || copies <= 0) {
            return false;
        }

        books[bookCount] = new Book(title, author, copies);
        bookCount++;
        return true;
    }

    // Добавить читателя (add a new member)
    bool addMember(string name, string password) {
        if (memberCount >= 100) {
            return false;
        }

        members[memberCount] = new Member(name, password);
        memberCount++;
        return true;
    }

    // Добавить библиотекаря (add a new librarian)
    bool addLibrarian(string name, string password) {
        if (librarianCount >= 50) {
            return false;
        }

        librarians[librarianCount] = new Librarian(name, password);
        librarianCount++;
        return true;
    }

    // Добавить администратора (add a new admin)
    bool addAdmin(string name, string password) {
        if (adminCount >= 20) {
            return false;
        }

        admins[adminCount] = new Admin(name, password);
        adminCount++;
        return true;
    }

    // Поиск книги по ID (search book by id)
    int searchBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr && books[i]->getId() == id) {
                return i;
            }
        }

        return -1;
    }

    // Поиск книги по названию (search book by title)
    int searchBook(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr && books[i]->getTitle() == title) {
                return i;
            }
        }

        return -1;
    }

    // Поиск книги по ID через отдельный метод (wrapper by id)
    int searchBookByID(int id) {
        return searchBook(id);
    }

    // Поиск книги по названию через отдельный метод (wrapper by title)
    int searchBookByTitle(string title) {
        return searchBook(title);
    }

    // Поиск читателя по ID (search member by id)
    int searchMemberById(int id) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i] != nullptr && members[i]->getId() == id) {
                return i;
            }
        }

        return -1;
    }

    // Вход читателя (member login)
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

    // Выдать книгу по строке: ID или название (borrow by id/title input)
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

        // Создать запись о выдаче (create borrow record)
        if (recordCount < 500) {
            records[recordCount] = new BorrowRecord(memberId, books[bookIndex]->getId());
            recordCount++;
        }

        return true;
    }

    // Выдать книгу по числовому ID (borrow by numeric id)
    bool borrowBook(int memberId, int bookId) {
        return borrowBook(memberId, to_string(bookId));
    }

    // Вернуть книгу (return a book)
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

                // Закрыть запись выдачи (close active record)
                records[i]->deactivate();

                // Вернуть копию книги (return one copy)
                books[bookIndex]->returnCopy();
                return true;
            }
        }

        cout << "No active borrow record found." << endl;
        return false;
    }

    // Показать все книги (show all books)
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

    // Показать только доступные книги (show available books only)
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

    // Поиск книг по ключевому слову (search by keyword)
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

    // Показать всех читателей (show all members)
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

    // Показать все записи выдачи (show all borrow records)
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

    // Показать статистику системы (show system statistics)
    void displayStatistics() const {
        cout << "Books in library: " << bookCount << endl;
        cout << "Members in library: " << memberCount << endl;
        cout << "Librarians in library: " << librarianCount << endl;
        cout << "Admins in library: " << adminCount << endl;
        cout << "Borrow Records in library: " << recordCount << endl;
    }

    // Показать данные администратора (show admin info)
    void displayAdminInfo(int adminIndex) const {
        if (adminIndex >= 0 && adminIndex < adminCount && admins[adminIndex] != nullptr) {
            admins[adminIndex]->displayInfo();
        } else {
            cout << "Admin not found." << endl;
        }
    }

    // Показать данные библиотекаря (show librarian info)
    void displayLibrarianInfo(int librarianIndex) const {
        if (librarianIndex >= 0 && librarianIndex < librarianCount && librarians[librarianIndex] != nullptr) {
            librarians[librarianIndex]->displayInfo();
        } else {
            cout << "Librarian not found." << endl;
        }
    }

    // Показать данные читателя (show member info)
    void displayMemberInfo(int memberIndex) const {
        if (memberIndex >= 0 && memberIndex < memberCount && members[memberIndex] != nullptr) {
            members[memberIndex]->displayInfo();
        } else {
            cout << "Member not found." << endl;
        }
    }

    // Показать книги, которые сейчас у читателя (show borrowed books of member)
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

    // Получить ID читателя по индексу (get member id by index)
    int getMemberIdByIndex(int memberIndex) const {
        if (memberIndex >= 0 && memberIndex < memberCount && members[memberIndex] != nullptr) {
            return members[memberIndex]->getId();
        }

        return -1;
    }
};