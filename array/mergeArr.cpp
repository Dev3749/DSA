#include <bits/stdc++.h>
using namespace std;

/*
Problem: Merge two sorted arrays without extra space

Approach: GAP Method (Shell Sort idea)

Idea:
- Treat nums1 and nums2 as one virtual combined array
- Compare elements at a distance = gap
- Swap if they are out of order
- Reduce gap until it becomes 0

Time Complexity: O((m + n) log(m + n))
Space Complexity: O(1)
*/

class Solution {
private:
    void swapIfGreater(vector<int>& a, vector<int>& b, int i, int j) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
        }
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int len = m + n;
        int gap = (len / 2) + (len % 2);   // ceil(len / 2)

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {

                // left in nums1, right in nums2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                }
                // both in nums2
                else if (left >= m) {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                // both in nums1
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }

                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

        // copy nums2 into nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 7, 0, 0, 0};
    vector<int> nums2 = {0, 2, 6};

    int m = 4, n = 3;
    Solution obj;
    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
