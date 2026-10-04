#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int s){
        size = s;
        arr = new int [size];
        front = rear = 0;
    }
    bool isEmpty(){
        return front == rear;
    }
    bool isFull(){
        return rear == size;
    }
    void enqueue(int val){
        if(isFull()){
            cout << "Queue Overflow." << endl;
            return;
        }
        arr[rear] = val;
        rear++;
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[front];
        front++;
        if(front == rear){
            front = rear = 0;
        }
        return val;
    }
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
        return arr[rear - 1];
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Queue(){
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.enqueue(23);
    q.enqueue(45);
    q.enqueue(44);
    q.display();

    cout << "Front Element: " << q.frontElement() << endl; // Output: 23

    q.dequeue(); // Removes 23
    cout << "Front Element after deQueue: " << q.frontElement() << endl; // Output: 45

    q.display();

    return 0;
}
