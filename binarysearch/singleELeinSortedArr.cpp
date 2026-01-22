#include<bits/stdc++.h>
using namespace std;
/*
Concept:
- The array is sorted and every element appears exactly twice except one.
- Duplicate elements form pairs at (even, odd) indices.
- Before the single element, pairs start at even indices.
- After the single element, this index pattern breaks.
- Using binary search, check index parity to decide which half to search.
- If mid is even and equals next OR mid is odd and equals previous,
  then the single element lies on the right side.
- Otherwise, it lies on the left side.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    Solution s;
    cout << s.singleNonDuplicate(nums);
    return 0;
}
