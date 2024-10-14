/*
    Exception Handling in C++ - Comprehensive Overview

    1. **What is Exception Handling?**
       Exception handling in C++ allows us to manage and respond to runtime errors gracefully.
       Instead of crashing, exceptions provide a controlled mechanism to catch and manage errors.

    2. **Key Keywords:**
       - `try`: Defines a block of code to be tested for errors during execution.
       - `catch`: Defines a block of code to handle the error if an exception occurs in the try block.
       - `throw`: Signals an exception and transfers control to the nearest catch block.

    3. **Types of Exceptions:**
       - **Standard Exceptions** (from `<stdexcept>`):
         - `std::exception`: The base class for all exceptions.
         - `std::logic_error`: Errors related to program logic (e.g., `std::invalid_argument`, `std::out_of_range`).
         - `std::runtime_error`: Errors that occur during program execution (e.g., `std::overflow_error`, `std::underflow_error`).
         - `std::bad_alloc`: Memory allocation failure.
         - `std::bad_cast`: Failure of `dynamic_cast`.
       - **Custom Exceptions**: Derived from `std::exception` or other standard exceptions.

    4. **Finally Block Equivalent:**
       - C++ does not have a built-in `finally` block. Instead, RAII (Resource Acquisition Is Initialization) is used to manage resources. 
       - Objects with destructors are used to perform cleanup automatically when they go out of scope, ensuring resources are released, similar to a `finally` block.

    5. **noexcept:**
       - The `noexcept` specifier indicates whether a function is guaranteed not to throw any exceptions.
       - It improves performance because it allows the compiler to make optimizations knowing the function will not throw.
       - A function marked as `noexcept` that throws an exception will call `std::terminate()` and terminate the program.
       - You can also use `noexcept(false)` to indicate that a function may throw, but this is not common as it is the default behavior.

    6. **Example:**
       This example demonstrates standard and custom exceptions, a way to simulate a `finally` block using RAII, 
       and the use of `noexcept` for optimizing functions that are guaranteed not to throw exceptions.

*/

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Custom exception class inheriting from std::exception
class MyCustomException : public exception {
public:
    MyCustomException(const string& message) : msg_(message) {}

    // Override the what() function to provide an error message
    const char* what() const noexcept override {
        return msg_.c_str();
    }

private:
    string msg_;
};

// RAII class that simulates a "finally" block using its destructor
class ResourceGuard {
public:
    ResourceGuard() { cout << "Resource acquired." << endl; }
    ~ResourceGuard() { cout << "Resource released (simulating finally block)." << endl; }
};

// A function guaranteed not to throw any exceptions (noexcept)
void safeOperation() noexcept {
    cout << "This operation is guaranteed not to throw an exception." << endl;
}

// Function that demonstrates various exceptions
void processData(int value) {
    ResourceGuard guard; // This object ensures resource cleanup when the function exits, simulating "finally"

    if (value < 0) {
        throw invalid_argument("Negative value is not allowed."); // Standard exception
    } else if (value == 0) {
        throw MyCustomException("Zero is not permitted."); // Custom exception
    } else if (value > 100) {
        throw overflow_error("Value exceeds the allowable range."); // Runtime error
    }

    // Simulate a memory allocation error
    if (value == 99) {
        throw bad_alloc(); // Simulating a memory allocation failure
    }

    // Display the value if everything is correct
    cout << "Value is valid: " << value << endl;
}

int main() {
    try {
        processData(-1); // This will throw std::invalid_argument
    } catch (const invalid_argument& e) {
        cerr << "Caught a logic error (invalid_argument): " << e.what() << endl;
    }

    try {
        processData(0); // This will throw MyCustomException
    } catch (const MyCustomException& e) {
        cerr << "Caught a custom exception: " << e.what() << endl;
    }

    try {
        processData(101); // This will throw overflow_error
    } catch (const overflow_error& e) {
        cerr << "Caught a runtime error (overflow_error): " << e.what() << endl;
    }

    try {
        processData(99); // This will throw bad_alloc
    } catch (const bad_alloc& e) {
        cerr << "Caught a memory allocation error (bad_alloc): " << e.what() << endl;
    }

    // General catch-all for any other std::exception types
    try {
        processData(10); // Valid case
    } catch (const exception& e) {
        cerr << "Caught a general exception: " << e.what() << endl;
    }

    // Catch all unexpected exceptions
    try {
        processData(50); // Valid case, won't throw any exception
        processData(999); // This will throw overflow_error
    } catch (...) { 
        cerr << "Caught an unexpected exception." << endl;
    }

    // Demonstrate the noexcept function
    try {
        safeOperation(); // Guaranteed not to throw
    } catch (...) {
        cerr << "This block will never be executed as safeOperation() is noexcept." << endl;
    }

    return 0;
}

/*
    Detailed Explanation:

    - **RAII Simulation for Finally Block**:
        - The `ResourceGuard` class is used to simulate a `finally` block. It acquires a resource in its 
          constructor and releases it in its destructor. This ensures that when the function `processData` exits 
          (either normally or due to an exception), the destructor is called, simulating the behavior of a `finally` 
          block.
    
    - **Exception Handling Demonstrated**:
        - `processData` function shows different scenarios where exceptions are thrown:
            - `std::invalid_argument` for negative values.
            - `MyCustomException` for zero values.
            - `std::overflow_error` for values greater than 100.
            - `std::bad_alloc` for value 99, simulating a memory allocation failure.

    - **Catching Exceptions**:
        - Specific exceptions are caught using their respective catch blocks (`invalid_argument`, `MyCustomException`, etc.).
        - A general `catch (const exception& e)` block handles any other standard exceptions.
        - A catch-all `catch (...)` block is included as a safety net for any unforeseen exceptions.


    - **noexcept Usage**:
        - The `safeOperation` function is declared with `noexcept`, indicating it will not throw any exceptions.
        - If a `noexcept` function throws, it results in a call to `std::terminate()`, stopping the program.
        - Marking functions as `noexcept` where applicable helps with performance optimization and safety assurance.

    This code provides a detailed demonstration of exception handling, including standard, custom exceptions, 
    resource management using RAII, and the use of `noexcept` to enhance performance and safety.
*/
