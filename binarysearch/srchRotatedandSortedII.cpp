#include <bits/stdc++.h>
using namespace std;
/* TO eliminate the ambiguos case of low == mid == high in duplicates*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // target found
            if (nums[mid] == target)
                return true;

            // duplicate case: cannot decide sorted half
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;   // skip duplicates safely
            }

            // left half is sorted
            if (nums[low] <= nums[mid]) {

                // target lies in left sorted half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
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
                else {
                    high = mid - 1;
                }
            }
        }
        return false;   // target not present
    }
};

int main() {
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    Solution s;
    cout << s.search(nums, target);
    return 0;
}
