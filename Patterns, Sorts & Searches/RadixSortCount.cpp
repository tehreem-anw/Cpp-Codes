#include<iostream>
using namespace std;

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp){
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++){
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for(int i = 0; i < n; i++){
        count[i] += count[i-1];
    }

    for(int i = n-1; i >= 0; i--){
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}
