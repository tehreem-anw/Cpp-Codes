#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1. Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 2. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 3. Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: stop if array is already sorted
    }
}

// 4. Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr1[] = {12, 34, 54, 2, 3};
    int arr2[] = {12, 34, 54, 2, 3};
    int arr3[] = {12, 34, 54, 2, 3};
    int arr4[] = {12, 34, 54, 2, 3};
    int n = 5;

    cout << "Insertion Sort: ";
    insertionSort(arr1, n);
    printArray(arr1, n);

    cout << "Selection Sort: ";
    selectionSort(arr2, n);
    printArray(arr2, n);

    cout << "Bubble Sort:    ";
    bubbleSort(arr3, n);
    printArray(arr3, n);

    cout << "Shell Sort:     ";
    shellSort(arr4, n);
    printArray(arr4, n);

    return 0;
}
