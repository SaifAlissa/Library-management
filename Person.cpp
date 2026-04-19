#include<iostream> // For input/output.
#include<string> // For string handlingl
using namespace std; // Avoid using std::

class Person{

protected:
    int id; // to store the unique id of each person.
    string name; // to store the name of the person.
    string password; // to store the password of the person.

public:
    // Default constructor, intializes empty name and password, and assign a unique id to each person using static nextId variable.
    Person(){
        id = 0;
        name = "";
        password = "";

    }

    // Parameterized constructor to initialize name and password, and automatically assign a unique id to each person.
    Person(int personId, string personName, string personPassword){
        id = personId;
        this->name = personName;
        this->password = personPassword;
    }

    // Getters for Id and Name.
    int getId() const{
        return id;
    }

    string getName() const{
        return name;
    }

    string getPassword() const{
        return password;
    }

    void setName(string newName){
        name = newName;
    }

    void setPassword(string newPassword){
        password = newPassword;
    }

    void displayInfo() const{
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }



    
};