#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TreeNode structure to represent each node in the tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node with data
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinaryTree class to manage the binary tree
class BinaryTree {
    int preorderIndex;
    int postorderIndex;

public:
    TreeNode* root;

    BinaryTree() : root(nullptr), preorderIndex(0), postorderIndex(0) {}
    // Helper function for inorder traversal
    void inorderRec(TreeNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    // Helper function to construct tree from preorder array
    TreeNode* constructTreeFromPreorderHelper(const vector<int>& preorder) {
        if (preorderIndex >= preorder.size() || preorder[preorderIndex] == -1) {
            preorderIndex++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[preorderIndex++]);

        node->left = constructTreeFromPreorderHelper(preorder);
        node->right = constructTreeFromPreorderHelper(preorder);

        return node;
    }

    // Helper function to construct tree from postorder array
    TreeNode* constructTreeFromPostorderHelper(const vector<int>& postorder) {
        if (postorderIndex >= postorder.size() || postorder[postorderIndex] == -1) {
            postorderIndex++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(postorder[postorderIndex++]);

        // Note: Postorder traversal processes the right child before the left child
        node->right = constructTreeFromPostorderHelper(postorder);
        node->left = constructTreeFromPostorderHelper(postorder);

        return node;
    }



    // Method to construct a binary tree from a level order array
    void constructTreeFromLevelOrder(const vector<int>& levelOrder) {
        if (levelOrder.empty()) {
            return;
        }

        root = new TreeNode(levelOrder[0]);
        queue<TreeNode*> queue;
        queue.push(root);

        int i = 0;
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();

            // Calculate indices for left and right children
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            // Left child
            if (leftIndex < levelOrder.size() && levelOrder[leftIndex] != -1) {
                current->left = new TreeNode(levelOrder[leftIndex]);
                queue.push(current->left);
            }

            // Right child
            if (rightIndex < levelOrder.size() && levelOrder[rightIndex] != -1) {
                current->right = new TreeNode(levelOrder[rightIndex]);
                queue.push(current->right);
            }

            i++;
        }
    }

    // Method to construct a binary tree from preorder array
    void constructTreeFromPreorder(const vector<int>& preorder) {
        preorderIndex = 0;
        root = constructTreeFromPreorderHelper(preorder);
    }

    // Method to construct a binary tree from postorder array
    void constructTreeFromPostorder(const vector<int>& postorder) {
        postorderIndex = 0;
        root = constructTreeFromPostorderHelper(postorder);
    }

    // Method for inorder traversal
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    vector<int> levelOrder = {1, 2, 3, 4, 5, -1, 6};
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> postorder = {4, -1, -1, 5, -1, -1, 2, -1, 6, -1, -1, 3, 1};

    // Construct the tree from level order
    tree.constructTreeFromLevelOrder(levelOrder);
    cout << "Inorder traversal of tree constructed from level order: ";
    tree.inorder();

    // Construct the tree from preorder
    tree.constructTreeFromPreorder(preorder);
    cout << "Inorder traversal of tree constructed from preorder: ";
    tree.inorder();

    // Construct the tree from postorder
    tree.constructTreeFromPostorder(postorder);
    cout << "Inorder traversal of tree constructed from postorder: ";
    tree.inorder();

    return 0;
}
