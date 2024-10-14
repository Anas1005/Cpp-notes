#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * STL Unordered Set and Unordered Map Overview:
 *
 * 1. **Unordered Set**:
 *    - A collection of unique elements stored in no particular order.
 *    - Based on hash table, provides average constant time complexity for search, insert, and delete.
 *    - Operations:
 *      - insert(value): Adds an element; duplicates not allowed.
 *      - emplace(value): Constructs an element in place.
 *      - erase(value): Removes the specified element.
 *      - erase(iterator): Removes an element using an iterator.
 *      - clear(): Removes all elements.
 *      - size(): Returns the number of elements.
 *      - empty(): Checks if the unordered set is empty.
 *      - find(value): Finds an element (iterator).
 *      - count(value): Returns 1 if the element is found, 0 otherwise.
 *      - bucket_count(): Returns the number of buckets in the unordered set.
 *      - load_factor(): Returns the average number of elements per bucket.
 *      - rehash(count): Changes the number of buckets to at least count.
 *      - begin(): Returns an iterator to the first element.
 *      - end(): Returns an iterator to one past the last element.
 *      - rbegin(): Returns a reverse iterator to the last element.
 *      - rend(): Returns a reverse iterator to before the first element.
 *
 * 2. **Unordered Map**:
 *    - A collection of key-value pairs with unique keys stored in no particular order.
 *    - Based on hash table, provides average constant time complexity for search, insert, and delete.
 *    - Operations:
 *      - insert({key, value}): Adds a key-value pair; duplicates not allowed for keys.
 *      - emplace(key, value): Constructs a key-value pair in place.
 *      - erase(key): Removes the specified key and its associated value.
 *      - erase(iterator): Removes an element using an iterator.
 *      - clear(): Removes all key-value pairs.
 *      - size(): Returns the number of key-value pairs.
 *      - empty(): Checks if the unordered map is empty.
 *      - find(key): Finds a key (iterator).
 *      - count(key): Returns 1 if the key is found, 0 otherwise.
 *      - bucket_count(): Returns the number of buckets in the unordered map.
 *      - load_factor(): Returns the average number of elements per bucket.
 *      - rehash(count): Changes the number of buckets to at least count.
 *      - begin(): Returns an iterator to the first key-value pair.
 *      - end(): Returns an iterator to one past the last key-value pair.
 *      - rbegin(): Returns a reverse iterator to the last key-value pair.
 *      - rend(): Returns a reverse iterator to before the first key-value pair.
 */

void unorderedSetUsage() {
    unordered_set<int> us; // Initialize an empty unordered set
    us.insert(10); // Add elements
    us.insert(20);
    us.insert(10); // Duplicate (will be ignored)
    us.insert(30);
    
    // Output elements
    cout << "Unordered Set after insertions: ";
    for (const auto& n : us) cout << n << " "; // Output: 10 20 30 (order may vary)
    cout << endl;


    // Check for presence
    cout << "Count of 10: " << us.count(10) << endl; // Output: 1
    cout << "Count of 40: " << us.count(40) << endl; // Output: 0

    // Remove an element
    us.erase(20);
    cout << "Unordered Set after removing 20: ";
    for (const auto& n : us) cout << n << " "; // Output: 10 30 (order may vary)
    cout << endl;

    // Size and clear
    cout << "Size of unordered set: " << us.size() << endl; // Output: 2
    us.clear();
    cout << "Unordered Set size after clear: " << us.size() << endl; // Output: 0
}

void unorderedMapUsage() {
    unordered_map<string, int> um; // Initialize an empty unordered map
    um.insert({"Alice", 25}); // Add key-value pairs
    um.insert({"Bob", 30});
    um.insert({"Alice", 35}); // Duplicate key (will be replaced)
    um.insert({"Charlie", 40});

    // Output elements
    cout << "Unordered Map after insertions:\n";
    for (const auto& p : um) cout << p.first << ": " << p.second << endl; // Output: All pairs, order may vary

    // Check presence of a key
    cout << "Count of Alice: " << um.count("Alice") << endl; // Output: 1

    // Remove a specific key
    um.erase("Bob");
    cout << "Unordered Map after removing Bob:\n";
    for (const auto& p : um) cout << p.first << ": " << p.second << endl; // Output: Remaining pairs

    for (auto it = um.begin(); it != um.end(); ++it) cout << it->first << ":::::djkdka: " << it->second << endl; // Output: All pai

    // Size and clear
    cout << "Size of unordered map: " << um.size() << endl; // Output: Remaining size
    um.clear();
    cout << "Unordered Map size after clear: " << um.size() << endl; // Output: 0

     
}

int main() {
    cout << "Unordered Set Usage:\n";
    unorderedSetUsage();
    cout << "\nUnordered Map Usage:\n";
    unorderedMapUsage();
    return 0;
}
