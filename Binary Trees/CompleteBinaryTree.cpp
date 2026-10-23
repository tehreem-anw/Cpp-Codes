#include <iostream>
using namespace std;

// Node class representing each element in the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to easily initialize a node with a value
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Calculates and returns the maximum height (depth) of the tree
int height(Node* root) {
    if (root == nullptr)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

// Helper function to try inserting a value at a specific tree level
bool insertAtLevel(Node* root, int value, int level) {
    if (root == nullptr)
        return false;

    if (level == 1) {
        if (root->left == nullptr) {
            root->left = new Node(value);
            return true;
        }

        if (root->right == nullptr) {
            root->right = new Node(value);
            return true;
        }

        return false;
    }

    if (insertAtLevel(root->left, value, level - 1))
        return true;

    return insertAtLevel(root->right, value, level - 1);
}

// Inserts a value level-by-level to keep the binary tree fully packed
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    int h = height(root);

    // Try to insert in existing levels from top to bottom
    for (int level = 1; level <= h; level++) {
        if (insertAtLevel(root, value, level))
            return root;
    }

    // If all current levels are full, insert in a new level
    insertAtLevel(root, value, h + 1);

    return root;
}

// Searches for a target value in the tree using Depth-First Search
Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value)
        return root;

    Node* found = search(root->left, value);

    if (found != nullptr)
        return found;

    return search(root->right, value);
}

// Locates an old value and updates it to a new value
void update(Node* root, int oldValue, int newValue) {
    Node* temp = search(root, oldValue);

    if (temp == nullptr)
        cout << "Value not found\n";
    else
        temp->data = newValue;
}

// Preorder traversal: Root -> Left Subtree -> Right Subtree
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal: Left Subtree -> Root -> Right Subtree
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder traversal: Left Subtree -> Right Subtree -> Root
void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Helper function to print all node data at a specified target level
void printLevel(Node* root, int level) {
    if (root == nullptr) return;

    if (level == 1) {
        cout << root->data << " ";
        return;
    }

    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

// Level-order traversal: Prints the tree level by level from top to bottom
void levelOrder(Node* root) {
    int h = height(root);

    for (int i = 1; i <= h; i++)
        printLevel(root, i);

    cout << endl;
}

int main() {
    Node* root = nullptr;

    // Inserting elements into the binary tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Level order: ";
    levelOrder(root);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nSearch 30: ";
    cout << (search(root, 30) != nullptr ? "Found" : "Not found");

    update(root, 30, 35);

    cout << "\nAfter update: ";
    levelOrder(root);

    return 0;
}
