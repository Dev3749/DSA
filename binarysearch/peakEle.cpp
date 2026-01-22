
#include <bits/stdc++.h>
using namespace std;
/*
Concept:
- A peak element is an element greater than its neighbors.
- The array does not need to be sorted.
- Use binary search to discard the half where a peak cannot exist.
- Loop ends when low == high, which points to a peak index.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // peak lies on right side
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }
            // peak lies on left side (including mid)
            else {
                high = mid;
            }
        }
        return low;   // low == high is the peak index
    }
};

int main() {
    vector<int> nums = {1,2,3,1};

    Solution s;
    cout << s.findPeakElement(nums);
    return 0;
}
