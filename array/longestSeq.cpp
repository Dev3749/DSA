#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest
consecutive elements sequence.

Approach: Hash Set (Optimal)

Idea:
1. Insert all elements into an unordered_set.
2. For each element, check if it is the start of a sequence
   (i.e., element - 1 does not exist).
3. If yes, count consecutive elements forward.
4. Update the maximum length.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        int longest = 1;

        for (auto it : st) {
            // Check if it is the start of a sequence
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution obj;

    int result = obj.longestConsecutive(nums);
    cout << result << endl;

    return 0;
}
