#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

// Function to demonstrate stack operations
void stackUsage() {
    stack<int> s; // Declare a stack of integers

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Stack after pushes: ";
    cout << s.top() << endl; // Show top element (30)

    // Pop an element from the stack
    s.pop();
    cout << "Stack after popping: ";
    cout << s.top() << endl; // Show top element (20)

    // Check if stack is empty
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; // Output: No

    // Get the size of the stack
    cout << "Size of stack: " << s.size() << endl; // Output: 2
}

// Function to demonstrate queue operations
void queueUsage() {
    queue<int> q; // Declare a queue of integers

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Queue after enqueues: ";
    cout << q.front() << endl; // Show front element (10)

    // Dequeue an element from the queue
    q.pop();
    cout << "Queue after dequeuing: ";
    cout << q.front() << endl; // Show front element (20)

    // Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Output: No

    // Get the size of the queue
    cout << "Size of queue: " << q.size() << endl; // Output: 2
}

// Function to demonstrate deque operations
void dequeUsage() {
    deque<int> d; // Declare a deque of integers

    // Push elements to the front and back
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);
    d.push_front(0);
    cout << "Deque after pushes: ";
    for (int n : d) {
        cout << n << " "; // Output: 0 5 10 20
    }
    cout << endl;

    // Pop elements from the front and back
    d.pop_front(); // Removes 0
    d.pop_back(); // Removes 20
    cout << "Deque after pops: ";
    for (int n : d) {
        cout << n << " "; // Output: 5 10
    }
    cout << endl;

    // Check if deque is empty
    cout << "Is deque empty? " << (d.empty() ? "Yes" : "No") << endl; // Output: No

    // Get the size of the deque
    cout << "Size of deque: " << d.size() << endl; // Output: 2
}

// Main function to demonstrate usage of stack, queue, and deque
int main() {
    cout << "Stack Usage:" << endl;
    stackUsage(); // Demonstrate stack operations

    cout << "\nQueue Usage:" << endl;
    queueUsage(); // Demonstrate queue operations

    cout << "\nDeque Usage:" << endl;
    dequeUsage(); // Demonstrate deque operations

    return 0;
}
