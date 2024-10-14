#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iterator>

using namespace std;

/*
 * This program demonstrates various types of iterators in C++ Standard Template Library (STL).
 *
 * 1. **Input Iterator**: Used to read input from a stream. Example using istream_iterator.
 * 2. **Output Iterator**: Used to write output to a stream. Example using ostream_iterator.
 * 3. **Forward Iterator**: Can read elements in one direction. Example using a list.
 * 4. **Bidirectional Iterator**: Can read elements in both directions. Example using a set.
 * 5. **Random Access Iterator**: Allows access to elements using indices, enabling more complex operations. Example using a vector.
 * 6. **Const Iterator**: Provides read-only access to elements. Example using a const vector.
 * 7. **Reverse Iterator**: Allows iterating through a container in reverse order. Example using a vector.
 */

int main() {
    // Input Iterator Example
    cout << "Input Iterator Example:" << endl;
    vector<int> inputVec = {1, 2, 3, 4, 5};
    istream_iterator<int> inputIt(cin); // Reads from standard input
    cout << "Enter 5 integers (end with EOF): ";
    cout << "Input Iterated Values: ";
    for (int i = 0; i < 5; ++i) {
        int val;
        cin >> val;
        cout << val << " ";
    }
    cout << endl;

    // Output Iterator Example
    cout << "\nOutput Iterator Example:" << endl;
    ostream_iterator<int> outputIt(cout, " ");
    *outputIt = 10;  // Outputting single value
    *outputIt = 20;  // Outputting another value
    cout << endl;

    // Forward Iterator Example
    cout << "\nForward Iterator Example:" << endl;
    list<int> forwardList = {10, 20, 30, 40, 50};
    cout << "Forward List Values: ";
    for (list<int>::iterator it = forwardList.begin(); it != forwardList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Bidirectional Iterator Example
    cout << "\nBidirectional Iterator Example:" << endl;
    set<int> bidirectionalSet = {5, 10, 15, 20};
    cout << "Bidirectional Set Values: ";
    for (set<int>::iterator it = bidirectionalSet.begin(); it != bidirectionalSet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Random Access Iterator Example
    cout << "\nRandom Access Iterator Example:" << endl;
    vector<int> randomAccessVec = {1, 2, 3, 4, 5};
    cout << "Random Access Vector Values: ";
    for (vector<int>::iterator it = randomAccessVec.begin(); it != randomAccessVec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Const Iterator Example
    cout << "\nConst Iterator Example:" << endl;
    const vector<int> constVec = {10, 20, 30, 40};
    cout << "Const Vector Values: ";
    for (vector<int>::const_iterator it = constVec.begin(); it != constVec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse Iterator Example
    cout << "\nReverse Iterator Example:" << endl;
    vector<int> reverseVec = {1, 2, 3, 4, 5};
    cout << "Reverse Vector Values: ";
    for (vector<int>::reverse_iterator it = reverseVec.rbegin(); it != reverseVec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
