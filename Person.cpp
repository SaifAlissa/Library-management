#include<iostream> // For input/output.
#include<string> // For string handlingl
using namespace std; // Avoid using std::

class Person{

protected:
    static int nextId; // Static variable to give unique id to each person created.
    int id; // to store the unique id of each person.
    string name; // to store the name of the person.
    string password; // to store the password of the person.

public:
    // Default constructor, intializes empty name and password, and assign a unique id to each person using static nextId variable.
    Person(){
        id = nextId++;
        name = "";
        password = "";

    }

    // Parameterized constructor to initialize name and password, and automatically assign a unique id to each person.
    Person(string name, string password){
        id = nextId++;
        this->name = name;
        this->password = password;
    }

    // virtual destructor, to properly cleanup resources when deleting objects of derived classes through a pointer to Person.
    virtual ~Person(){}


    // Getters for Id and Name.
    int getId() const{
        return id;
    }

    string getName() const{
        return name;
    }

    // Function to check if the provided password matches the person's passord.
    bool checkPassword(string password) const{
        return this->password == password;
    }

    // virtual displayinfo function, has to be implemented by other classes that inherit from Person class.
    virtual void displayinfo() const = 0;



    
};
// Initialize the static member variable nextId to 1, ensuring that the first person created will have an id of 1.
int Person::nextId = 1;