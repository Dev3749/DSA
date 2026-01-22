#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // finds first index of target
    int firstOcc(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;                 // stores answer

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;           // possible answer
                high = mid - 1;      // move left for first occurrence
            }
            else if (nums[mid] < target) {
                low = mid + 1;       // target on right side
            }
            else {
                high = mid - 1;      // target on left side
            }
        }
        return ans;
    }

    // finds last index of target
    int lastOcc(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;           // possible answer
                low = mid + 1;       // move right for last occurrence
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    pair<int,int> searchRange(vector<int>& nums, int target) {
        // calling both searches
        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
    int count(vector<int>&nums,int target){
        pair<int,int>ans = searchRange(nums,target);
        if (ans.first == -1) return 0;
        return (ans.second - ans.first + 1 );
    }

};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution s;
   int ans = s.count(nums, target);
    cout << ans;
    return 0;
}
