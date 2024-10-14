#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data; // Data stored in the node
    Node* next; // Pointer to the next node

    // Node constructor
    Node(int value) : data(value), next(nullptr) {}
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor to initialize the linked list
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~SinglyLinkedList() {
        clear(); // Clear the list on destruction
    }

    // Insert at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (!head) {
            head = newNode; // If list is empty, new node becomes the head
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Link the new node
    }

    // Delete a specific value from the list
    void deleteValue(int value) {
        if (!head) return; // List is empty
        if (head->data == value) {
            Node* temp = head; // Node to be deleted is the head
            head = head->next; // Move head to the next node
            delete temp; // Free memory
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next; // Traverse to find the node to delete
        }
        if (current->next) {
            Node* temp = current->next; // Node to be deleted
            current->next = current->next->next; // Bypass the node
            delete temp; // Free memory
        }
    }

    // Print all elements in the list
    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " "; // Print data
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }

    // Clear the entire list
    void clear() {
        while (head) {
            deleteValue(head->data); // Delete each node
        }
    }

    // Get the size of the list
    int size() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++; // Count each node
            temp = temp->next; // Move to the next node
        }
        return count;
    }
};

// Main function to demonstrate the usage
int main() {
    SinglyLinkedList list; // Create a linked list

    // Inserting values into the list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "List after insertion: ";
    list.print(); // Output: 10 20 30

    // Deleting a value
    list.deleteValue(20);
    cout << "List after deleting 20: ";
    list.print(); // Output: 10 30

    // Deleting a non-existent value
    list.deleteValue(40); // Should not affect the list
    cout << "List after trying to delete 40: ";
    list.print(); // Output: 10 30

    // Getting the size of the list
    cout << "Size of the list: " << list.size() << endl; // Output: 2

    // Clearing the list
    list.clear();
    cout << "List after clearing: ";
    list.print(); // Output: (empty)

    return 0;
}
