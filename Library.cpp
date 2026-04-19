 #include <iostream> 
 using namespace std;

 class Library
 {
 private:
  
 public:
    Library();

    bool addAdmin(string a, string b);
    bool addLibrarian(string a, string b);
    bool addMember(string a, string b);
    bool addBook(string a, string b, int c);
    int loginAdmin(string a, string b);
    int loginLibrarian(string a, string b);
    int loginMember(string a, string b);
    void displayAdminInfo(int a);
    bool addAdmin(string a, string b);
    void displayStatistics();
    void displayLibrarianInfo(int a);
    bool addBook(string a, string b, int c);
    void displayAllBooks();
    void searchBooks(string a);
    void displayMembers();
    void displayBorrowRecords();
    int getMemberIdByIndex(int a);
    void displayMemberInfo(int a);
    void displayAvailableBooks();
    bool borrowBook(int a, int b);
    bool returnBook(int a, int b);
    void displayBorrowedBooksForMember(int a);
    
 };