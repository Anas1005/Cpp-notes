#include <iostream>
#include <string>
using namespace std;

/*
    ============================================
    Object-Oriented Programming (OOP) Concepts
    ============================================

    1. Classes and Objects:
       - A class is a blueprint for creating objects, which are instances of the class.
       - Each object has its own copy of the data members and methods defined in the class.

    2. Access Modifiers:
       - Access modifiers control the visibility of class members.
       - 'private': Only accessible within the class.
       - 'public': Accessible outside the class.
       - 'protected': Accessible in derived classes (not shown here).

    3. Constructors:
       - Default Constructor: Provided by C++ if no other constructor is defined. Initializes objects with default values.
       - Parameterized Constructor: Allows initialization of objects with user-defined values.
       - Copy Constructor: Creates a new object as a copy of an existing object. 
       - If no copy constructor is provided, C++ automatically supplies a default one, which performs a shallow copy.

    4. Destructors:
       - A special function called when an object goes out of scope or is deleted.
       - Used for cleanup tasks such as releasing memory. It has no parameters and no return type.

    5. Static Members:
       - Static variables belong to the class, not to any object instance.
       - Static methods can access static variables but not non-static members directly.
*/

class Employee {
private:
    string name;
    int age;
    double salary;

    // Static member variable to keep track of the number of employees
    static int employeeCount;

public:
    // Default constructor
    Employee() {
        name = "Unknown";
        age = 0;
        salary = 0.0;
        employeeCount++; // Increment employee count when an object is created
    }

    // Parameterized constructor
    Employee(string empName, int empAge, double empSalary) {
        name = empName;
        age = empAge;
        salary = empSalary;
        employeeCount++;
    }

    // Copy constructor
    Employee(const Employee &other) {
        // Copy all data from the other object to this object
        name = other.name;
        age = other.age;
        salary = other.salary;
        employeeCount++;
        // Note: Copy constructors perform a shallow copy unless you implement a deep copy (for dynamic memory).
    }

    // Destructor
    ~Employee() {
        employeeCount--; // Decrement employee count when an object is destroyed
        // Destructors are useful for cleaning up resources like memory (if dynamically allocated).
    }

    // Static function to get the total number of Employee objects
    static int getEmployeeCount() {
        return employeeCount;
    }

    // Function to display employee details
    void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", Salary: " << salary << endl;
    }

    // Function to set employee details (example of public setter method)
    void setDetails(string empName, int empAge, double empSalary) {
        name = empName;
        age = empAge;
        salary = empSalary;
    }
};

// Definition and initialization of static member outside the class
int Employee::employeeCount = 0;

int main() {
    // Creating objects using the default constructor
    Employee emp1;
    emp1.displayDetails();

    // Creating objects using the parameterized constructor
    Employee emp2("Alice", 30, 75000.0);
    emp2.displayDetails();

    // Using the copy constructor
    Employee emp3 = emp2; // emp3 is a copy of emp2
    emp3.displayDetails();

    // Displaying the count of employee objects (using the static function)
    cout << "Total Employees: " << Employee::getEmployeeCount() << endl;

    {
        // Creating another object inside a block scope to test destructor
        Employee emp4("Bob", 25, 55000.0);
        emp4.displayDetails();
        cout << "Total Employees (inside block): " << Employee::getEmployeeCount() << endl;
    } // emp4 goes out of scope and its destructor is called

    // Final employee count after emp4 is destroyed
    cout << "Total Employees (after block): " << Employee::getEmployeeCount() << endl;

    return 0;
}
