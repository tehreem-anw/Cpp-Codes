#include<iostream>
using namespace std;

const int N = 6;
const int num_buckets = 6;
const int bucket_cap = 6;


void insertionSort(float arr[], int n){
    for(int i = 1; i < n; i++){
        float key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n){
    float buckets[num_buckets][bucket_cap];
    int bucket_size[num_buckets] = {0};

    for(int i = 0; i < n; i++){
        // Scattering
        int bi = num_buckets * arr[i];
        if(bi >= num_buckets){
            bi = num_buckets - 1;
        }
        buckets[bi][bucket_size[bi]] = arr[i];
        bucket_size[bi]++;
    }

    // Sorting
    for(int i = 0; i < num_buckets; i++){
        if(bucket_size[i] > 0){
            insertionSort(buckets[i], bucket_size[i]);
        }
    }

    // Gathering
    int index = 0;
    for(int i = 0; i < num_buckets; i++){
        for(int j = 0; j < bucket_size[i]; j++){
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    // Input array containing floating-point numbers between 0.0 and 1.0
    float arr[N] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};

    cout << "Original array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform bucket sort
    bucketSort(arr, N);

    cout << "Sorted array:   ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
