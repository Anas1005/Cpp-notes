#include <iostream>
#include <utility> // For std::move

// Notes:
// This code demonstrates move semantics, value categories, and the use of noexcept
// using a simple IntegerWrapper class. The key concepts covered include:

// 1. **Value Categories:**
//    - **Lvalues**: Expressions that refer to a specific memory location and can be assigned to.
//    - **Rvalues**: Temporary expressions that cannot be assigned to and usually appear on the right side of an assignment.

// 2. **References:**
//    - **Lvalue References (`&`)**: Reference to lvalues, allowing modification.
//    - **Rvalue References (`&&`)**: Reference to rvalues, enabling resource transfers without copying.

// 3. **Copy Semantics:**
//    - **Copy Constructor**: Initializes a new object as a copy of an existing object.
//    - **Copy Assignment Operator**: Copies the value from one object to another existing object, handling self-assignment.

// 4. **Move Semantics:**
//    - **Move Constructor**: Transfers resources from a temporary object (rvalue) to a new object, avoiding copy overhead.
//    - **Move Assignment Operator**: Transfers resources from a temporary object to an existing object.
//    - Move operations leave the moved-from object in a valid state, often nulling pointers or resetting values.

// 5. **std::move()**:
//    - A utility function that casts an lvalue to an rvalue reference, enabling move semantics on lvalues.

// 6. **noexcept Specifier**:
//    - Indicates that a function does not throw exceptions.
//    - Essential for performance optimization in move operations, allowing the compiler to make assumptions about exception safety.
//    - If a move constructor or move assignment operator is marked as noexcept, containers like std::vector can use move semantics more efficiently,
//      leading to better performance by avoiding unnecessary copies.
//    - When a function marked as noexcept does throw, the program will call std::terminate(), leading to an immediate program termination.

// 7.  **Best Practices**:
//     - **When to Use Move Semantics**:
//       * Use move semantics for classes managing resources (e.g., dynamic memory, file handles).
//       * Prefer moving over copying when the object's state is no longer needed after the operation.

//     - **Common Pitfalls**:
//       * Avoid using moved-from objects; they may be in a valid but unspecified state.
//       * Always provide a noexcept specifier for move operations when possible to enable optimizations.







// Example Class: IntegerWrapper
// This class manages a single dynamically allocated integer, showcasing copy and move semantics, and the noexcept specifier.
class IntegerWrapper
{
public:
    int *ptr; // Pointer to an integer

    // Constructor: Allocates memory and initializes the integer.
    IntegerWrapper(int value) : ptr(new int(value))
    {
        std::cout << "Constructor: Created IntegerWrapper with value " << *ptr << std::endl;
    }

    // Copy Constructor: Deep copies the integer value from another IntegerWrapper.
    IntegerWrapper(const IntegerWrapper &other) : ptr(new int(*other.ptr))
    {
        std::cout << "Copy Constructor: Copied IntegerWrapper with value " << *ptr << std::endl;
    }

    // Move Constructor: Transfers ownership of the integer pointer from a temporary IntegerWrapper.
    IntegerWrapper(IntegerWrapper &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr; // Leave the other object in a valid state
        std::cout << "Move Constructor: Moved IntegerWrapper with value " << *ptr << std::endl;
    }

    // Copy Assignment Operator: Handles copying values and self-assignment, freeing old resources.
    IntegerWrapper &operator=(const IntegerWrapper &other)
    {
        std::cout << "Copy Assignment: Copying IntegerWrapper with value " << *other.ptr << std::endl;
        if (this != &other)
        {                              // Avoid self-assignment
            delete ptr;                // Free existing resource
            ptr = new int(*other.ptr); // Allocate new memory and copy value
        }
        return *this;
    }

    // Move Assignment Operator: Transfers resources from a temporary IntegerWrapper.
    IntegerWrapper &operator=(IntegerWrapper &&other) noexcept
    {
        std::cout << "Move Assignment: Moving IntegerWrapper with value " << *other.ptr << std::endl;
        if (this != &other)
        {                        // Avoid self-assignment
            delete ptr;          // Free existing resource
            ptr = other.ptr;     // Transfer ownership
            other.ptr = nullptr; // Leave the other object in a valid state
        }
        return *this;
    }

    // Destructor: Cleans up allocated memory.
    ~IntegerWrapper()
    {
        delete ptr; // Free the allocated memory
        std::cout << "Destructor: Deleted IntegerWrapper" << std::endl;
    }

    // Function to get the value stored in the wrapper.
    int getValue() const
    {
        return *ptr;
    }
};

// Practical example
int main()
{
    IntegerWrapper a(42);            // Regular construction
    IntegerWrapper b = a;            // Copy construction
    IntegerWrapper c = std::move(a); // Move construction
    b = c;                           // Copy assignment
    b = std::move(c);                // Move assignment

    std::cout << "Value of b: " << b.getValue() << std::endl;

    return 0;
}
