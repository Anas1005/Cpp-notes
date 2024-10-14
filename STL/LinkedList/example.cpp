#include <iostream>
#include <list> // Include the list header

using namespace std;

int main() {
    // 1. Declaration and Initialization
    list<int> myList;

    // 2. Adding Elements
    myList.push_back(10);  // Adds 10 to the end
    myList.push_back(20);  // Adds 20 to the end
    myList.push_front(5);  // Adds 5 to the front

    // Displaying the current list
    cout << "List after adding elements: ";
    for (int value : myList) {
        cout << value << " "; // Prints: 5 10 20
    }
    cout << endl;

    // 3. Inserting Elements at Specific Position
    auto it = myList.begin(); // Get iterator to the beginning
    ++it; // Move to the second position
    myList.insert(it, 15); // Insert 15 before 10

    cout << "List after inserting 15: ";
    for (int value : myList) {
        cout << value << " "; // Prints: 5 15 10 20
    }
    cout << endl;

    // 4. Accessing Elements
    cout << "Front element: " << myList.front() << endl; // Prints: 5
    cout << "Back element: " << myList.back() << endl; // Prints: 20

    // 5. Removing Elements
    myList.pop_front(); // Removes the first element (5)
    myList.pop_back();  // Removes the last element (20)

    cout << "List after popping front and back: ";
    for (auto it = myList.begin() ; it != myList.end(); ++it) {
        cout << *it << " "<<"kkk"; // Prints: 15 10
    }
    cout << endl;

    // 6. Sorting the List
    myList.push_back(25); // Adding elements for sorting
    myList.push_back(5);
    myList.push_back(30);
    myList.sort(); // Sorts the list

    cout << "Sorted List: ";
    for (int value : myList) {
        cout << value << " "; // Prints: 5 10 15 25 30
    }
    cout << endl;

    // 7. Removing Specific Value
    myList.remove(15); // Removes all instances of 15

    cout << "List after removing 15: ";
    for (int value : myList) {
        cout << value << " "; // Prints: 5 10 25 30
    }
    cout << endl;

    // 8. Reversing the List
    myList.reverse(); // Reverses the order of the elements

    cout << "Reversed List: ";
    for (int value : myList) {
        cout << value << " "; // Prints: 30 25 10 5
    }
    cout << endl;

    // 9. Clearing the List
    myList.clear(); // Clears all elements from the list

    cout << "List size after clearing: " << myList.size() << endl; // Prints: 0

    return 0;
}
