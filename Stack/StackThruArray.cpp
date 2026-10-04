#include<iostream>
using namespace std;

class Stack{
    int* arr;
    int top;
    int size;
    public:
    Stack(int s){
        size = s;
        arr = new int[s];
        top = -1;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size - 1;
    }
    void push(int val){
        if(isFull()){
            cout << "Stack overflow." << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack underflow." << endl;
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }
    int getTop(){
        if(isEmpty()){
            cout << "Stack underflow." << endl;
            return -1;
        }
        return arr[top];
    }
    void display(){
        if(isEmpty()){
            cout << "Stack underflow." << endl;
            return;
        }
        for(int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack(){
        delete[] arr;
    }
};

int main() {
    Stack s(5); // Create stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // Output: 10 20 30

    cout << "Current Top: " << s.getTop() << endl; // Output: 30

    cout << "Popped element: " << s.pop() << endl; // Output: 30
    s.display(); // Output: 10 20

    s.push(40);
    s.push(50);
    s.push(60); // Stack is now full [10, 20, 40, 50, 60]
    s.display();

    s.push(70); // Triggers Stack Overflow

    return 0;
}
