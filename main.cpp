#include <iostream> // For input/output (для ввода и вывода)
#include <string>   // For string handling (для работы со строками)
#include <limits>   // For numeric_limits (для очистки ввода)
#include <cstdlib>  // For system() (для system("cls"))
using namespace std;

#include "Library.cpp" // Include Library class (подключаем класс Library)

// Function declarations (объявления функций)
void adminMenu(Library &lib, int adminIndex);         // Admin menu (меню администратора)
void librarianMenu(Library &lib, int librarianIndex); // Librarian menu (меню библиотекаря)
void memberMenu(Library &lib, int memberIndex);       // Member menu (меню читателя)

// Clears invalid input from the stream (очищает неправильный ввод из потока)
void clearInput(){
    cin.clear(); // Reset error flags (сбрасывает флаги ошибок)
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input (игнорирует оставшийся ввод)
}

// Clears terminal screen (очищает экран терминала)
void clearScreen(){
    system("cls"); // Clear screen in Windows (очищает экран в Windows)
}

// Pauses program until Enter is pressed (останавливает программу до нажатия Enter)
void pauseScreen(){
    cout << "\nPress Enter to continue..."; // Message to user (сообщение пользователю)
    cin.get(); // Wait for Enter (ожидает Enter)
}
    
// Main function — starting point of the program (главная функция — точка входа программы)
int main(){
    // Create Library object (создаём объект библиотеки)
    Library lib;

    // Add default data for testing (добавляем начальные данные для теста)
    lib.addAdmin("admin", "1234");              // Default admin (администратор по умолчанию)
    lib.addLibrarian("librarian", "1234");      // Default librarian (библиотекарь по умолчанию)
    lib.addMember("member", "1234");            // Default member (читатель по умолчанию)
    lib.addBook("C++ Basics", "Bjarne", 3);     // Sample book (пример книги)
    lib.addBook("OOP in C++", "Author2", 2);    // Sample book (пример книги)

    int choice; // Stores main menu choice (хранит выбор главного меню)

    // Main menu loop (цикл главного меню)
    do{
        clearScreen(); // Clear screen before showing menu (очищаем экран перед меню)

        // Display main menu (показываем главное меню)
        cout << "\n======== Library Management System ========" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Librarian" << endl;
        cout << "3. Member" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice: ";
<<<<<<< HEAD
        cin >> choice;
        clearInput();
        
        switch (choice)
        {

        // Case one is when the the user choice is 1 than the admin login will start
        case 1:{
            string input, password;
            cout << "Enter Name or ID: " << endl;
            //getline() is used for take all the line not just first word
            getline(cin, input);
            cout << "Enter Password: " << endl;
            getline(cin, password);

            // loginAdmin is a method in Library Class.
            int adminIndex = lib.loginAdmin(input, password);
            if(adminIndex != -1){
                // The name and the password is true than it will go to adminMenu method in main class
                adminMenu(lib, adminIndex);
            }
            else{
                cout << "Invalid admin login." << endl;
                pauseScreen();
            }
            break;
        }
        case 2: {
            string input, password;
            cout << "Enter Name or ID: " << endl;
            getline(cin, input);
            cout << "Enter Password: " << endl;
            getline(cin, password);

            int librarianIndex = lib.loginLibrarian(input, password);
            if(librarianIndex != -1){
                librarianMenu(lib, librarianIndex);
=======
        cin >> choice;   // Read user choice (читаем выбор пользователя)
        clearInput();    // Clear input buffer (очищаем буфер ввода)
        
        switch (choice)
        {
        // Admin login option (вариант входа администратора)
        case 1:{
            string input, password; // Store login data (хранят данные для входа)

            cout << "Enter Name or ID: " << endl;
            getline(cin, input); // Read whole line (считываем всю строку)

            cout << "Enter Password: " << endl;
            getline(cin, password); // Read password (считываем пароль)

            int adminIndex = lib.loginAdmin(input, password); // Try admin login (пытаемся войти как админ)

            if(adminIndex != -1){
                adminMenu(lib, adminIndex); // Open admin menu (открываем меню администратора)
            }
            else{
                cout << "Invalid admin login." << endl; // Login failed (ошибка входа)
                pauseScreen(); // Pause screen (пауза)
            }
            break;
        }

        // Librarian login option (вариант входа библиотекаря)
        case 2: {
            string input, password;

            cout << "Enter Name or ID: " << endl;
            getline(cin, input);

            cout << "Enter Password: " << endl;
            getline(cin, password);

            int librarianIndex = lib.loginLibrarian(input, password); // Try librarian login (пытаемся войти как библиотекарь)

            if(librarianIndex != -1){
                librarianMenu(lib, librarianIndex); // Open librarian menu (открываем меню библиотекаря)
>>>>>>> library
            }
            else{
                cout << "Invalid librarian login." << endl;
                pauseScreen();
            }
            break;
        }
<<<<<<< HEAD
        case 3: {
            string input, password;
            cout << "Enter name or ID: ";
            getline(cin, input);
            cout << "Enter password: ";
            getline(cin, password);

            int memberIndex = lib.loginMember(input, password);
            if (memberIndex != -1) {
                 memberMenu(lib, memberIndex);
=======

        // Member login option (вариант входа читателя)
        case 3: {
            string input, password;

            cout << "Enter name or ID: ";
            getline(cin, input);

            cout << "Enter password: ";
            getline(cin, password);

            int memberIndex = lib.loginMember(input, password); // Try member login (пытаемся войти как читатель)

            if (memberIndex != -1) {
                 memberMenu(lib, memberIndex); // Open member menu (открываем меню читателя)
>>>>>>> library
            } 
            else {
                cout << "Invalid member login." << endl;
                pauseScreen();
            }
            break;
        }
<<<<<<< HEAD
=======

        // Exit program (выход из программы)
>>>>>>> library
        case 0:{
            cout << "Program ended." << endl;
            break;
        }
<<<<<<< HEAD
=======

        // Invalid choice (неверный выбор)
>>>>>>> library
        default: {
            cout << "Invalid choice." << endl;
            pauseScreen();
        }
        }
<<<<<<< HEAD
    }while (choice != 0);  
}

// This is the page of the admin
void adminMenu(Library &lib, int adminIndex){
    int choice;

    do{
        clearScreen();
=======
    }while (choice != 0);  // Continue until user chooses 0 (повторяем пока не выберут 0)
}

// Admin menu function (функция меню администратора)
void adminMenu(Library &lib, int adminIndex){
    int choice; // Store admin choice (хранит выбор администратора)

    do{
        clearScreen();

        // Show admin menu (показываем меню администратора)
>>>>>>> library
        cout << "\nAdmin Menu" << endl;
        cout << "1. View My Information" << endl;
        cout << "2. Add Admin" << endl;
        cout << "3. Add Librarian" << endl;
        cout << "4. View Statistics" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        clearInput();
    
        switch (choice)
        {
<<<<<<< HEAD
=======
        // Show admin information (показать информацию администратора)
>>>>>>> library
        case 1:{
            lib.displayAdminInfo(adminIndex);
            pauseScreen();
            break;
        }
<<<<<<< HEAD
        case 2:{
            string name, password;
            cout << "Enter Admin name: ";
            getline(cin, name);
=======

        // Add new admin (добавить нового администратора)
        case 2:{
            string name, password;

            cout << "Enter Admin name: ";
            getline(cin, name);

>>>>>>> library
            cout << "Enter Admin password: ";
            getline(cin, password);

            if(lib.addAdmin(name, password)){
<<<<<<< HEAD

=======
>>>>>>> library
                cout << "Admin added successfully. " << endl;
            }
            else{
                cout << "Cannot add more admins." << endl;
            }
<<<<<<< HEAD
            pauseScreen();
            break;
        }
        case 3:{
            string name, password;
            cout << "Enter Librarian name: ";
            getline(cin, name);
=======

            pauseScreen();
            break;
        }

        // Add new librarian (добавить нового библиотекаря)
        case 3:{
            string name, password;

            cout << "Enter Librarian name: ";
            getline(cin, name);

>>>>>>> library
            cout << "Enter Librarian password: ";
            getline(cin, password);

            if(lib.addLibrarian(name, password)){
                cout << "Librarian added successfully." << endl;
            }
            else{
                cout << "Cannot add more librarians." << endl;
            }
<<<<<<< HEAD
            pauseScreen();
            break;
        }
=======

            pauseScreen();
            break;
        }

        // Show statistics (показать статистику)
>>>>>>> library
        case 4:{
            lib.displayStatistics();
            pauseScreen();
            break;
        }
<<<<<<< HEAD
=======

        // Logout (выход из аккаунта)
>>>>>>> library
        case 0:{
            cout << "Logging out..." << endl;
            pauseScreen();
            break;
        }
<<<<<<< HEAD
=======

        // Invalid choice (неверный выбор)
>>>>>>> library
        default:{
            cout << "Invalid choice." << endl;
            pauseScreen();
        }
        }
    }while(choice != 0);
<<<<<<< HEAD
    
}

void librarianMenu(Library &lib, int librarianIndex){
    int choice;

    do{
        clearScreen();
=======
}

// Librarian menu function (функция меню библиотекаря)
void librarianMenu(Library &lib, int librarianIndex){
    int choice; // Store librarian choice (хранит выбор библиотекаря)

    do{
        clearScreen();

        // Show librarian menu (показываем меню библиотекаря)
>>>>>>> library
        cout << "\nLibrarian Menu" << endl;
        cout << "1. View My Information" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. View All Books" << endl;
        cout << "4. Search Books" << endl;
        cout << "5. Add Member" << endl;
        cout << "6. View Members" << endl;
        cout << "7. View Borrow Records" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        clearInput();

        switch (choice){
<<<<<<< HEAD
=======
            // Show librarian info (показать информацию библиотекаря)
>>>>>>> library
            case 1: {
                lib.displayLibrarianInfo(librarianIndex);
                pauseScreen();
                break;
            }
<<<<<<< HEAD
=======

            // Add a new book (добавить новую книгу)
>>>>>>> library
            case 2: {
                string title, author;
                int copies;

                cout << "Enter book title: ";
                getline(cin, title);
<<<<<<< HEAD
                cout << "Enter book author: ";
                getline(cin, author);
=======

                cout << "Enter book author: ";
                getline(cin, author);

>>>>>>> library
                cout << "Enter number of copies: ";
                cin >> copies;
                clearInput();

                if(lib.addBook(title, author, copies)){
                    cout << "Book added successfully." << endl;
                }
                else{
                    cout << "Book could not be added." << endl;
                }
<<<<<<< HEAD
                pauseScreen();
                break;
            }
=======

                pauseScreen();
                break;
            }

            // Show all books (показать все книги)
>>>>>>> library
            case 3:{
                lib.displayAllBooks();
                pauseScreen();
                break;
            }
<<<<<<< HEAD
            case 4:{
                string keyword;
                cout << "Enter title or author keyword: ";
                getline(cin, keyword);
=======

            // Search books (поиск книг)
            case 4:{
                string keyword;

                cout << "Enter title or author keyword: ";
                getline(cin, keyword);

>>>>>>> library
                lib.searchBooks(keyword);
                pauseScreen();
                break;
            }
<<<<<<< HEAD
            case 5:{
                string name, password;
                cout << "Enter member name: ";
                getline(cin, name);
=======

            // Add new member (добавить нового читателя)
            case 5:{
                string name, password;

                cout << "Enter member name: ";
                getline(cin, name);

>>>>>>> library
                cout << "Enter member password: ";
                getline(cin, password);

                if(lib.addMember(name, password)){
                    cout << "Member added successfully." << endl;
                }
                else{
                    cout << "Cannot add more members.";
                }
<<<<<<< HEAD
                pauseScreen();
                break;
            }
=======

                pauseScreen();
                break;
            }

            // Show all members (показать всех читателей)
>>>>>>> library
            case 6:{
                lib.displayMembers();
                pauseScreen();
                break;
            }
<<<<<<< HEAD
=======

            // Show borrow records (показать записи выдачи)
>>>>>>> library
            case 7:{
                lib.displayBorrowRecords();
                pauseScreen();
                break;
            }
<<<<<<< HEAD
=======

            // Logout (выход)
>>>>>>> library
            case 0:{
                cout << "Logging out..." << endl;
                pauseScreen();
                break;
            }
<<<<<<< HEAD
=======

            // Invalid choice (неверный выбор)
>>>>>>> library
            default:{
                cout << "Invalid choice." << endl;
                pauseScreen();
            }
        }
    } while (choice != 0);
}

<<<<<<< HEAD
void memberMenu(Library &lib, int memberIndex){
    int choice;
    int memberId = lib.getMemberIdByIndex(memberIndex);

    do{
        clearScreen();
=======
// Member menu function (функция меню читателя)
void memberMenu(Library &lib, int memberIndex){
    int choice; // Store member choice (хранит выбор читателя)
    int memberId = lib.getMemberIdByIndex(memberIndex); // Get real member ID (получаем настоящий ID читателя)

    do{
        clearScreen();

        // Show member menu (показываем меню читателя)
>>>>>>> library
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

        switch (choice){
<<<<<<< HEAD
=======
            // Show member info (показать информацию читателя)
>>>>>>> library
            case 1:{
                lib.displayMemberInfo(memberIndex);
                pauseScreen();
                break;
            }
<<<<<<< HEAD
=======

            // Show available books (показать доступные книги)
>>>>>>> library
            case 2:{
                lib.displayAvailableBooks();
                pauseScreen();
                break;
            }
<<<<<<< HEAD
            case 3:{
                string keyword;
                cout << "Enter title or author keyword: ";
                getline(cin, keyword);
=======

            // Search books (поиск книг)
            case 3:{
                string keyword;

                cout << "Enter title or author keyword: ";
                getline(cin, keyword);

>>>>>>> library
                lib.searchBooks(keyword);
                pauseScreen();
                break;
            }
<<<<<<< HEAD
            case 4:{
                int bookId;
=======

            // Borrow a book (взять книгу)
            case 4:{
                int bookId;

>>>>>>> library
                cout << "Enter book ID: ";
                cin >> bookId;
                clearInput();

                if(lib.borrowBook(memberId, bookId)){
                    cout << "Book borrowed successfully." << endl;
                }
                else{
                    cout << "Borrow failed." << endl;
                }
<<<<<<< HEAD
                pauseScreen();
                break;
            }
            case 5:{
                int bookId;
=======

                pauseScreen();
                break;
            }

            // Return a book (вернуть книгу)
            case 5:{
                int bookId;

>>>>>>> library
                cout << "Enter book ID: ";
                cin >> bookId;
                clearInput();

                if(lib.returnBook(memberId, bookId)){
                    cout << "Book returned successfully." << endl;
                }
                else{
                    cout << "Return failed." << endl;
                }
<<<<<<< HEAD
                pauseScreen();
                break;
            }
=======

                pauseScreen();
                break;
            }

            // Show borrowed books (показать книги, взятые читателем)
>>>>>>> library
            case 6:{
                lib.displayBorrowedBooksForMember(memberId);
                pauseScreen();
                break;
            }
<<<<<<< HEAD
=======

            // Logout (выход)
>>>>>>> library
            case 0:{
                cout << "Logging out..." << endl;
                pauseScreen();
                break;
            }
<<<<<<< HEAD
=======

            // Invalid choice (неверный выбор)
>>>>>>> library
            default:{
                cout << "Invalid choice." << endl;
                pauseScreen();
            }
        }
    } while(choice != 0);
}