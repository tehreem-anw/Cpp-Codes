#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to generate and print unique subsets directly
void printUniqueSubsets(vector<int> &nums, vector<int> &ans, int i) {
    // Base Case: When we've considered all elements
    if (i == nums.size()) {
        cout << "{ ";
        for (int val : ans) {
            cout << val << " ";
        }
        cout << "}\n";
        return;
    }
    
    // Choice 1: Include the current element
    ans.push_back(nums[i]);
    printUniqueSubsets(nums, ans, i + 1);
    
    // Choice 2: Exclude the current element (Backtrack)
    ans.pop_back();
    
    // Skip all consecutive duplicate elements to avoid duplicate subsets
    int idx = i + 1;
    while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
        idx++;
    }
    
    printUniqueSubsets(nums, ans, idx);
}

int main() {
    // Test array with duplicates
    vector<int> nums = {1, 2, 2};
    
    // Step 1: Sorting is mandatory for duplicate elimination to work
    sort(nums.begin(), nums.end());
    
    vector<int> ans; // Temporary vector to store the current subset
    
    cout << "All unique subsets for {1, 2, 2}:\n";
    printUniqueSubsets(nums, ans, 0);
    
    return 0;
}
