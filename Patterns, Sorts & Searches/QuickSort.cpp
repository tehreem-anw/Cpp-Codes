#include<iostream>
using namespace std;

int partition(int arr[], int st, int end){
    int idx = st - 1;
    int pivot = arr[end];
    for(int j = st; j < end; j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(int arr[], int st, int end){
    if(st < end){
        int piv_idx = partition(arr, st, end);
        quickSort(arr, st, piv_idx - 1);
        quickSort(arr, piv_idx + 1, end);
    }
}

int main() {
    int n = 6;
    int arr[n] = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Merge Sort on the entire range [0, n - 1]
    quickSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
