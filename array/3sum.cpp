#include <bits/stdc++.h>
using namespace std;

/*
Problem: 3Sum
Approach:
1. Sort the array
2. Fix one element and use two pointers for the remaining part
3. Skip duplicates to avoid repeated triplets

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding answer)
*/

class Solution {
public:
    vector<vector<int>> ThreeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicates
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-2, -1, 0, 1, 1, 2, 2};
    Solution obj;

    vector<vector<int>> result = obj.ThreeSum(nums);

    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
