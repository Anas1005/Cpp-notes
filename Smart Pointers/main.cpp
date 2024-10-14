#include <iostream>
#include <memory>

struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int val) : value(val) {}
    ~Node() { std::cout << "Deleting Node with value: " << value << std::endl; }
};

// Function to add children to a node
void addChildren(std::unique_ptr<Node>& parent, int leftValue, int rightValue) {
    parent->left = std::make_unique<Node>(leftValue);
    parent->right = std::make_unique<Node>(rightValue);
}

// Function to create a tree structure
void createTree(std::unique_ptr<Node>& root) {
    root = std::make_unique<Node>(1); // Root node
    addChildren(root, 2, 3);           // Add children to root

    // Adding more children
    addChildren(root->left, 4, 5);     // Add children to left child of root
    addChildren(root->right, 6, 7);    // Add children to right child of root

    // Further expanding the tree
    addChildren(root->left->left, 8, 9); // Add children to left child of left child
    addChildren(root->left->right, 10, 11); // Add children to right child of left child
}

int main() {
    std::unique_ptr<Node> root;
    createTree(root); // Build the tree structure

    // The entire tree will be automatically cleaned up when root goes out of scope
    return 0;
}
