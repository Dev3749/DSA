#include <bits/stdc++.h>
using namespace std;
/* Concept : using the sorted thing to solve in 0(logn).
IN Rotated , we observe that one of side must be sorted , we use this to eliminate the problem into halfs*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // target found
            if (nums[mid] == target)
                return mid;

            // left half is sorted
            if (nums[low] <= nums[mid]) {

                // target lies in left sorted half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                // target lies in right half
                else {
                    low = mid + 1;
                }
            }
            // right half is sorted
            else {

                // target lies in right sorted half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                // target lies in left half
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;   // target not found
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution s;
    cout << s.search(nums, target);
    return 0;
}
