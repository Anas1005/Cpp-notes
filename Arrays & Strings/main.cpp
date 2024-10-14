#include <iostream>
#include <string>
using namespace std;

int main() {
    // ===========================
    // 1. Arrays in C++
    // ===========================

    // An array is a collection of elements of the same data type stored in contiguous memory locations.
    // Syntax: dataType arrayName[arraySize];
    
    // a. Declaration and Initialization
    int numbers[5]; // Declares an array of integers with 5 elements (default values are undefined)
    int evenNumbers[5] = {2, 4, 6, 8, 10}; // Declares and initializes an array with specific values

    // Accessing array elements:
    // Array elements are accessed using an index starting from 0.
    cout << "First element: " << evenNumbers[0] << endl; // Access the first element (index 0)
    cout << "Last element: " << evenNumbers[4] << endl; // Access the last element (index 4)

    // Modifying array elements:
    numbers[0] = 1; // Assigns value to the first element
    numbers[1] = 3; // Assigns value to the second element

    // b. Array Iteration (Looping through arrays)
    cout << "\nIterating through evenNumbers array:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Element at index " << i << ": " << evenNumbers[i] << endl;
    }

    // c. Multidimensional Arrays (2D Arrays)
    // Syntax: dataType arrayName[rows][columns];
    int matrix[2][3] = {
        {1, 2, 3}, 
        {4, 5, 6}
    }; // 2x3 matrix (2 rows, 3 columns)

    // Accessing elements in a 2D array:
    cout << "\nAccessing elements of 2D array (matrix):\n";
    cout << "Element at [0][1]: " << matrix[0][1] << endl; // Accesses the element in the first row and second column (value 2)
    cout << "Element at [1][2]: " << matrix[1][2] << endl; // Accesses the element in the second row and third column (value 6)

    // Iterating through a 2D array:
    cout << "\nIterating through the 2D array (matrix):\n";
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "Element at [" << row << "][" << col << "]: " << matrix[row][col] << " ";
        }
        cout << endl;
    }

    // ===========================
    // 2. Strings in C++
    // ===========================

    // A string is a sequence of characters used to represent text.
    // Strings in C++ can be created using character arrays or the string class (preferred).

    // a. Character Array (C-style strings)
    char cString[] = "Hello"; // Null-terminated character array (C-style string)

    // Accessing elements in a C-style string:
    cout << "\nFirst character of cString: " << cString[0] << endl; // Accesses 'H'
    cout << "Last character of cString: " << cString[4] << endl; // Accesses 'o'

    // Modifying elements in a C-style string:
    cString[0] = 'h'; // Modifies the first character
    cout << "Modified cString: " << cString << endl;

    // b. C++ String Class
    string cppString = "Welcome to C++"; // Declares a C++ string

    // String operations:
    cout << "\nString length: " << cppString.length() << endl; // Outputs the length of the string
    cout << "Substring (0, 7): " << cppString.substr(0, 7) << endl; // Extracts a substring (from index 0 to 6)
    cout << "Character at index 3: " << cppString.at(3) << endl; // Accesses a character at a specific position ('c')

    // Concatenation
    string greeting = "Hello";
    string name = "John";
    string fullGreeting = greeting + ", " + name + "!"; // Concatenates strings
    cout << "\nConcatenated String: " << fullGreeting << endl; // Outputs: Hello, John!

    // Comparing strings
    string str1 = "apple";
    string str2 = "orange";
    if (str1 < str2) { // Compares lexicographically
        cout << "apple comes before orange" << endl;
    }

    // c. Modifying Strings
    cppString[0] = 'w'; // Modifies the first character of the string
    cout << "Modified cppString: " << cppString << endl;

    // ===========================
    // 3. Arrays of Strings
    // ===========================

    // Array of strings using the string class:
    string fruits[3] = {"Apple", "Banana", "Cherry"}; // Declares an array of strings

    // Iterating through the array of strings:
    cout << "\nIterating through the array of strings (fruits):\n";
    for (int i = 0; i < 3; i++) {
        cout << "Fruit " << i + 1 << ": " << fruits[i] << endl;
    }

    // ===========================
    // 4. Common String Functions
    // ===========================

    // a. Finding substrings
    size_t found = cppString.find("to"); // Searches for the substring "to"
    if (found != string::npos) {
        cout << "\nSubstring 'to' found at index: " << found << endl;
    }

    // b. Replacing substrings
    cppString.replace(cppString.find("Welcome"), 7, "Hello"); // Replaces "Welcome" with "Hello"
    cout << "Modified cppString: " << cppString << endl;

    // c. Inserting into strings
    cppString.insert(5, " everyone"); // Inserts " everyone" at index 5
    cout << "Inserted text: " << cppString << endl;

    // d. Erasing part of the string
    cppString.erase(5, 9); // Erases 9 characters starting from index 5
    cout << "After erasing: " << cppString << endl;

    // e. Clearing a string
    cppString.clear(); // Clears the entire string content
    cout << "\nAfter clearing, length of cppString: " << cppString.length() << endl;

    return 0; // End of the program
}
