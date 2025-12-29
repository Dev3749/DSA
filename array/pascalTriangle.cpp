#include <bits/stdc++.h>
using namespace std;

/*
Problem: Pascal's Triangle
Approach:
- Each row is generated using nCr formula
- nth row has n elements
- Use previous value to compute next value efficiently

Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/

class Pascal {
public:
    // Generates a single row of Pascal's Triangle
    vector<int> generateRow(int row) {
        long long value = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for (int i = 1; i < row; i++) {
            value = value * (row - i);
            value = value / i;
            ansRow.push_back(value);
        }
        return ansRow;
    }

    // Generates Pascal's Triangle up to N rows
    vector<vector<int>> pascalTriangle(int N) {
        vector<vector<int>> ans;
        for (int i = 1; i <= N; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

int main() {
    Pascal obj;
    int n = 4;

    vector<vector<int>> result = obj.pascalTriangle(n);

    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
