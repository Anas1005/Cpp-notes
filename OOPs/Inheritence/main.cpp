#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Types of Inheritance
// Inheritance allows a class (derived class) to inherit the attributes and methods of another class (base class).
// There are different types of inheritance in C++:

// a. Single Inheritance: A derived class inherits from a single base class.
class Vehicle {
public:
    string brand;
    int year;

    Vehicle(string b, int y) : brand(b), year(y) {} // Constructor

    void displayInfo() {
        cout << "Vehicle Brand: " << brand << ", Year: " << year << endl;
    }
};

class Car : public Vehicle { // Car inherits from Vehicle
public:
    int doors;

    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {} // Constructor

    void displayCarInfo() {
        displayInfo(); // Call base class method
        cout << "Number of doors: " << doors << endl;
    }
};

// b. Multiple Inheritance: A derived class inherits from multiple base classes.
class Engine {
public:
    string type;

    Engine(string t) : type(t) {} // Constructor
};

// Derived class inherits from both Vehicle and Engine
class Truck : public Vehicle, public Engine {
public:
    int loadCapacity;

    Truck(string b, int y, string t, int lc)
        : Vehicle(b, y), Engine(t), loadCapacity(lc) {} // Constructor

    void displayTruckInfo() {
        displayInfo(); // Call base class method
        cout << "Engine Type: " << type << ", Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

// c. Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
class Motorcycle : public Vehicle { // Motorcycle also inherits from Vehicle
public:
    bool hasSidecar;

    Motorcycle(string b, int y, bool hs)
        : Vehicle(b, y), hasSidecar(hs) {} // Constructor

    void displayMotorcycleInfo() {
        displayInfo(); // Call base class method
        cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
};

// d. Multilevel Inheritance: A derived class inherits from another derived class.
class SportsCar : public Car { // SportsCar inherits from Car
public:
    int maxSpeed;

    SportsCar(string b, int y, int d, int ms)
        : Car(b, y, d), maxSpeed(ms) {} // Constructor

    void displaySportsCarInfo() {
        displayCarInfo(); // Call base class method
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    }
};

// e. Hybrid Inheritance: A combination of two or more types of inheritance.

class Base {
public:
    void display() {
        cout << "Base class display function." << endl;
    }
};

// Derived classes
class Derived1 : public Base {};
class Derived2 : public Base {};
class Hybrid : public Derived1, public Derived2 {};

// 2. Visibility Modes
// The access specifiers in C++ determine how members of a class can be accessed.
// The following table summarizes the member access in inheritance:

// | Member Access | Public Inheritance | Protected Inheritance | Private Inheritance |
// |---------------|-------------------|-----------------------|---------------------|
// | public        | public            | protected              | private              |
// | protected     | protected         | protected              | private              |
// | private       | inaccessible      | inaccessible          | inaccessible         |

// 3. Scope Resolution Operator in Multiple Inheritance
// When derived classes have functions with the same name, we can use the scope resolution operator (::)
// to specify which base class function to call.

class BaseA {
public:
    void show() {
        cout << "Show from BaseA" << endl;
    }
};

class BaseB {
public:
    void show() {
        cout << "Show from BaseB" << endl;
    }
};

class Derived : public BaseA, public BaseB {
public:
    void show() {
        BaseA::show(); // Calls show from BaseA
        BaseB::show(); // Calls show from BaseB
    }
};

// 4. Diamond Problem
// The diamond problem occurs in multiple inheritance when two classes inherit from the same base class,
// and a third class inherits from both of them. This can cause ambiguity in method resolution.
// Virtual inheritance solves this issue by ensuring that only one instance of the base class is used.

class A {
public:
    void display() {
        cout << "Display from A" << endl;
    }
};

// Using virtual inheritance to solve the diamond problem
class B : virtual public A {}; // B inherits from A
class C : virtual public A {}; // C inherits from A

class D : public B, public C { // D inherits from both B and C
public:
    void show() {
        display(); // No ambiguity, calls A's display
    }
};


// 5. Static Members in Inheritance
// Static members are shared among all instances of a class and can be accessed without creating an instance.
// They can be inherited by derived classes.

class StaticBase {
public:
    static int staticValue; // Static member

    StaticBase() {
        staticValue++;
    }
};

// Initialize the static member outside the class
int StaticBase::staticValue = 0;

class StaticDerived : public StaticBase {
public:
    static void displayStaticValue() {
        cout << "Static Value: " << staticValue << endl; // Accessing static member
    }
};

int main() {
    // 1. Types of Inheritance
    cout << "Single Inheritance:" << endl;
    Car myCar("Toyota", 2022, 4);
    myCar.displayCarInfo();

    cout << "\nMultiple Inheritance:" << endl;
    Truck myTruck("Ford", 2023, "Diesel", 10);
    myTruck.displayTruckInfo();

    cout << "\nHierarchical Inheritance:" << endl;
    Motorcycle myBike("Yamaha", 2021, false);
    myBike.displayMotorcycleInfo();

    cout << "\nMultilevel Inheritance:" << endl;
    SportsCar mySportsCar("Ferrari", 2024, 2, 350);
    mySportsCar.displaySportsCarInfo();

    cout << "\nScope Resolution Operator in Multiple Inheritance:" << endl;
    Derived d;
    // d.show();

    cout << "\nDiamond Problem:" << endl;
    D dObj;
    dObj.show();


    cout << "\nStatic Members in Inheritance:" << endl;
    StaticDerived::displayStaticValue();

    return 0;
}


//New, Delete, Arrow Operarors..

#include <iostream>
#include <string>

using namespace std;

// Class definition for Person
class Person {
public:
    string name; // Member variable to store the person's name
    int age;     // Member variable to store the person's age

    // Constructor to initialize a Person object
    Person(string n, int a) : name(n), age(a) {}
};

int main() {
    // Array of pointers to Person objects
    Person* people[3];



    // Dynamically creating Person objects and assigning them to the array
    people[0] = new Person("Alice", 25);  // Allocate memory for Alice
    people[1] = new Person("Bob", 30);    // Allocate memory for Bob
    people[2] = new Person("Charlie", 22); // Allocate memory for Charlie

    // Accessing members of each Person object using pointers and the arrow operator
    for (int i = 0; i < 3; ++i) {
        cout << "Name: " << people[i]->name << ", Age: " << people[i]->age << endl; // Using -> to access members
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < 3; ++i) {
        delete people[i]; // Deallocate memory for each Person object
    }

    return 0; // Return 0 to indicate successful execution
}
