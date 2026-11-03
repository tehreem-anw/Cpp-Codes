#include <iostream>
#include <vector>

using namespace std;

// Recursive function to generate and print subsets directly
void printSubsets(vector<int> &nums, vector<int> &ans, int i) {
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
    printSubsets(nums, ans, i + 1);
    
    // Choice 2: Exclude the current element (Backtrack)
    ans.pop_back();
    printSubsets(nums, ans, i + 1);
}

int main() {
    // Test array
    vector<int> nums = {1, 2, 3};
    vector<int> ans; // Temporary vector to store the current subset
    
    cout << "All subsets for {1, 2, 3}:\n";
    printSubsets(nums, ans, 0);
    
    return 0;
}

// Output
// All subsets for {1, 2, 3}:
// { 1 2 3 }
// { 1 2 }
// { 1 3 }
// { 1 }
// { 2 3 }
// { 2 }
// { 3 }
// { }
