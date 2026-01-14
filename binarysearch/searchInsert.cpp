/*
  Problem: Search Insert Position
  Approach: Binary Search (Lower Bound)
  Time Complexity: O(log n)
  Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Finds the index where target is found or should be inserted
int searchInsertPosition(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();   // default insert position

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << searchInsertPosition(nums, target);
    return 0;
}
