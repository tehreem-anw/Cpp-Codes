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

    // Helper method to get the length of the list
    int getLength() {
        int len = 0;
        Node* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    // Helper method to get pointer to node at specific index
    Node* getNodeAt(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        return temp;
    }

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

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

    // 1. Insertion Sort (re-linking node pointers)
    void insertionSort() {
        Node* sorted = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;

            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    // 2. Selection Sort
    void selectionSort() {
        for (Node* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            Node* minNode = temp1;
            for (Node* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {
                if (temp2->data < minNode->data) {
                    minNode = temp2;
                }
            }
            if (minNode != temp1) {
                swap(temp1->data, minNode->data);
            }
        }
    }

    // 3. Bubble Sort
    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    // 4. Shell Sort
    void shellSort() {
        int n = getLength();

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                Node* nodeI = getNodeAt(i);
                int temp = nodeI->data;
                int j = i;

                while (j >= gap && getNodeAt(j - gap)->data > temp) {
                    getNodeAt(j)->data = getNodeAt(j - gap)->data;
                    j -= gap;
                }
                getNodeAt(j)->data = temp;
            }
        }
    }

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
    // Demonstration of Insertion Sort
    LinkedList list1;
    list1.pushBack(64);
    list1.pushBack(25);
    list1.pushBack(12);
    list1.pushBack(22);
    list1.pushBack(11);
    cout << "Insertion Sort: ";
    list1.insertionSort();
    list1.display();

    // Demonstration of Selection Sort
    LinkedList list2;
    list2.pushBack(64);
    list2.pushBack(25);
    list2.pushBack(12);
    list2.pushBack(22);
    list2.pushBack(11);
    cout << "Selection Sort: ";
    list2.selectionSort();
    list2.display();

    // Demonstration of Bubble Sort
    LinkedList list3;
    list3.pushBack(64);
    list3.pushBack(25);
    list3.pushBack(12);
    list3.pushBack(22);
    list3.pushBack(11);
    cout << "Bubble Sort:    ";
    list3.bubbleSort();
    list3.display();

    // Demonstration of Shell Sort
    LinkedList list4;
    list4.pushBack(64);
    list4.pushBack(25);
    list4.pushBack(12);
    list4.pushBack(22);
    list4.pushBack(11);
    cout << "Shell Sort:     ";
    list4.shellSort();
    list4.display();

    return 0;
}
