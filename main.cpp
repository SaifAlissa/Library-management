#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

#include "Library.cpp"

void adminMenu(Library &lib, int adminIndex);
void librarianMenu(Library &lib, int librarianIndex);
void memberMenu(Library &lib, int memberIndex);

void clearInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// This for clear the text in the terminal
void clearScreen(){
    system("cls");
}

void pauseScreen(){
    cout << "\nPress Enter to continue...";
    cin.get();
}
    
int main(){
    // Creating Library object
    Library lib;
    lib.addAdmin("admin", "1234");
    lib.addLibrarian("librarian", "1234");
    lib.addMember("member", "1234");
    lib.addBook("C++ Basics", "Bjarne", 3);
    lib.addBook("OOP in C++", "Author2", 2);

    int choice;
    do{
        clearScreen();
        cout << R"(
       .--.                   .---.
   .---|__|           .-.     |~~~|
.--|===|--|_          |_|     |~~~|--.
|  |===|  |'\     .---!~|  .--|   |--|
|%%|   |  |.'\    |===| |--|%%|   |  |
|%%|   |  |\.'\   |   | |__|  |   |  |
|  |   |  | \  \  |===| |==|  |   |  |
|  |   |__|  \.'\ |   |_|__|  |~~~|__|
|  |===|--|   \.'\|===|~|--|%%|~~~|--|
^--^---'--^    `-'`---^-^--^--^---'--')";
        cout << "\n======== Library Management System ========" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Librarian" << endl;
        cout << "3. Member" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice: ";
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
            }
            else{
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
            } 
            else {
                cout << "Invalid member login." << endl;
                pauseScreen();
            }
            break;
        }
        case 0:{
            cout << "Program ended." << endl;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            pauseScreen();
        }
        }
    }while (choice != 0);  
}

// This is the page of the admin
void adminMenu(Library &lib, int adminIndex){
    int choice;

    do{
        clearScreen();
        cout << R"(
      _.--._  _.--._
,-=.-":;:;:;\':;:;:;"-._
\\\:;:;:;:;:;\:;:;:;:;:;\
 \\\:;:;:;:;:;\:;:;:;:;:;\
  \\\:;:;:;:;:;\:;:;:;:;:;\
   \\\:;:;:;:;:;\:;::;:;:;:\
    \\\;:;::;:;:;\:;:;:;::;:\
     \\\;;:;:_:--:\:_:--:_;:;\    
      \\\_.-"      :      "-._\
       \`_..--""--.;.--""--.._=>)";
        cout << "\n======== Admin Menu ========" << endl;
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
        case 1:{
            
            lib.displayAdminInfo(adminIndex);
            pauseScreen();
            break;
        }
        case 2:{
            string name, password;
            cout << "Enter Admin name: ";
            getline(cin, name);
            cout << "Enter Admin password: ";
            getline(cin, password);

            if(lib.addAdmin(name, password)){

                cout << "Admin added successfully. " << endl;
            }
            else{
                cout << "Cannot add more admins." << endl;
            }
            pauseScreen();
            break;
        }
        case 3:{
            string name, password;
            cout << "Enter Librarian name: ";
            getline(cin, name);
            cout << "Enter Librarian password: ";
            getline(cin, password);

            if(lib.addLibrarian(name, password)){
                cout << "Librarian added successfully." << endl;
            }
            else{
                cout << "Cannot add more librarians." << endl;
            }
            pauseScreen();
            break;
        }
        case 4:{
            cout << "===== Admin Statistics =====" << endl;
            lib.displayStatistics();
            pauseScreen();
            break;
        }
        case 0:{
            cout << "Logging out..." << endl;
            pauseScreen();
            break;
        }
        default:{
            cout << "Invalid choice." << endl;
            pauseScreen();
        }
        }
    }while(choice != 0);
    
}

void librarianMenu(Library &lib, int librarianIndex){
    int choice;

    do{
        clearScreen();
        cout << R"(_________________________________________________
  |____________________________________________________|
  | __     __   ____   ___ ||  ____    ____     _  __  |
  ||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |
  ||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |
  ||  |##||  | | || | |JRO|||-|  | |==|+|+||-|-|~||__| |
  ||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|
  ||_______________________||__________________________|
  | _____________________  ||      __   __  _  __    _ |
  ||=|=|=|=|=|=|=|=|=|=|=| __..\/ |  |_|  ||#||==|  / /|
  || | | | | | | | | | | |/\ \  \\|++|=|  || ||==| / / |
  ||_|_|_|_|_|_|_|_|_|_|_/_/\_.___\__|_|__||_||__|/_/__|
  |____________________ /\~()/()~//\ __________________|
  | __   __    _  _     \_  (_ .  _/ _    ___     _____|
  ||~~|_|..|__| || |_ _   \ //\\ /  |=|__|~|~|___| | | |
  ||--|+|^^|==|1||2| | |__/\ __ /\__| |==|x|x|+|+|=|=|=|
  ||__|_|__|__|_||_|_| /  \ \  / /  \_|__|_|_|_|_|_|_|_|
  |_________________ _/    \/\/\/    \_ _______________|
  | _____   _   __  |/      \../      \|  __   __   ___|
  ||_____|_| |_|##|_||   |   \/ __|   ||_|==|_|++|_|-|||
  ||______||=|#|--| |\   \   o    /   /| |  |~|  | | |||
  ||______||_|_|__|_|_\   \  o   /   /_|_|__|_|__|_|_|||
  |_________ __________\___\____/___/___________ ______|
  |__    _  /    ________     ______           /| _ _ _|
  |\ \  |=|/   //    /| //   /  /  / |        / ||%|%|%|
  | \/\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|
__|  \/\|/   /(____|/ //                    /  /||~|~|~|__
  |___\_/   /________//   ________         /  / ||_|_|_|
  |___ /   (|________/   |\_______\       /  /| |______|
      /                  \|________)     /  / | |)";
        cout << "\n======== Librarian Menu ========" << endl;
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
            case 1: {
                
                lib.displayLibrarianInfo(librarianIndex);
                pauseScreen();
                break;
            }
            case 2: {
                string title, author;
                int copies;

                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> copies;
                clearInput();

                if(lib.addBook(title, author, copies)){
                    cout << "Book added successfully." << endl;
                }
                else{
                    cout << "Book could not be added." << endl;
                }
                pauseScreen();
                break;
            }
            case 3:{
                lib.displayAllBooks();
                pauseScreen();
                break;
            }
            case 4:{
                string keyword;
                cout << "Enter title or author keyword: ";
                getline(cin, keyword);
                lib.searchBooks(keyword);
                pauseScreen();
                break;
            }
            case 5:{
                string name, password;
                cout << "Enter member name: ";
                getline(cin, name);
                cout << "Enter member password: ";
                getline(cin, password);

                if(lib.addMember(name, password)){
                    cout << "Member added successfully." << endl;
                }
                else{
                    cout << "Cannot add more members.";
                }
                pauseScreen();
                break;
            }
            case 6:{
                lib.displayMembers();
                pauseScreen();
                break;
            }
            case 7:{
                lib.displayBorrowRecords();
                pauseScreen();
                break;
            }
            case 0:{
                cout << "Logging out..." << endl;
                pauseScreen();
                break;
            }
            default:{
                cout << "Invalid choice." << endl;
                pauseScreen();
            }
        }
    } while (choice != 0);
}

void memberMenu(Library &lib, int memberIndex){
    int choice;
    int memberId = lib.getMemberIdByIndex(memberIndex);

    do{
        clearScreen();
        cout << R"(
             .--.           .---.        .-.
         .---|--|   .-.     | A |  .---. |~|    .--.
      .--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---.
      |%%|NT2|oc|===| |~~|%%| C |--|   |_|~|CATS|  |___|-.
      |  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|
      |  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |
      |~~|===|--|===|~|~~|%%|~~~|--|:::|=|~|----|==|---|=|
      ^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-')";
        cout << "\n======== Member Menu ========" << endl;
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
            case 1:{
                lib.displayMemberInfo(memberIndex);
                pauseScreen();
                break;
            }
            case 2:{
                lib.displayAvailableBooks();
                pauseScreen();
                break;
            }
            case 3:{
                string keyword;
                cout << "Enter title or author keyword: ";
                getline(cin, keyword);
                lib.searchBooks(keyword);
                pauseScreen();
                break;
            }
            case 4:{
                int bookId;
                cout << "Enter book ID: ";
                cin >> bookId;
                clearInput();

                if(lib.borrowBook(memberId, bookId)){
                    cout << "Book borrowed successfully." << endl;
                }
                else{
                    cout << "Borrow failed." << endl;
                }
                pauseScreen();
                break;
            }
            case 5:{
                int bookId;
                cout << "Enter book ID: ";
                cin >> bookId;
                clearInput();

                if(lib.returnBook(memberId, bookId)){
                    cout << "Book returned successfully." << endl;
                }
                else{
                    cout << "Return failed." << endl;
                }
                pauseScreen();
                break;
            }
            case 6:{
                lib.displayBorrowedBooksForMember(memberId);
                pauseScreen();
                break;
            }
            case 0:{
                cout << "Logging out..." << endl;
                pauseScreen();
                break;
            }
            default:{
                cout << "Invalid choice." << endl;
                pauseScreen();
            }
        }
    } while(choice != 0);
}