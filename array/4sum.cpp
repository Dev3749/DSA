#include <bits/stdc++.h>
using namespace std;
/*
  Problem : 4sum 
  Approach :
   1.Sort the array 
   2. Fix two indices i and j 
   3. use two pointer approach for remaining part
   4. skip duplicates to avoid repeated quadruplets 
   Time Complexity : O(n^3)
   Space Complexity :O(1) excluding answer storage  */
class Solution
{
public:
    vector<vector<int>> FourSum(vector<int> arr)
    {
       vector<vector<int>>ans;
       //Sort the array
       sort(arr.begin(),arr.end());
        for (int i = 0; i < arr.size(); i++)
        { //FIX first element 
            if (i > 0 && arr[i] == arr[i - 1])//avoid duplicates for first i 
                continue;
            for (int j = i + 1; j < arr.size(); j++)
            { // Fix second element 
                if (j > i+1 && arr[j] == arr[j - 1])//avoid duplicats for first j
                    continue;
                int k = j + 1;  //Two pointer approach
                int l = arr.size() - 1;
                while (k < l)
                {
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum < 0)
                    {
                        k++;
                    }
                    else if (sum > 0)
                    {
                        l--;
                    }
                    else
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        //Skip duplicates for k and l
                        while(k<l && arr[k]==arr[k-1])k++;
                        while(k<l && arr[l]==arr[l+1])l--;
                    }
                }
            }
        }
         return ans;

    }
};
int main()
{
    vector<int> arr = {1, 0, -1, 0, -2};
    Solution obj;
    vector<vector<int>> result = obj.FourSum(arr);
    for (auto &row : result)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
    }
}