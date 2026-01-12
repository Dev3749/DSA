#include <bits/stdc++.h>
using namespace std;

/*
  Maximum Product Subarray
  Approach: Prefix & Suffix traversal

  Idea:
  - Calculate product from left (prefix) and right (suffix)
  - Reset product when it becomes zero
  - Take maximum at every step
*/

int main() {
    vector<int> arr = {1, 2, -3, 0, 4, -9, -1};

    int pre = 1, suf = 1;
    int ans = INT_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suf == 0) suf = 1;

        pre *= arr[i];
        suf *= arr[n - i - 1];

        ans = max(ans, max(pre, suf));
    }

    cout << ans << endl;
    return 0;
}
