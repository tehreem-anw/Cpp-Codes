#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front;
    int rear;
    int size;
    int* arr;

public:
    // Constructor
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to prevent memory leak
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Insert element
    void enQueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) { // First element insertion
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size; // Wrap around circularly
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Remove element
    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        
        if (front == rear) { // Last element removed, reset queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size; // Wrap around circularly
        }
    }

    // Get front element
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is Empty! ";
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is Empty! ";
            return -1;
        }
        return arr[rear];
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enQueue(23);
    q.enQueue(45);
    q.enQueue(44);

    cout << "Front Element: " << q.frontElement() << endl; // Output: 23
    
    q.deQueue(); // Removes 23
    cout << "Front Element after deQueue: " << q.frontElement() << endl; // Output: 45

    q.display();

    return 0;
}
