#include <iostream>

using namespace std;

// Helper function for recursive binary search
int bs(int* nums, int tar, int st, int end){
    if(st <= end){
        int mid = (st + end) / 2;
        
        if(nums[mid] == tar) {
            return mid;
        }
        else if(nums[mid] < tar) {
            return bs(nums, tar, mid + 1, end); // Search right half
        }
        else {
            return bs(nums, tar, st, mid - 1); // Search left half
        }
    }
    return -1; // Base case: Target not found
}

// Main search function matching standard LeetCode signature
int search(int* nums, int numsSize, int target) {
    return bs(nums, target, 0, numsSize - 1);
}

int main() {
    // Note: Binary search requires the array to be sorted!
    int nums[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int target = 23;
    int result = search(nums, numsSize, target);
    
    if (result != -1) {
        cout << "Target " << target << " found at index: " << result << "\n";
    } else {
        cout << "Target " << target << " not found in the array.\n";
    }
    
    return 0;
}

// Output:
// Target 23 found at index: 5
