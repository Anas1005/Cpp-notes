#include <iostream>
#include <string>
using namespace std;

/*
Notes about Passing by Value and Passing by Reference in C++:

1. **Default Behavior**:
   - In C++, all arguments are passed by value by default, whether they are primitives, objects, or arrays.
   - When passing by value, a copy of the argument is created, so modifications inside the function do not affect the original variable.

2. **Primitive Types**:
   - Primitives like `int`, `char`, and `double` are passed by value by default. Any modification to these inside the function does not affect the original variable.

3. **Objects**:
   - Objects (instances of classes) are also passed by value by default. This means a copy of the object is created when passed, and changes within the function do not affect the original object.

4. **Arrays**:
   - Arrays are a special case. When an array is passed, it decays to a pointer, and the pointer itself is passed by value.
   - Modifying the elements of the array inside the function affects the original array, but the pointer’s address itself is a copy, meaning the array's base address is not modified.

5. **Passing by Reference**:
   - To modify the original argument, use the `&` symbol (reference) when declaring the parameter in the function. This passes the original variable itself, not a copy.

6. **Pointers**:
   - Pointers are variables that hold memory addresses. Pointers themselves can be passed by value or by reference, and they are useful for dynamic memory management or modifying original data when passed as arguments.

*/

/*
Additional Notes about Concepts Used:

1. Pointers:
   - Pointers are variables that hold memory addresses. They are useful for dynamically managing memory and manipulating data.
   - In this code, we use pointers to find the maximum element in an array and perform operations on it.

2. References:
   - References allow you to create an alias for an existing variable, enabling direct manipulation without copying the variable.
   - The function reverseString demonstrates how to modify a string by passing it as a reference.

3. Returning References:
   - Functions can return references, enabling modification of the original variable from the caller's context.
   - The function accessElement showcases returning a reference to an array element.

4. Const References:
   - Using const references helps prevent modification of the argument while still allowing efficient access to the data.
   - The processLargeArray function uses const reference for a large array to avoid unnecessary copying.

5. Inline Functions:
   - Inline functions are suggested to the compiler for optimization by replacing calls with the actual function code.
   - The calculateArea function is defined as inline for computing the area of a circle efficiently.

6. Default Parameters:
   - Functions can have default values for parameters, which are used if no arguments are passed during the function call.
   - The showEmployeeInfo function demonstrates the use of default parameter values for employee information.

7. Pointer Arithmetic and Swapping:
   - Pointer arithmetic allows direct manipulation of memory addresses, which is useful in various scenarios like swapping values.
   - The complexSwap function showcases how to swap two values using pointers and arithmetic operations.
*/

// Function Declarations
int* findMaxElement(int* arr, int size);
void reverseString(string &str);
int& accessElement(int arr[], int size, int index);
void processLargeArray(const int arr[], int size);
inline double calculateArea(double radius);
void showEmployeeInfo(const string &name = "John Doe", int age = 30, const string &department = "HR");
void complexSwap(double *x, double *y);

// Main function
int main() {
    // ===========================
    // 1. Pointers - Complex Example
    // ===========================

    // Static array allocation and finding the maximum element
    int arr[] = {2, 8, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* maxElemPtr = findMaxElement(arr, size);
    if (maxElemPtr != nullptr) {
        cout << "Max element in array: " << *maxElemPtr << endl;
    }

    // ===========================
    // 2. References - Complex Example
    // ===========================

    // Reversing a string using a reference
    string sample = "Complexity";
    cout << "\nOriginal string: " << sample << endl;
    reverseString(sample);
    cout << "Reversed string: " << sample << endl;

    // ===========================
    // 3. Returning References
    // ===========================

    int numbers[] = {10, 20, 30, 40};
    cout << "\nOriginal array: ";
    for (int i = 0; i < 4; ++i) cout << numbers[i] << " ";
    cout << endl;

    // Access and modify an element by reference
    int &element = accessElement(numbers, 4, 2);
    element = 99;
    cout << "Modified array: ";
    for (int i = 0; i < 4; ++i) cout << numbers[i] << " ";
    cout << endl;

    // ===========================
    // 4. Const References
    // ===========================

    // Passing large array as a const reference
    int largeArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    processLargeArray(largeArray, 10);

    // ===========================
    // 5. Inline Function - Complex Calculation
    // ===========================

    double radius = 5.0;
    cout << "\nArea of circle with radius 5.0: " << calculateArea(radius) << endl;

    // ===========================
    // 6. Default Parameters
    // ===========================

    // Displaying employee info with default values and overridden values
    showEmployeeInfo(); // Uses all default values
    showEmployeeInfo("Alice", 28, "Engineering"); // Overrides all default values

    // ===========================
    // 7. Pointer Example - Complex Swap Function
    // ===========================

    double a = 12.5, b = 3.75;
    cout << "\nBefore swap: a = " << a << ", b = " << b << endl;
    complexSwap(&a, &b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0; // End of the program
}

// Function Definitions:

// 1. Pointers - Find the maximum element in an array using a pointer
int* findMaxElement(int* arr, int size) {
    if (size <= 0) return nullptr;
    int* maxElem = arr; // Pointer to the first element
    for (int i = 1; i < size; i++) {
        if (arr[i] > *maxElem) {
            maxElem = &arr[i]; // Update maxElem to point to the new maximum
        }
    }
    return maxElem;
}

// 2. Reverse a string using a reference
void reverseString(string &str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}



// 3. Returning a reference - Access and modify an element in an array
int& accessElement(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    // Handle out-of-bounds cases: this is dangerous, so use with caution
    // Note: This is just for demonstration purposes
    static int invalid = -1;
    return invalid;
}

// 4. Using const reference for large data
void processLargeArray(const int arr[], int size) {
    cout << "\nProcessing large array (const reference passed): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Accessing elements safely without modification
    }
    cout << endl;
}

// 5. Inline function for complex calculations (calculating area of a circle)
// Inline functions are used to reduce function call overhead, especially for small functions.
// The compiler replaces the function call with the actual code of the function during compilation.
// This can improve performance for small functions but may lead to code bloat if the function is too large.
inline double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

// 6. Function with default parameters for an employee information display
void showEmployeeInfo(const string &name, int age, const string &department) {
    cout << "\nEmployee Info:\n";
    cout << "Name: " << name << "\nAge: " << age << "\nDepartment: " << department << endl;
}

// 7. Pointer Example - Complex swap function for floating-point values
void complexSwap(double *x, double *y) {
    // More complex swap logic to demonstrate pointers
    if (x != y) { // Only proceed if pointers are not the same
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
}
