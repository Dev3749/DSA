/*
  Problem: Count Inversions in an Array
  Approach: Merge Sort based inversion counting
  Time Complexity: O(n log n)
  Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Merges two sorted halves and counts inversions
int mergeArrays(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    int inversions = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
            inversions += (mid - left + 1);
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return inversions;
}

// Recursive merge sort function
int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;

    int mid = low + (high - low) / 2;
    int inversions = 0;

    inversions += mergeSort(arr, low, mid);
    inversions += mergeSort(arr, mid + 1, high);
    inversions += mergeArrays(arr, low, mid, high);

    return inversions;
}

// Wrapper function
int countInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {3, 2, 10, 4};
    cout << countInversions(arr);
    return 0;
}
