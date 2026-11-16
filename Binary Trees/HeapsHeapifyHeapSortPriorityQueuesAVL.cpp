#include <iostream>
#include <algorithm> // For max() function used in AVL

using namespace std;

// ============================================================================
// PART 1: PRIORITY QUEUE USING A SORTED LINKED LIST
// Elements are kept sorted by priority (highest first). Front is O(1), insert is O(n).
//
// ============================================================================

class NodeLinkedList {
public:
    int value;           // The value of the element[cite: 4]
    int priority;        // The priority of the element[cite: 4]
    NodeLinkedList* next;// Pointer to the next node in the queue[cite: 4]

    NodeLinkedList(int val, int pri) {
        value = val;
        priority = pri;
        next = nullptr;
    }
};

class PriorityQueueLinkedList {
private:
    NodeLinkedList* front; // The front of the queue[cite: 4]

public:
    PriorityQueueLinkedList() {
        front = nullptr;
    }

    // Destructor to clean up memory
    ~PriorityQueueLinkedList() {
        while (front) {
            NodeLinkedList* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Insert a new element in its correct sorted position based on priority[cite: 4]
    void insert(int val, int pri) {
        NodeLinkedList* newNode = new NodeLinkedList(val, pri);

        // If queue is empty or new node has higher priority than the front[cite: 4]
        if (!front || pri > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            // Traverse to find the correct sorted position[cite: 4, 5]
            NodeLinkedList* current = front;
            while (current->next && current->next->priority >= pri) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Remove the element with the highest priority (the front)[cite: 5]
    void remove() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        NodeLinkedList* temp = front;
        front = front->next;
        delete temp;
    }

    // Look at the highest priority element without removing it[cite: 4, 5]
    int peek() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->value;
    }

    // Print the entire queue from front to back[cite: 5]
    void printQueue() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        NodeLinkedList* current = front;
        while (current) {
            cout << "(" << current->value << "," << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};


// ============================================================================
// PART 2: MAX-HEAP AND HEAP OPERATIONS (Array-Based Complete Binary Tree)
// Operations: Heapify-Up, Heapify-Down, BuildHeap, Insert, DeleteMax
//
// ============================================================================

class MaxHeap {
private:
    int* arr;       // Dynamic raw array to store heap elements[cite: 7]
    int capacity;   // Maximum capacity of the heap[cite: 7]
    int size;       // Current number of elements[cite: 7]

    // Helper index formulas for a complete binary tree stored in an array[cite: 6]
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    // Heapify-Up (Percolate-Up): Used during insertion to restore heap property[cite: 7, 8]
    void heapifyUp(int i) {
        while (i > 0 && arr[parent(i)] < arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // Heapify-Down (Percolate-Down): Used during deletion/buildHeap to sink nodes down[cite: 8]
    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int l = leftChild(i);
            int r = rightChild(i);

            // Check if left child is greater than current largest[cite: 8]
            if (l < size && arr[l] > arr[largest]) largest = l;
            // Check if right child is greater than current largest[cite: 8]
            if (r < size && arr[r] > arr[largest]) largest = r;

            // If root is largest, heap property is satisfied; otherwise swap and continue[cite: 8]
            if (largest == i) break;
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~MaxHeap() {
        delete[] arr;
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }

    // Insert an element into the heap[cite: 8]
    void insert(int value) {
        if (isFull()) {
            cout << "Heap is full!" << endl;
            return;
        }
        arr[size] = value; // Place at the end of the complete binary tree[cite: 8]
        size++;
        heapifyUp(size - 1); // Fix heap property moving up[cite: 8]
    }

    // Return the max element (root)[cite: 8]
    int peek() {
        if (isEmpty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return arr[0];
    }

    // Remove the maximum element (root) and reorganize the heap[cite: 7, 8]
    int deleteMax() {
        if (isEmpty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        int top = arr[0];
        arr[0] = arr[size - 1]; // Move last element to root[cite: 8]
        size--;
        heapifyDown(0);         // Fix heap property moving down[cite: 8]
        return top;
    }

    // Build a heap from an arbitrary array in O(n) time[cite: 8, 18]
    void buildHeap(int a[], int n) {
        if (n > capacity) {
            cout << "Array too large!" << endl;
            return;
        }
        for (int i = 0; i < n; i++) arr[i] = a[i];
        size = n;
        // Start from the first non-leaf node (n/2 - 1) and heapify down[cite: 6, 8]
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


// ============================================================================
// PART 3: HEAP SORT IMPLEMENTATION
// Uses heapify to sort an array in-place.
// ============================================================================

void heapifyForSort(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyForSort(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build max heap from unsorted array[cite: 8]
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyForSort(arr, n, i);
    }
    // Step 2: Extract elements one by one from the heap[cite: 8]
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move max root to the end[cite: 8]
        heapifyForSort(arr, i, 0); // Restore heap on reduced array[cite: 8]
    }
}


// ============================================================================
// PART 4: AVL TREE IMPLEMENTATION (Self-Balancing Binary Search Tree)
// Handles balance factors and rotations (LL, RR, LR, RL)
// ============================================================================

struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int val) {
        key = val;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// Get height of an AVL node
int getHeight(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Get balance factor (Left Height - Right Height)
int getBalanceFactor(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right Rotation (Fixes Left-Left Imbalance)
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotation (Fixes Right-Right Imbalance)
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert into AVL Tree with automatic self-balancing rotations
AVLNode* insertAVL(AVLNode* node, int key) {
    // 1. Standard BST Insertion
    if (node == nullptr) return new AVLNode(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else if (key > node->key)
        node->right = insertAVL(node->right, key);
    else
        return node; // Duplicate keys not allowed

    // 2. Update height of current ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get balance factor to check if node became unbalanced
    int balance = getBalanceFactor(node);

    // 4. Perform Rotations if unbalanced
    // Left-Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right-Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left-Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// In-order traversal for AVL Tree
void inOrderTraversal(AVLNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}


// ============================================================================
// MAIN FUNCTION: DEMONSTRATING ALL MODULES
// ============================================================================
int main() {
    cout << "=== 1. PRIORITY QUEUE (SORTED LINKED LIST) ===" << endl;
    PriorityQueueLinkedList pqList;
    pqList.insert(10, 2);
    pqList.insert(20, 5);
    pqList.insert(30, 1);
    pqList.insert(40, 5);
    pqList.insert(50, 3);
    pqList.printQueue(); // Expected: (20, 5) (40, 5) (50, 3) (10, 2) (30, 1)[cite: 5]
    cout << "Peek: " << pqList.peek() << endl; // 20[cite: 5]
    pqList.remove();
    pqList.printQueue();

    cout << "\n=== 2. MAX-HEAP & BUILD HEAP ===" << endl;
    MaxHeap heap(10);
    int values[] = {20, 15, 30, 10, 40};
    for (int i = 0; i < 5; i++) heap.insert(values[i]);
    cout << "Max-Heap Display: ";
    heap.display();
    cout << "Deleted Max: " << heap.deleteMax() << endl;

    cout << "\n=== 3. HEAP SORT ===" << endl;
    int sortArr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    heapSort(sortArr, n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << sortArr[i] << " ";
    cout << endl;

    cout << "\n=== 4. AVL TREE ===" << endl;
    AVLNode* avlRoot = nullptr;
    int avlKeys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        avlRoot = insertAVL(avlRoot, avlKeys[i]);
    }
    cout << "AVL In-order Traversal: ";
    inOrderTraversal(avlRoot);
    cout << endl;

    return 0;
}
