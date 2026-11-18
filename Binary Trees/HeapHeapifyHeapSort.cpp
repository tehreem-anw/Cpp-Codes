#include<iostream>
#include<string>
using namespace std;

class MaxHeap{
	int* arr;
	int size;
	int cap;
	public:
		MaxHeap(int c){
			cap = c;
			arr = new int[cap];
			size = 0;
		}
		int parent(int i){
			return (i-1) / 2;
		}
		int leftChild(int i){
			return (2*i) + 1;
		}
		int rightChild(int i){
			return (2*i) + 2;
		}
		bool isEmpty(){
			return size == 0;
		}
		bool isFull(){
			return size == cap;
		}
		void heapifyUp(int i){
			while(i > 0 && arr[parent(i)] < arr[i]){
				swap(arr[parent(i)], arr[i]);
				i = parent(i);
			}
		}
		void heapifyDown(int i){
			while(true){
				int largest = i;
				int l = leftChild(i);
				int r = rightChild(i);
				if(l < size && arr[l] > arr[largest]) {
					largest = l;
				}
				if(r < size && arr[r] > arr[largest]){
					largest = r;
				}
				if(i == largest) break;
				swap(arr[i], arr[largest]);
				i = largest;
			}
		}
		void insert(int val){
			if(isFull()){
				cout << "Heap is full." << endl;
				return;
			}
			arr[size] = val;
			size++;
			heapifyUp(size - 1);
		}
		int deleteNode(){
			if(isEmpty()){
				cout << "Heap is empty." << endl;
				return -1;
			}
			int top = arr[0];
			arr[0] = arr[size - 1];
			size--;
			heapifyDown(0);
			return top;
		}
		int peek() {
	        if (isEmpty()) {
	            cout << "Heap is empty." << endl;
	            return -1;
	        }
	        return arr[0];
    	}
		void display() {
	        for (int i = 0; i < size; i++) {
	            cout << arr[i] << " ";
	        }
	        cout << endl;
		}
		~MaxHeap(){
			delete[] arr;
		}
};
void heapifyForSort(int arr[], int n, int i){
	int largest = i;
	int l = (2*i) + 1;
	int r = (2*i) + 2;
	if(l < n && arr[l] > arr[largest]){
		largest = l;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(i != largest){
		swap(arr[i], arr[largest]);
		heapifyForSort(arr, n, largest);
	}	
}
void heapSort(int arr[], int n){
	for(int i = n / 2 - 1; i >= 0; i--){
		heapifyForSort(arr, n, i);
	}
	for(int i = n-1; i > 0; i--){
		swap(arr[0], arr[i]);
		heapifyForSort(arr, i, 0);
	}
}

int main() {
    MaxHeap h(10);
    int values[] = {20, 15, 30, 10, 40};
    for (int i = 0; i < 5; i++) {
        h.insert(values[i]);
    }
    cout << "MaxHeap elements: ";
    h.display(); 

    cout << "Peek: " << h.peek() << endl;  
    cout << "Deleted: " << h.deleteNode() << endl; 

    cout << "After deletion: ";
    h.display(); 
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
    return 0;
}
