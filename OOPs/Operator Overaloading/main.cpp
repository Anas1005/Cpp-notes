#include <iostream>
#include <cstring>

using namespace std;

/*
    Operator Overloading in C++:

    1. **What is Operator Overloading?**
        - Operator overloading allows C++ operators to be redefined and used in different ways depending on the operand types.
        - It enhances the readability and usability of the code by allowing operators to work with user-defined types (classes).

    2. **Types of Operators that can be Overloaded:**
        - **Arithmetic Operators:** +, -, *, /, %
        - **Relational Operators:** ==, !=, <, >, <=, >=
        - **Logical Operators:** &&, ||, !
        - **Bitwise Operators:** &, |, ^, ~, <<, >>
        - **Assignment Operators:** =, +=, -=, *=, /=
        - **Increment/Decrement Operators:** ++, --
        - **Input/Output Operators:** <<, >>
        - **Indexing Operators:** []
        - **Function Call Operator:** ()
        - **Pointer Operators:** *, ->

    3. **Key Points:**
        - Operator overloading is performed by defining a function in the class with a special name.
        - You cannot change the precedence or associativity of operators.
        - Some operators cannot be overloaded (e.g., . , :: , .* , ?:).
        - Operator overloading can be done through member functions or friend functions.
        - Overloaded operators can also handle pointers and references.

          1. **When to use Member Functions:**
        - Use member functions to overload operators when:
            - The operator is naturally associated with the class.
            - The left operand is of the class type.
            - You don't need to access private or protected members of another class.

         2. **When to use Non-Member (Friend) Functions:**
            - Use non-member functions (friend functions) to overload operators when:
            - The left operand is not of the class type (e.g., when overloading operators for mixed-type operations).
            - You need to access private or protected members of other classes.
            - The operator’s functionality is more intuitive when defined outside the class.

*/

class Complex
{
private:
    double real; // Real part
    double imag; // Imaginary part

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    void display()
    {
        cout << *this << endl;
    }

    // Arithmetic Operator (Member Function)
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag); // Addition
    }

    // Relational Operator (Member Function)
    bool operator==(const Complex &other) const
    {
        return (real == other.real && imag == other.imag); // Equality
    }

    // Assignment Operator (Member Function)
    Complex& operator=(const Complex &other)
    {
        if (this != &other)
        {
            real = other.real; // Assignment
            imag = other.imag;
        }
        return *this;
    }

    // Increment Operator (Member Function)
    Complex& operator++()
    { // Prefix Increment
        ++real;
        return *this;
    }

    // Function Call Operator (Member Function)
    double operator()(int index)
    {
        if (index == 0)
            return real; // Return real part
        else if (index == 1)
            return imag;                          // Return imaginary part
        throw out_of_range("Index out of range"); // Handle invalid index
    }

    // Pointer Dereference Operator (Member Function)
    double& operator*()
    {
        return real; // Dereference to real part
    }

    // Pointer Member Operator (Non-Member Function)
    Complex* operator->()
    {
        return this; // Pointer to real part
    }

    // Logical Operator (Non-Member Function)
    friend bool operator&&(const Complex& c1, const Complex& c2)
    {
        return (c1.real != 0 && c1.imag != 0) && (c2.real != 0 && c2.imag != 0); // Logical AND
    }

    // Input Operator (Non-Member Function)
    friend istream& operator>>(istream& is, Complex& c)
    {
        is >> c.real >> c.imag; // Input
        return is;
    }

    // Output Operator (Non-Member Function)
    friend ostream& operator<<(ostream& os, const Complex& c)
    {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i"; // Output
        return os;
    }
};

int main()
{
    Complex c1(3, 4);
    Complex c2(1, 2);

    // Testing Arithmetic Operator
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    // Testing Logical Operator
    cout << "c1 && c2: " << (c1 && c2) << endl; // Logical AND

    // Testing Relational Operator
    cout << "c1 == c2: " << (c1 == c2) << endl; // Equality Check

    // Testing Assignment Operator
    c1 = c2;
    cout << "After assignment, c1 = " << c1 << endl;

    // Testing Increment Operator
    ++c1;
    cout << "After increment, c1 = " << c1 << endl;

    // Input using overloaded '>>'
    Complex c4;
    cout << "Enter a complex number (real and imaginary parts): ";
    cin >> c4;
    cout << "You entered: " << c4 << endl;

    // Output using overloaded '<<'
    cout << "Output of c4: " << c4 << endl;

    // Function Call Operator
    cout << "Real part of c4: " << c4(0) << endl;
    cout << "Imaginary part of c4: " << c4(1) << endl;

    // Pointer Dereference Operator
    cout << "Dereferenced value (real part): " << *c4 << endl; // Dereference to get real part

    // Pointer Member Operator
    c4->display(); // Accessing member through pointer operator..although c4 is not a pointer variable.

    return 0;
}