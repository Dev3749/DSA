#include <bits/stdc++.h>
using namespace std;

/*
Problem: Longest Subarray with Sum = 0
Approach: Prefix Sum + Hashing

Idea:
- Maintain prefix sum
- If the same prefix sum appears again, the subarray between
  those indices has sum 0
- Store first occurrence of each prefix sum to maximize length

Time Complexity: O(n)
Space Complexity: O(n)
*/

int main() {
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4};

    unordered_map<int, int> mpp;
    int sum = 0;
    int maxLen = 0;

    int start = -1, end = -1;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Case 1: Subarray from index 0 to i
        if (sum == 0) {
            if (i + 1 > maxLen) {
                maxLen = i + 1;
                start = 0;
                end = i;
            }
        }

        // Case 2: Prefix sum seen before
        if (mpp.find(sum) != mpp.end()) {
            int length = i - mpp[sum];
            if (length > maxLen) {
                maxLen = length;
                start = mpp[sum] + 1;
                end = i;
            }
        } else {
            // Store first occurrence only
            mpp[sum] = i;
        }
    }

    cout << "Max Length: " << maxLen << endl;
    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
