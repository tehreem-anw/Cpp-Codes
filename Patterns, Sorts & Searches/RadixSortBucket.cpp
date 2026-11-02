#include<iostream>
using namespace std;

const int N = 6;
const int num_buckets = 10;
const int bucket_cap = 10;

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void radixSort(int arr[], int n){
    int m = getMax(arr, n);
    for(int exp = 1; m / exp > 0; exp*=10){
        int buckets[num_buckets][bucket_cap];
        int bucket_size[num_buckets] = {0};

        for(int i = 0; i < n; i++){
            int digit = (arr[i] / exp) % 10;
            buckets[digit][bucket_size[digit]] = arr[i];
            bucket_size[digit]++;
        }

        int idx = 0;
        for(int i = 0; i < num_buckets; i++){
            for(int j = 0; j < bucket_size[i]; j++){
                arr[idx++] = buckets[i][j];
            }
        }
    }
    
}
