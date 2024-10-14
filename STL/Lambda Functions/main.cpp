/*
 * Lambda Functions in C++
 *
 * Lambda functions are anonymous functions that can be defined in-place.
 * They are useful for short operations that do not require a full function definition.
 *
 * **Characteristics**:
 * - Defined using the syntax: `[captures] (parameters) -> return_type { body }`
 * - Can capture local variables by value or reference.
 * - Can be passed as arguments to functions or returned from functions.
 * - Useful for creating custom comparators, callbacks, and algorithms.
 *
 * **Use Cases**:
 * 1. **Basic Operations**: Simple tasks like addition, subtraction, etc.
 * 2. **Higher-Order Functions**: Functions that accept other functions as arguments.
 * 3. **Custom Comparators**: Used with STL containers like sort, priority_queue, etc.
 * 4. **STL Algorithm Integration**: Used with standard algorithms for concise operations.
 * 5. **Capturing Variables**: Capturing local variables for use within the lambda.
 * 6. **Returning Lambdas**: Functions that return lambdas for flexible behavior.
 *
 * This code showcases various use cases of lambda functions in C++.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {
    // 1. Basic Lambda Expression
    auto add = [](int a, int b) { return a + b; };
    cout << "Sum: " << add(5, 3) << endl; // Outputs: 8

    // 2. Lambda with Parameters
    auto multiply = [](int a, int b) {
        return a * b;
    };
    cout << "Product: " << multiply(4, 6) << endl; // Outputs: 24

    // 3. Capturing Variables
    int x = 10;
    int y = 5;
    
    // Capture by value
    auto captureByValue = [x, y]() { return x + y; };
    cout << "Captured by value: " << captureByValue() << endl; // Outputs: 15

    // Capture by reference
    auto captureByReference = [&x, &y]() { return x * y; };
    cout << "Captured by reference: " << captureByReference() << endl; // Outputs: 50

    // 4. Using Lambdas with STL Algorithms
    vector<int> vec = {5, 2, 8, 1, 4};

    // Sort in ascending order using lambda
    sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; });
    cout << "Sorted (ascending): ";
    for (int n : vec) cout << n << " "; // Outputs: 1 2 4 5 8
    cout << endl;

    // Sort in descending order using lambda
    sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
    cout << "Sorted (descending): ";
    for (int n : vec) cout << n << " "; // Outputs: 8 5 4 2 1
    cout << endl;

    // 5. Using Lambdas in Data Structures
    auto customComparator = [](int a, int b) {
        return a < b; // Max-heap
    };

    bool (*ptr)(int, int) = [](int a, int b) {
        return a < b; // Max-heap
    };

    priority_queue<int, vector<int>, decltype(customComparator)> maxHeap(customComparator);
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);

    cout << "Max-Heap elements: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Outputs: 30 20 10
        maxHeap.pop();
    }
    cout << endl;

    

    // 6. Lambda as a Return Type
    auto returnLambda = []() {
        return [](int a, int b) { return a - b; }; // returns a lambda that subtracts
    };

    auto subtract = returnLambda();
    cout << "Subtraction: " << subtract(10, 5) << endl; // Outputs: 5

    // 7. Higher-Order Functions
    auto higherOrderFunction = [](function<int(int, int)> func, int a, int b) {
        return func(a, b);
    };

    cout << "Higher-order function result: " << higherOrderFunction(multiply, 4, 3) << endl; // Outputs: 12

    return 0;
}
