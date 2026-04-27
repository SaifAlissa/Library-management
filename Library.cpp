

#include <iostream> // For input/output (для ввода и вывода)
#include <string>   // For string operations (для работы со строками)
#include <cctype>   // For isdigit() (для проверки символов)
using namespace std; // To avoid writing std:: (чтобы не писать std::)

// Include all related classes (подключаем все связанные классы)
#include "Book.cpp"
#include "Member.cpp"
#include "Librarian.cpp"
#include "Admin.cpp"
#include "BorrowRecord.cpp"

// Library class manages the whole library system (класс Library управляет всей библиотечной системой)
class Library {
private:
    // Arrays of pointers to store objects (массивы указателей для хранения объектов)
    Book* books[100];              // Stores books (хранит книги)
    Member* members[100];          // Stores members (хранит читателей)
    Librarian* librarians[50];     // Stores librarians (хранит библиотекарей)
    Admin* admins[20];             // Stores admins (хранит администраторов)
    BorrowRecord* records[500];    // Stores borrow records (хранит записи выдачи)

    // Counters for number of stored objects (счётчики количества объектов)
    int bookCount;         // Number of books (количество книг)
    int memberCount;       // Number of members (количество читателей)
    int librarianCount;    // Number of librarians (количество библиотекарей)
    int adminCount;        // Number of admins (количество администраторов)
    int recordCount;       // Number of borrow records (количество записей выдачи)

    // Check if input string contains only digits (проверяет, состоит ли строка только из цифр)
    bool isNumber(string text) const {
        if (text.empty()) { // If string is empty (если строка пустая)
            return false;
        }

        for (int i = 0; i < (int)text.length(); i++) { // Check every character (проверяем каждый символ)
            if (!isdigit((unsigned char)text[i])) { // If not a digit (если не цифра)
                return false;
            }
        }

        return true; // String is numeric (строка является числом)
    }

public:
    // Constructor initializes all counters and arrays (конструктор инициализирует счётчики и массивы)
    Library() {
        bookCount = 0;       // Start with 0 books (в начале 0 книг)
        memberCount = 0;     // Start with 0 members (в начале 0 читателей)
        librarianCount = 0;  // Start with 0 librarians (в начале 0 библиотекарей)
        adminCount = 0;      // Start with 0 admins (в начале 0 администраторов)
        recordCount = 0;     // Start with 0 records (в начале 0 записей)

        // Initialize book and member arrays with nullptr (заполняем массивы nullptr)
        for (int i = 0; i < 100; i++) {
            books[i] = nullptr;
            members[i] = nullptr;
        }

        // Initialize librarian array (инициализация массива библиотекарей)
        for (int i = 0; i < 50; i++) {
            librarians[i] = nullptr;
        }

        // Initialize admin array (инициализация массива администраторов)
        for (int i = 0; i < 20; i++) {
            admins[i] = nullptr;
        }

        // Initialize borrow record array (инициализация массива записей выдачи)
        for (int i = 0; i < 500; i++) {
            records[i] = nullptr;
        }
    }

    // Destructor frees allocated memory (деструктор освобождает выделенную память)
    ~Library() {
        for (int i = 0; i < bookCount; i++) { // Delete all books (удаляем все книги)
            delete books[i];
        }

        for (int i = 0; i < memberCount; i++) { // Delete all members (удаляем всех читателей)
            delete members[i];
        }

        for (int i = 0; i < librarianCount; i++) { // Delete all librarians (удаляем всех библиотекарей)
            delete librarians[i];
        }

        for (int i = 0; i < adminCount; i++) { // Delete all admins (удаляем всех администраторов)
            delete admins[i];
        }

        for (int i = 0; i < recordCount; i++) { // Delete all records (удаляем все записи)
            delete records[i];
        }
    }

    // Add a new book (добавляет новую книгу)
    bool addBook(string title, string author, int copies) {
        if (bookCount >= 100 || copies <= 0) { // Check capacity and copies (проверяем лимит и количество копий)
            return false;
        }

        books[bookCount] = new Book(title, author, copies); // Create and store book (создаём и сохраняем книгу)
        bookCount++; // Increase book counter (увеличиваем счётчик книг)
        return true;
    }

    // Add a new member (добавляет нового читателя)
    bool addMember(string name, string password) {
        if (memberCount >= 100) { // Check capacity (проверяем лимит)
            return false;
        }

        members[memberCount] = new Member(name, password); // Create member (создаём читателя)
        memberCount++; // Increase member counter (увеличиваем счётчик читателей)
        return true;
    }

    // Add a new librarian (добавляет нового библиотекаря)
    bool addLibrarian(string name, string password) {
        if (librarianCount >= 50) { // Check capacity (проверяем лимит)
            return false;
        }

        librarians[librarianCount] = new Librarian(name, password); // Create librarian (создаём библиотекаря)
        librarianCount++; // Increase counter (увеличиваем счётчик)
        return true;
    }

    // Add a new admin (добавляет нового администратора)
    bool addAdmin(string name, string password) {
        if (adminCount >= 20) { // Check capacity (проверяем лимит)
            return false;
        }

        admins[adminCount] = new Admin(name, password); // Create admin (создаём администратора)
        adminCount++; // Increase counter (увеличиваем счётчик)
        return true;
    }

    // Search book by ID and return index (ищет книгу по ID и возвращает индекс)
    int searchBook(int id) {
        for (int i = 0; i < bookCount; i++) { // Loop through books (проходим по книгам)
            if (books[i] != nullptr && books[i]->getId() == id) { // If found (если нашли)
                return i;
            }
        }

        return -1; // Not found (не найдено)
    }

    // Search book by title and return index (ищет книгу по названию и возвращает индекс)
    int searchBook(string title) {
        for (int i = 0; i < bookCount; i++) { // Loop through books (проходим по книгам)
            if (books[i] != nullptr && books[i]->getTitle() == title) { // If found (если нашли)
                return i;
            }
        }

        return -1; // Not found (не найдено)
    }

    // Wrapper for search by ID (обёртка для поиска по ID)
    int searchBookByID(int id) {
        return searchBook(id);
    }

    // Wrapper for search by title (обёртка для поиска по названию)
    int searchBookByTitle(string title) {
        return searchBook(title);
    }

    // Search member by ID and return index (ищет читателя по ID и возвращает индекс)
    int searchMemberById(int id) {
        for (int i = 0; i < memberCount; i++) { // Loop through members (проходим по читателям)
            if (members[i] != nullptr && members[i]->getId() == id) { // If found (если нашли)
                return i;
            }
        }

        return -1; // Not found (не найдено)
    }

    // Login member by name/ID and password (вход читателя по имени/ID и паролю)
    int loginMember(string input, string password) {
        for (int i = 0; i < memberCount; i++) { // Loop through members (проходим по читателям)
            if (members[i] != nullptr) { // Check valid pointer (проверяем указатель)
                if ((members[i]->getName() == input || to_string(members[i]->getId()) == input) &&
                    members[i]->checkPassword(password)) { // Check credentials (проверяем данные)
                    return i;
                }
            }
        }
        return -1; // Login failed (вход не выполнен)
    }

    // Login librarian by name/ID and password (вход библиотекаря по имени/ID и паролю)
    int loginLibrarian(string input, string password) {
        for (int i = 0; i < librarianCount; i++) { // Loop through librarians (проходим по библиотекарям)
            if (librarians[i] != nullptr) {
                if ((librarians[i]->getName() == input || to_string(librarians[i]->getId()) == input) &&
                    librarians[i]->checkPassword(password)) {
                    return i;
                }
            }
        }
        return -1; // Login failed (вход не выполнен)
    }

    // Login admin by name/ID and password (вход администратора по имени/ID и паролю)
    int loginAdmin(string input, string password) {
        for (int i = 0; i < adminCount; i++) { // Loop through admins (проходим по администраторам)
            if (admins[i] != nullptr) {
                if ((admins[i]->getName() == input || to_string(admins[i]->getId()) == input) &&
                    admins[i]->checkPassword(password)) {
                    return i;
                }
            }
        }
        return -1; // Login failed (вход не выполнен)
    }

    // Borrow book using string input (ID or title) (выдача книги по строке: ID или название)
    bool borrowBook(int memberId, string bookInput) {
        int memberIndex = searchMemberById(memberId); // Find member (ищем читателя)

        if (memberIndex == -1) { // If member not found (если читатель не найден)
            cout << "Member not found." << endl;
            return false;
        }

        int bookIndex = -1; // Default invalid index (индекс по умолчанию)

        if (isNumber(bookInput)) { // If input is numeric (если строка — число)
            bookIndex = searchBookByID(stoi(bookInput)); // Search by ID (поиск по ID)
        } else {
            bookIndex = searchBookByTitle(bookInput); // Search by title (поиск по названию)
        }

        if (bookIndex == -1) { // If book not found (если книга не найдена)
            cout << "Book not found." << endl;
            return false;
        }

        if (!books[bookIndex]->borrowCopy()) { // If no available copies (если нет доступных копий)
            cout << "No available copies." << endl;
            return false;
        }

        if (recordCount < 500) { // If record space exists (если есть место для записи)
            records[recordCount] = new BorrowRecord(memberId, books[bookIndex]->getId()); // Create record (создаём запись)
            recordCount++; // Increase record counter (увеличиваем счётчик записей)
        }

        return true; // Borrow success (книга успешно выдана)
    }

    // Borrow book using numeric ID (выдача книги по числовому ID)
    bool borrowBook(int memberId, int bookId) {
        return borrowBook(memberId, to_string(bookId)); // Convert int to string (преобразуем число в строку)
    }

    // Return book (возврат книги)
    bool returnBook(int memberId, int bookId) {
        int memberIndex = searchMemberById(memberId); // Find member (ищем читателя)
        int bookIndex = searchBookByID(bookId); // Find book (ищем книгу)

        if (memberIndex == -1 || bookIndex == -1) { // If member or book missing (если не найден читатель или книга)
            cout << "Member or Book not found." << endl;
            return false;
        }

        for (int i = 0; i < recordCount; i++) { // Loop through borrow records (проходим по записям)
            if (records[i] != nullptr &&
                records[i]->getMemberId() == memberId &&
                records[i]->getBookId() == bookId &&
                records[i]->isActive()) { // Find active record (ищем активную запись)

                records[i]->deactivate(); // Mark record inactive (деактивируем запись)
                books[bookIndex]->returnCopy(); // Return one copy (возвращаем одну копию)
                return true;
            }
        }

        cout << "No active borrow record found." << endl; // Record not found (запись не найдена)
        return false;
    }

    // Display all books (показать все книги)
    void displayAllBooks() const {
        if (bookCount == 0) { // If no books (если книг нет)
            cout << "No books available." << endl;
            return;
        }

        for (int i = 0; i < bookCount; i++) { // Loop through books (проходим по книгам)
            if (books[i] != nullptr) {
                cout << "----------------------" << endl; // Separator (разделитель)
                books[i]->displayInfo(); // Show book info (показываем книгу)
            }
        }
    }

    // Display only available books (показать только доступные книги)
    void displayAvailableBooks() const {
        bool found = false; // Track if any available book exists (флаг найденной книги)

        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr && books[i]->getAvailableCopies() > 0) {
                cout << "----------------------" << endl;
                books[i]->displayInfo();
                found = true;
            }
        }

        if (!found) { // If none found (если не найдено)
            cout << "No available books." << endl;
        }
    }

    // Search books by keyword in title or author (поиск книги по слову в названии или авторе)
    void searchBooks(string keyword) const {
        bool found = false; // Flag for search result (флаг результата поиска)

        for (int i = 0; i < bookCount; i++) {
            if (books[i] != nullptr) {
                if (books[i]->getTitle().find(keyword) != string::npos ||
                    books[i]->getAuthor().find(keyword) != string::npos) { // Match found (найдено совпадение)
                    cout << "----------------------" << endl;
                    books[i]->displayInfo();
                    found = true;
                }
            }
        }

        if (!found) { // If nothing matched (если совпадений нет)
            cout << "No matching books found." << endl;
        }
    }

    // Display all members (показать всех читателей)
    void displayMembers() const {
        if (memberCount == 0) { // If no members (если читателей нет)
            cout << "No members available." << endl;
            return;
        }

        for (int i = 0; i < memberCount; i++) { // Loop through members (проходим по читателям)
            if (members[i] != nullptr) {
                cout << "----------------------" << endl;
                members[i]->displayInfo();
            }
        }
    }

    // Display all borrow records (показать все записи выдачи)
    void displayBorrowRecords() const {
        if (recordCount == 0) { // If no records (если записей нет)
            cout << "No borrow records available." << endl;
            return;
        }

        for (int i = 0; i < recordCount; i++) { // Loop through records (проходим по записям)
            if (records[i] != nullptr) {
                cout << "----------------------" << endl;
                cout << "Member ID: " << records[i]->getMemberId() << endl; // Show member ID (показываем ID читателя)
                cout << "Book ID: " << records[i]->getBookId() << endl;     // Show book ID (показываем ID книги)
                cout << "Status: " << (records[i]->isActive() ? "Borrowed" : "Returned") << endl; // Show status (показываем статус)
            }
        }
    }

    // Display system statistics (показать статистику системы)
    void displayStatistics() const {
        cout << "Books in library: " << bookCount << endl;         // Number of books (количество книг)
        cout << "Members in library: " << memberCount << endl;     // Number of members (количество читателей)
        cout << "Librarians in library: " << librarianCount << endl; // Number of librarians (количество библиотекарей)
        cout << "Admins in library: " << adminCount << endl;       // Number of admins (количество админов)
        cout << "Borrow Records in library: " << recordCount << endl; // Number of records (количество записей)
    }

    // Display specific admin info (показать информацию об администраторе)
    void displayAdminInfo(int adminIndex) const {
        if (adminIndex >= 0 && adminIndex < adminCount && admins[adminIndex] != nullptr) {
            admins[adminIndex]->displayInfo();
        } else {
            cout << "Admin not found." << endl;
        }
    }

    // Display specific librarian info (показать информацию о библиотекаре)
    void displayLibrarianInfo(int librarianIndex) const {
        if (librarianIndex >= 0 && librarianIndex < librarianCount && librarians[librarianIndex] != nullptr) {
            librarians[librarianIndex]->displayInfo();
        } else {
            cout << "Librarian not found." << endl;
        }
    }

    // Display specific member info (показать информацию о читателе)
    void displayMemberInfo(int memberIndex) const {
        if (memberIndex >= 0 && memberIndex < memberCount && members[memberIndex] != nullptr) {
            members[memberIndex]->displayInfo();
        } else {
            cout << "Member not found." << endl;
        }
    }

    // Display borrowed books of a member (показать книги, взятые читателем)
    void displayBorrowedBooksForMember(int memberId) const {
        bool found = false; // Flag if member has borrowed books (флаг наличия книг)

        for (int i = 0; i < recordCount; i++) {
            if (records[i] != nullptr &&
                records[i]->getMemberId() == memberId &&
                records[i]->isActive()) { // Find active records of member (ищем активные записи читателя)

                int borrowedBookId = records[i]->getBookId(); // Save borrowed book ID (сохраняем ID книги)

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

        if (!found) { // If no active books (если у читателя нет активных книг)
            cout << "You have not borrowed any books." << endl;
        }
    }

    // Get member ID by index (получить ID читателя по индексу)
    int getMemberIdByIndex(int memberIndex) const {
        if (memberIndex >= 0 && memberIndex < memberCount && members[memberIndex] != nullptr) {
            return members[memberIndex]->getId();
        }

        return -1; // Invalid index (неверный индекс)
    }
};
