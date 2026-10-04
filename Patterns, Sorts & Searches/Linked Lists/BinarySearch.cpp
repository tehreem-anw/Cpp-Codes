#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

    // Private helper function to find middle node using fast & slow pointers
    Node* getMiddle(Node* start, Node* end) {
        if (start == nullptr) return nullptr;

        Node* slow = start;
        Node* fast = start->next;

        while (fast != end) {
            fast = fast->next;
            if (fast != end) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

public:
    LinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Push new element to the back of the linked list
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Perform binary search on the linked list
    bool binarySearch(int target) {
        Node* start = head;
        Node* end = nullptr;

        while (start != end) {
            Node* mid = getMiddle(start, end);

            if (mid == nullptr) return false;

            if (mid->data == target) {
                return true; // Target found
            } else if (mid->data < target) {
                start = mid->next; // Search in right half
            } else {
                end = mid; // Search in left half
            }
        }

        return false; // Target not found
    }

    // Helper to display the list elements
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Elements MUST be inserted in sorted order for binary search to work
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushBack(40);
    list.pushBack(50);
    list.pushBack(60);

    cout << "Linked List: ";
    list.display();

    int target = 40;
    if (list.binarySearch(target)) {
        cout << "LinkedList Search: Element " << target << " found." << endl;
    } else {
        cout << "LinkedList Search: Element " << target << " not found." << endl;
    }

    return 0;
}
