#include <iostream>
#include <set>
#include <map>

using namespace std;

/**
 * STL (Standard Template Library) Functions Overview:
 *
 * 1. **Set**:
 *    - Unique, sorted collection of elements.
 *    - Operations:
 *      - insert(value): Adds an element.
 *      - emplace(value): Constructs an element in place.
 *      - count(value): Checks existence (1 or 0).
 *      - erase(value): Removes an element.
 *      - erase(iterator): Removes an element using an iterator.
 *      - clear(): Removes all elements.
 *      - size(): Returns the number of elements.
 *      - empty(): Checks if the set is empty.
 *      - find(value): Finds an element (iterator).
 *      - lower_bound(value): First element not less than value.
 *      - upper_bound(value): First element greater than value.
 *      - begin(): Returns an iterator to the first element.
 *      - end(): Returns an iterator to one past the last element.
 *      - rbegin(): Returns a reverse iterator to the last element.
 *      - rend(): Returns a reverse iterator to before the first element.
 *
 * 2. **Map**:
 *    - Collection of key-value pairs (unique keys).
 *    - Operations:
 *      - operator[](key): Access/insert value by key.
 *      - emplace(key, value): Constructs an element in place.
 *      - count(key): Checks existence of key.
 *      - erase(key): Removes key-value pair.
 *      - erase(iterator): Removes an element using an iterator.
 *      - clear(): Removes all pairs.
 *      - size(): Returns the number of pairs.
 *      - empty(): Checks if the map is empty.
 *      - find(key): Finds key (iterator).
 *      - lower_bound(key): First pair with key not less than key.
 *      - upper_bound(key): First pair with key greater than key.
 *      - begin(): Returns an iterator to the first key-value pair.
 *      - end(): Returns an iterator to one past the last key-value pair.
 *      - rbegin(): Returns a reverse iterator to the last key-value pair.
 *      - rend(): Returns a reverse iterator to before the first key-value pair.
 */

void setUsage() {
    set<int> s; // Initialize an empty set
    s.insert(10); // Add an element
    s.insert(20);
    s.insert(30);
    s.insert(20); // Duplicate, will not be inserted

    // Output elements
    cout << "Set after insertions: ";
    for (const auto& n : s) cout << n << " "; // Output: 10 20 30
    cout << endl;

    // Check if an element exists
    cout << "Count of 20: " << s.count(20) << endl; // Output: 1

    // Remove an element
    s.erase(20);
    cout << "Set after removing 20: ";
    for (const auto& n : s) cout << n << " "; // Output: 10 30
    cout << endl;

    // Get size
    cout << "Size of set: " << s.size() << endl; // Output: 2

    // Clear the set
    s.clear();
    cout << "Set size after clear: " << s.size() << endl; // Output: 0

    // Reinsert elements to demonstrate other functions
    s.insert(15);
    s.insert(25);
    s.insert(5);

    // Lower and upper bounds
    cout << "Lower bound of 10: " << *s.lower_bound(10) << endl; // Output: 15
    cout << "Upper bound of 10: " << *s.upper_bound(10) << endl; // Output: 15

    // Iterators
    cout << "Set elements using iterators: ";
    for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " "; // Output: 5 15 25
    cout << endl;
}

void mapUsage() {
    map<string, int> m; // Initialize an empty map
    m["Alice"] = 25; // Add key-value pairs
    m["Bob"] = 30;
    m["Charlie"] = 35;

    // Output elements
    cout << "Map after insertions:\n";
    for (const auto& p : m) cout << p.first << ": " << p.second << endl; // Output: All pairs

    // Access value by key
    cout << "Age of Bob: " << m["Bob"] << endl; // Output: 30

    // Count existence of a key
    cout << "Count of Alice: " << m.count("Alice") << endl; // Output: 1

    // Remove a key-value pair
    m.erase("Alice");
    cout << "Map after removing Alice:\n";
    for (const auto& p : m) cout << p.first << ": " << p.second << endl; // Output: Bob and Charlie

    // Size and clear
    cout << "Size of map: " << m.size() << endl; // Output: 2
    m.clear();
    cout << "Map size after clear: " << m.size() << endl; // Output: 0

    // Reinsert elements to demonstrate other functions
    m["David"] = 40;
    m["Eve"] = 45;

    // Lower and upper bounds
    cout << "Lower bound for 'Bob': " << m.lower_bound("Bob")->first << endl; // Output: David
    cout << "Upper bound for 'Bob': " << m.upper_bound("Bob")->first << endl; // Output: Eve

    // Iterators
    cout << "Map elements using iterators:\n";
    for (auto it = m.begin(); it != m.end(); ++it) cout << it->first << ": " << it->second << endl; // Output: All pairs
}

int main() {
    cout << "Set Usage:\n";
    setUsage(); 
    cout << "\nMap Usage:\n";
    mapUsage(); 
    return 0; 
}
