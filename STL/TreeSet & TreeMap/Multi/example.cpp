#include <iostream>
#include <set>
#include <map>

using namespace std;

/**
 * STL Multiset and Multimap Overview:
 *
 * 1. **Multiset**:
 *    - A sorted collection of elements that allows duplicate values.
 *    - Operations:
 *      - insert(value): Adds an element, duplicates allowed.
 *      - emplace(value): Constructs an element in place, duplicates allowed.
 *      - count(value): Returns the number of occurrences of the value.
 *      - erase(value): Removes one occurrence of the value.
 *      - erase(iterator): Removes an element using an iterator.
 *      - clear(): Removes all elements.
 *      - size(): Returns the number of elements.
 *      - empty(): Checks if the multiset is empty.
 *      - find(value): Finds an element (iterator).
 *      - lower_bound(value): First element not less than the specified value.
 *      - upper_bound(value): First element greater than the specified value.
 *      - begin(): Returns an iterator to the first element.
 *      - end(): Returns an iterator to one past the last element.
 *      - rbegin(): Returns a reverse iterator to the last element.
 *      - rend(): Returns a reverse iterator to before the first element.
 *
 * 2. **Multimap**:
 *    - A collection of key-value pairs that allows duplicate keys.
 *    - Operations:
 *      - insert(key, value): Adds a key-value pair, duplicates allowed.
 *      - emplace(key, value): Constructs a key-value pair in place.
 *      - count(key): Returns the number of occurrences of the key.
 *      - erase(key): Removes all pairs with the specified key.
 *      - erase(iterator): Removes an element using an iterator.
 *      - clear(): Removes all pairs.
 *      - size(): Returns the number of pairs.
 *      - empty(): Checks if the multimap is empty.
 *      - find(key): Finds a key (iterator).
 *      - lower_bound(key): First pair with key not less than the specified key.
 *      - upper_bound(key): First pair with key greater than the specified key.
 *      - begin(): Returns an iterator to the first key-value pair.
 *      - end(): Returns an iterator to one past the last key-value pair.
 *      - rbegin(): Returns a reverse iterator to the last key-value pair.
 *      - rend(): Returns a reverse iterator to before the first key-value pair.
 */

void multisetUsage() {
    multiset<int> ms; // Initialize an empty multiset
    ms.insert(10); // Add elements
    ms.insert(20);
    ms.insert(10); // Duplicate
    ms.insert(30);
    ms.insert(20); // Duplicate

    // Output elements
    cout << "Multiset after insertions: ";
    for (const auto& n : ms) cout << n << " "; // Output: 10 10 20 20 30
    cout << endl;

    // Count occurrences
    cout << "Count of 10: " << ms.count(10) << endl; // Output: 2
    cout << "Count of 20: " << ms.count(20) << endl; // Output: 2

    // Remove one occurrence of an element
    ms.erase(20);
    cout << "Multiset after removing one occurrence of 20: ";
    for (const auto& n : ms) cout << n << " "; // Output: 10 10 20 30
    cout << endl;

    // Size and clear
    cout << "Size of multiset: " << ms.size() << endl; // Output: 4
    ms.clear();
    cout << "Multiset size after clear: " << ms.size() << endl; // Output: 0
}

void multimapUsage() {
    multimap<string, int> mm; // Initialize an empty multimap
    mm.insert({"Alice", 25}); // Add key-value pairs
    mm.insert({"Bob", 30});
    mm.insert({"Alice", 35}); // Duplicate key
    mm.insert({"Charlie", 40});

    // Output elements
    cout << "Multimap after insertions:\n";
    for (const auto& p : mm) cout << p.first << ": " << p.second << endl; // Output: All pairs

    // Count occurrences of a key
    cout << "Count of Alice: " << mm.count("Alice") << endl; // Output: 2

    // Remove all pairs with a specific key
    mm.erase("Alice");
    cout << "Multimap after removing all entries for Alice:\n";
    for (const auto& p : mm) cout << p.first << ": " << p.second << endl; // Output: Bob and Charlie

    // Size and clear
    cout << "Size of multimap: " << mm.size() << endl; // Output: 2
    mm.clear();
    cout << "Multimap size after clear: " << mm.size() << endl; // Output: 0
}

int main() {
    cout << "Multiset Usage:\n";
    multisetUsage();
    cout << "\nMultimap Usage:\n";
    multimapUsage();
    return 0;
}
