#include <iostream>
using namespace std;

// *********************
// Notes on Runtime Polymorphism and Virtual Functions
// *********************

// 1. **Polymorphism**:
//    - The ability of different objects to respond to the same function call in different ways.
//    - In C++, it can be achieved through compile-time (overloading) and runtime (overriding) polymorphism.

// 2. **Runtime Polymorphism**:
//    - Achieved using **virtual functions**.
//    - The function called is determined at runtime based on the actual object type that the pointer/reference points to.

//// 3. **Virtual Functions**:
//    - Declared using the `virtual` keyword in the base class.
//    - Allows derived classes to override the function with their own implementation.
//    - Ensures that the correct function is called for an object, providing different behavior based on the type of object the pointer is pointing to.


// 4. **Impact of Not Using the `virtual` Keyword**:
//    - If a function in the base class is not marked as virtual, the function resolution is done at compile time (early binding).
//    - The function called is determined by the type of the pointer/reference, not the object it points to.
//    - This leads to the base class version of the function being called instead of the derived class version.

// 5. **Pure Virtual Functions**:
//    - Declared by assigning `= 0` in the base class.
//    - Makes the class abstract, preventing instantiation of the base class.
//    - Derived classes must provide an implementation for pure virtual functions to be instantiated.
//    - Useful for defining interfaces.

// 6. **Abstract Class**:
//    - A class containing at least one pure virtual function.
//    - Cannot be instantiated directly.
//    - Serves as a blueprint for derived classes that must implement the pure virtual functions.

// 7. **Example Demonstrating Virtual Functions and Pure Virtual Functions**:

class Base {
public:
    // Virtual function, allows derived classes to override
    virtual void show() {
        cout << "Base Class Show" << endl; // Base class implementation
    }

    // Pure virtual function, makes Base an abstract class
    virtual void info() = 0; // Must be implemented by derived classes

    virtual ~Base() {} // Virtual destructor for proper cleanup
};

class Derived : public Base {
public:
    void show() override { // Override the virtual function
        cout << "Derived Class Show" << endl; // Derived class implementation
    }

    void info() override { // Implementation of the pure virtual function
        cout << "Derived Class Info" << endl; // Derived class implementation
    }
};

// Another derived class
class AnotherDerived : public Base {
public:
    void show() override {
        cout << "Another Derived Class Show" << endl; // Another derived class implementation
    }

    void info() override {
        cout << "Another Derived Class Info" << endl; // Another derived class implementation
    }
};

// Main function to demonstrate runtime polymorphism
int main() {
    Base* basePtr; // Base class pointer

    // Using Derived class object
    basePtr = new Derived();
    basePtr->show(); // Output: Derived Class Show
    basePtr->info(); // Output: Derived Class Info
    delete basePtr; // Cleanup

    // Using AnotherDerived class object
    basePtr = new AnotherDerived();
    basePtr->show(); // Output: Another Derived Class Show
    basePtr->info(); // Output: Another Derived Class Info
    delete basePtr; // Cleanup

    return 0;
}

// *********************
// Summary of Key Concepts
// *********************
// - Use `virtual` to enable dynamic binding for overridden functions.
// - If the `virtual` keyword is not used, the function called is determined at compile time based on the pointer type.
// - Pure virtual functions enforce implementation in derived classes, creating an abstract class.
