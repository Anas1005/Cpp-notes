/*
 * Pointers to Functions and Lambdas in C++
 * 
 * 1. **Pointers to Non-Member Functions**:
 *    - Hold the address of free-standing functions (functions not tied to a class).
 *    - They can be used for indirect calls and passed as arguments (e.g., callback functions).
 *    - Syntax:
 *      `ReturnType (*pointerName)(parameter types);`
 * 
 * 2. **Pointers to Member Functions**:
 *    - Store the address of member functions that belong to a class.
 *    - Require an instance of the class for invocation.
 *    - Syntax:
 *      `ReturnType (ClassName::*pointerName)(parameter types);`
 *    - **& Symbol**:
 *      - The `&` symbol indicates that the function belongs to a class and not a standalone function.
 *      - While using `&` is technically optional in modern C++, it's often included for clarity.
 *    - **Dereferencing the Mmeber Fuunction**:
 *      - Use `.*` with an instance of the class to call the member function after dereferencing the member function address.
 * 
 * 3. **Lambda Functions**:
 *    - Lambdas are function objects that can be assigned to function pointers if they have no capture list.
 *    - Lambdas with capture lists cannot be assigned directly to function pointers.
 * 
 * 4. **Comparison: Lambdas vs Function Pointers**
 *    - Function pointers are used for C compatibility and simple function passing.
 *    - Lambdas provide more flexibility with inline definitions and closures.
 * 
 * | Feature                | Function Pointers                    | Lambda Functions                  |
 * |-----------------------|--------------------------------------|----------------------------------|
 * | Flexibility           | Limited to pointing to existing functions | Can define inline logic directly |
 * | Closures/Capture      | Not possible                         | Supports capture of variables (closures) |
 * | Member Functions      | Supported (requires object instance) | Can mimic behavior but not directly assignable if capturing |
 * | C Compatibility       | Compatible                           | Not available in C               |
 * | Inline Usage          | Not possible                         | Directly definable inline        |
 * | Type Safety           | Basic type checking                  | Stronger type inference and safety |
 * 
 * Examples:
 *    - Pointer to non-member function
 *    - Pointer to member function
 *    - Lambda function assigned to a function pointer
 */

#include <iostream>
using namespace std;

// Non-member function (free function)
void multiplyByTwo(int& x) {
    x *= 2;
}

// Example class with a member function
class Calculator {
public:
    void addTen(int& x) {
        x += 10;
    }

    static void subtractFive(int& x) {
        x -= 5;
    }
};

int main() {
    // **Pointer to Non-Member Function**
    void (*nonMemberFuncPtr)(int&) = multiplyByTwo;
    int value = 5;
    nonMemberFuncPtr(value); // Calls multiplyByTwo indirectly
    cout << "After multiplyByTwo: " << value << endl; // Output: 10

    // **Pointer to Lambda Function (Non-member function equivalent)**
    void (*lambdaFuncPtr)(int&) = [](int& x) { x *= 3; };
    lambdaFuncPtr(value); // Multiplies value by 3
    cout << "After lambda function: " << value << endl; // Output: 30

    // **Pointer to Member Function**
    Calculator calc;
    void (Calculator::*memberFuncPtr)(int&) = &Calculator::addTen;
    (calc.*memberFuncPtr)(value); // Calls addTen on 'calc' object
    cout << "After addTen: " << value << endl; // Output: 40

    // **Pointer to Static Member Function**
    void (*staticMemberFuncPtr)(int&) = &Calculator::subtractFive;
    staticMemberFuncPtr(value); // Calls static subtractFive directly
    cout << "After subtractFive: " << value << endl; // Output: 35

    return 0;
}
