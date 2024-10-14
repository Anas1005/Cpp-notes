#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

/**
 * STL Priority Queue Overview:
 *
 * 1. **Priority Queue**:
 *    - A container adapter that provides constant time lookup of the largest (by default) or smallest element, 
 *      and logarithmic time insertion and removal.
 *    - Internally implemented as a max heap by default but can be configured to use a min heap.
 *    - Operations:
 *      - push(value): Adds an element to the priority queue.
 *      - emplace(value): Constructs and adds an element in place.
 *      - pop(): Removes the top element (highest priority).
 *      - top(): Returns a reference to the top element (highest priority).
 *      - empty(): Checks if the priority queue is empty.
 *      - size(): Returns the number of elements in the priority queue.
 *      - swap(other): Swaps the contents with another priority queue.
 */

void priorityQueueUsage() {
    // Max heap example
    priority_queue<int> maxHeap; // Initialize a max heap
    maxHeap.push(30); // Add elements
    maxHeap.push(20);
    maxHeap.push(10);
    maxHeap.push(25);

    cout << "Max Heap (Priority Queue) elements:\n";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Output: 30 25 20 10
        maxHeap.pop(); // Remove the top element
    }
    cout << endl;

    // Min heap example using greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap; // Initialize a min heap
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(10);
    minHeap.push(25);

    cout << "Min Heap (Priority Queue) elements:\n";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Output: 10 20 25 30
        minHeap.pop(); // Remove the top element
    }
    cout << endl;
}

int main() {
    priorityQueueUsage();
    return 0;
}
