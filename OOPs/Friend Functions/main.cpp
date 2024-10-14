#include <iostream>
#include <cmath>

// Important Points about Friend Functions:
// 1. **Access Control**: Friend functions can access private and protected members of the class they are friends with.
// 2. **Not Members**: Friend functions are not member functions of the class. They do not have a `this` pointer.
// 3. **Functionality**: They can be used to perform operations involving multiple classes or to provide customized input/output.
// 4. **Friendship is Not Inherited**: If a class is derived from a base class, the derived class does not inherit friend functions of the base class.
// 5. **Declaration Required**: To make a function a friend, it must be declared in the class that wants to grant access.
// 6. **Multiple Friendships**: A single function can be a friend to multiple classes, and a class can have multiple friend functions.
// 7. **Friend Classes**: Classes can also be declared as friends to allow access to all members, private or protected, of another class.

// This code demonstrates the concept of friend functions and friend classes in C++.
// It includes examples of:
// 1. Overloading the << operator to output the contents of a class.
// 2. Overloading the >> operator to read values into a class.
// 3. Friend functions interacting with multiple classes.
// 4. Friend classes accessing private members of another class.
// 5. Friend functions calculating the distance between two points.
// 6. Friend functions manipulating data in a class.

class Point {
private:
    double x, y;

public:
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Friend function to overload the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    // Friend function to calculate distance between two points
    friend double distance(const Point& p1, const Point& p2);
};

// Definition of the overloaded << operator
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// Definition of the distance function
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle() : width(0), height(0) {}

    // Friend function to overload the >> operator for input
    friend std::istream& operator>>(std::istream& is, Rectangle& r);
};

// Definition of the overloaded >> operator
std::istream& operator>>(std::istream& is, Rectangle& r) {
    std::cout << "Enter width and height: ";
    is >> r.width >> r.height;
    return is;
}

class ClassB; // Forward declaration

class ClassA {
private:
    int valueA;

public:
    ClassA(int val) : valueA(val) {}

    // Friend function that can access private members of ClassA and ClassB
    friend void showValues(ClassA, ClassB);
};

class ClassB {
private:
    int valueB;

public:
    ClassB(int val) : valueB(val) {}

    // Friend function declaration (not needed here as we use the one above)
    friend void showValues(ClassA, ClassB);
};

// Friend function definition
void showValues(ClassA a, ClassB b) {
    std::cout << "ClassA Value: " << a.valueA << ", ClassB Value: " << b.valueB << std::endl;
}

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    // Friend function to add money to the account
    friend void deposit(Account& acc, double amount);
};

// Definition of the deposit function
void deposit(Account& acc, double amount) {
    acc.balance += amount; // Accessing private member
    std::cout << "Deposited: " << amount << ", New Balance: " << acc.balance << std::endl;
}

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    // Friend class declaration
    friend class BoxFriend;
};

class BoxFriend {
public:
    void showWidth(Box b) {
        std::cout << "Width of the box: " << b.width << std::endl; // Accessing private member
    }
};

int main() {
    // Example 1: Using the Point class with overloaded << operator
    Point p1(1.0, 2.0);
    Point p2(4.0, 6.0);
    std::cout << "Point p1: " << p1 << std::endl; // Output: Point p1: (1, 2)

    // Example 2: Calculate distance between two points
    std::cout << "Distance between p1 and p2: " << distance(p1, p2) << std::endl; // Output: Distance: 5

    // Example 3: Using the Rectangle class with overloaded >> operator
    Rectangle rect;
    std::cin >> rect; // User input for width and height

    // Example 4: Using ClassA and ClassB to show values
    ClassA a(10);
    ClassB b(20);
    showValues(a, b); // Output: ClassA Value: 10, ClassB Value: 20

    // Example 5: Using the Account class to deposit money
    Account myAccount(100.0);
    deposit(myAccount, 50.0); // Output: Deposited: 50, New Balance: 150

    // Example 6: Using Box and BoxFriend classes
    Box box(15.5);
    BoxFriend bf;
    bf.showWidth(box); // Output: Width of the box: 15.5

    return 0; // Clean exit
}
