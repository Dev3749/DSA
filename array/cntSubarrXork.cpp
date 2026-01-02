#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count Subarrays with XOR = K

Approach: Prefix XOR + Hashing

Idea:
- Maintain prefix XOR while traversing the array
- If (prefixXor ^ k) has appeared before,
  then those many subarrays end at current index with XOR = k
- freq[0] = 1 is used to count subarrays starting from index 0

Time Complexity: O(n)
Space Complexity: O(n)
*/

int main() {
    vector<int> arr = {4, 2, 2, 6,4};
    int k = 6;

    unordered_map<int, int> freq;
    freq[0] = 1;  // To count subarrays starting from index 0

    int prefixXor = 0;
    int count = 0;

    for (int num : arr) {
        prefixXor ^= num;

        int target = prefixXor ^ k;
        if (freq.find(target) != freq.end()) {
            count += freq[target];
        }

        freq[prefixXor]++;
    }

    cout << count << endl;
    return 0;
}
