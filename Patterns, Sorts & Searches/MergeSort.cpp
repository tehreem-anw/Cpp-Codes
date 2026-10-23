#include<iostream>
using namespace std;

int max_size = 100;

void merge(int arr[], int st, int mid, int end){
    int temp[max_size];
    int count = 0;
    int i = st;
    int j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[count++] = arr[i];
            i++;
        }
        else{
            temp[count++] = arr[j];
            j++;
        }
    }
    while(i <= mid){
        temp[count++] = arr[i];
        i++;
    }
    while(j <= end){
        temp[count++] = arr[j];
        j++;
    }
    for(int idx = 0; idx < count; idx++){
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(int arr[], int st, int end){
    if(st < end){
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, st, mid, end);
    }
}

int main() {
    int n = 6;
    int arr[max_size] = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Merge Sort on the entire range [0, n - 1]
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
