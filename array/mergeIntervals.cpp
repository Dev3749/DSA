#include <bits/stdc++.h>
using namespace std;

/*
Problem: Merge Intervals

Approach:
1. Sort intervals based on starting time.
2. Traverse intervals and compare with the last merged interval.
3. If overlapping, merge by updating the end time.
4. Otherwise, add the current interval as a new one.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (auto &interval : intervals) {
            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    Solution obj;

    vector<vector<int>> result = obj.merge(intervals);

    cout << "Merged Intervals:\n";
    for (auto &row : result) {
        cout << "[" << row[0] << ", " << row[1] << "] ";
    }
    cout << endl;

    return 0;
}
