#include <iostream>
#include <string>

using namespace std;

int main() {
    // ===========================
    // 1. Variables in C++
    // ===========================

    // A variable is a named storage location in memory.
    // Syntax for declaring a variable:
    // dataType variableName;

    int age; // Declare an integer variable named 'age'

    // Initialization: Assign a value to the variable at the time of declaration
    age = 25; // Initialize 'age' to 25

    // Variables can change value during execution
    age = 30; // Update 'age' to 30

    // ===========================
    // 2. Data Types in C++
    // ===========================

    // Basic Data Types:
    
    // Integer Types
    int count = 10; // 'int' for whole numbers
    short smallNumber = 5; // 'short' for smaller integers
    long bigNumber = 100000L; // 'long' for larger integers
    long long veryBigNumber = 10000000000LL; // 'long long' for very large integers

    // Floating Point Types
    float height = 5.9f; // 'float' for single-precision numbers
    double pi = 3.14159; // 'double' for double-precision numbers
    long double preciseValue = 2.718281828459045L; // 'long double' for extended precision

    // Character Type
    char grade = 'A'; // 'char' for a single character

    // String Type
    string name = "Alice"; // 'string' for a sequence of characters (text)

    // Type Modifiers:
    unsigned int positiveCount = 100; // 'unsigned' can only hold non-negative values

    // ===========================
    // 3. Constants in C++
    // ===========================

    // A constant is a fixed value that cannot be altered during execution.
    const int MAX_AGE = 120; // 'const' keyword used to declare a constant
    
    // Importance of Constants:
    // - Enhances code readability and maintainability
    // - Prevents accidental changes to fixed values

    // Preprocessor Constants:
    #define PI 3.14159 // PI defined as a preprocessor constant

    // ===========================
    // 4. Operators in C++
    // ===========================

    // a. Arithmetic Operators
    int a = 10;
    int b = 3;

    // Addition
    int sum = a + b; // 10 + 3 = 13

    // Subtraction
    int difference = a - b; // 10 - 3 = 7

    // Multiplication
    int product = a * b; // 10 * 3 = 30

    // Division
    double quotient = static_cast<double>(a) / b; // 10 / 3 = 3.3333 (using static_cast for double)

    // Modulus
    int remainder = a % b; // 10 % 3 = 1

    // b. Relational Operators
    bool isEqual = (a == b); // Equal to: false
    bool isNotEqual = (a != b); // Not equal to: true
    bool isGreater = (a > b); // Greater than: true
    bool isLess = (a < b); // Less than: false
    bool isGreaterOrEqual = (a >= b); // Greater than or equal to: true
    bool isLessOrEqual = (a <= b); // Less than or equal to: false

    // c. Logical Operators
    bool logicalAnd = (a > 5 && b < 5); // true and false = false
    bool logicalOr = (a > 5 || b < 5); // true or false = true
    bool logicalNot = !(a > 5); // Not true = false

    // d. Bitwise Operators
    int x = 5; // 0101 in binary
    int y = 3; // 0011 in binary

    int bitwiseAnd = x & y; // 0001 (1 in decimal)
    int bitwiseOr = x | y; // 0111 (7 in decimal)
    int bitwiseXor = x ^ y; // 0110 (6 in decimal)
    int bitwiseNot = ~x; // Inverts the bits

    // ===========================
    // 5. Control Structures (Loops)
    // ===========================

    // a. For Loop
    cout << "\nFor Loop Example: Counting from 1 to 5\n";
    for (int i = 1; i <= 5; i++) { // Loop runs from 1 to 5
        cout << "Count: " << i << endl; // Output the count
    }

    // b. While Loop
    cout << "\nWhile Loop Example: Counting down from 5 to 1\n";
    int countDown = 5;
    while (countDown > 0) {
        cout << "Count: " << countDown << endl; // Output the count
        countDown--; // Decrement the counter
    }

    // c. Do-While Loop
    cout << "\nDo-While Loop Example: Counting from 1 to 3\n";
    int doCount = 1;
    do {
        cout << "Count: " << doCount << endl; // Output the count
        doCount++; // Increment the counter
    } while (doCount <= 3); // Loop runs until doCount is greater than 3

    // ===========================
    // 6. Type Casting in C++
    // ===========================

    // Type casting is converting one data type to another.
    
    // a. Implicit Casting (Automatic)
    int intValue = 10;
    double doubleValue = intValue; // Automatically converts int to double

    // b. Explicit Casting
    double originalValue = 9.99;
    int convertedValue = static_cast<int>(originalValue); // Converts double to int, truncating the decimal part

    // ===========================
    // 7. Type Conversion in C++
    // ===========================

    // Type conversion involves converting between types.
    
    // a. Using static_cast
    float floatValue = 2.5f;
    int intFromFloat = static_cast<int>(floatValue); // Converts float to int

    // b. Using C-style cast
    char charValue = 'A';
    int intFromChar = (int)charValue; // Converts char to int (ASCII value)

    // Example Usage
    cout << "\nExample of Type Casting and Conversion\n";
    cout << "Original integer: " << intValue << ", converted to double: " << doubleValue << endl;
    cout << "Original double: " << originalValue << ", converted to int: " << convertedValue << endl;
    cout << "Original float: " << floatValue << ", converted to int: " << intFromFloat << endl;
    cout << "Original char: " << charValue << ", converted to int (ASCII): " << intFromChar << endl;

    // ===========================
    // 8. Structures in C++
    // ===========================

    // A structure is a user-defined data type that groups related variables.
    
    struct Person { // Define a structure named 'Person'
        string name; // Name of the person
        int age; // Age of the person
        float height; // Height of the person
    };

    Person person1; // Create an instance of 'Person'
    person1.name = "Alice"; // Assign values to the instance
    person1.age = 30;
    person1.height = 5.5f;

    cout << "\nPerson Structure:\n";
    cout << "Name: " << person1.name << ", Age: " << person1.age << ", Height: " << person1.height << " ft\n";

    // ===========================
    // 9. Unions in C++
    // ===========================

    // A union is a user-defined data type that allows storing different data types in the same memory location.
    
    union Data { // Define a union named 'Data'
        int intValue; // Integer value
        float floatValue; // Float value
        char charValue; // Character value
    };

    Data data; // Create an instance of 'Data'
    data.intValue = 10; // Assign an integer value to the union
    cout << "\nUnion Data (intValue): " << data.intValue << endl; // Accessing intValue

    // Assigning another type to the union will overwrite the previous value
    data.floatValue = 3.14f; // Now floatValue is set
    cout << "Union Data (floatValue): " << data.floatValue << endl; // Accessing floatValue
    // Accessing intValue after assigning floatValue will show garbage value
    cout << "Union Data (intValue after floatValue): " << data.intValue << endl;

    // ===========================
    // 10. Enums in C++
    // ===========================

    // An enum (enumeration) is a user-defined data type that consists of integral constants.
    
    enum Color { // Define an enum named 'Color'
        RED, // 0
        GREEN, // 1
        BLUE // 2
    };

    Color myColor = GREEN; // Assign a value from the enum
    cout << "\nSelected Color Enum: " << myColor << endl; // Outputs the integer value associated with GREEN

    return 0; // End of the program
}
