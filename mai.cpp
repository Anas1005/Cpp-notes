#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called\n";
    }
    ~MyClass() {
        std::cout << "Destructor called\n";
    }
};

int main() {
    // Dynamically allocate memory for MyClass
    MyClass obj;
    // If we forget to delete, the destructor will NOT be called
    // delete obj; // Uncommenting this line will call the destructor

    // The program ends here
    return 0;
}
