#include <iostream>
#include <string>

using namespace std;

class JobEntry {
public:
    string name;
    int priority;
    long long arrivalTime;

    JobEntry() {
        name = "";
        priority = 0;
        arrivalTime = 0;
    }

    JobEntry(string n, int p, long long a) {
        name = n;
        priority = p;
        arrivalTime = a;
    }
};

class PrintServerQueue {
private:
    JobEntry heap[100];
    int size;
    long long counter;

    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[i].priority < heap[p].priority || (heap[i].priority == heap[p].priority && heap[i].arrivalTime < heap[p].arrivalTime)) {
                JobEntry temp = heap[i];
                heap[i] = heap[p];
                heap[p] = temp;
                i = p;
            } else {
                break;
            }
        }
    }

    void siftDown(int i) {
        while (2 * i + 1 < size) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < size && (heap[left].priority < heap[smallest].priority || 
                (heap[left].priority == heap[smallest].priority && heap[left].arrivalTime < heap[smallest].arrivalTime))) {
                smallest = left;
            }
            if (right < size && (heap[right].priority < heap[smallest].priority || 
                (heap[right].priority == heap[smallest].priority && heap[right].arrivalTime < heap[smallest].arrivalTime))) {
                smallest = right;
            }

            if (smallest != i) {
                JobEntry temp = heap[i];
                heap[i] = heap[smallest];
                heap[smallest] = temp;
                i = smallest;
            } else {
                break;
            }
        }
    }

public:
    PrintServerQueue() {
        size = 0;
        counter = 0;
    }

    void push(string jobName, int priority) {
        heap[size] = JobEntry(jobName, priority, counter++);
        siftUp(size);
        size++;
    }

    string pop() {
        if (size == 0) return "Queue Empty";
        string topName = heap[0].name;
        heap[0] = heap[size - 1];
        size--;
        siftDown(0);
        return topName;
    }

    string peek() {
        if (size == 0) return "Queue Empty";
        return heap[0].name;
    }
};

int main() {
    PrintServerQueue server;
    
    server.push("J1", 3); // Step 1
    server.push("J2", 1); // Step 2
    server.push("J3", 2); // Step 3
    cout << "POP: " << server.pop() << endl;   
    server.push("J4", 1); // Step 5
    server.push("J5", 3); // Step 6
    cout << "POP: " << server.pop() << endl;   
    cout << "POP: " << server.pop() << endl;   
    server.push("J6", 2); // Step 9
    cout << "POP: " << server.pop() << endl;  
    cout << "POP: " << server.pop() << endl;  
    cout << "POP: " << server.pop() << endl; 

    return 0;
}
