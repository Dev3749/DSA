#include<bits/stdc++.h>
using namespace std;
class Pascal{
    public:
    vector<int>generateRow(int row){
        long long ans = 1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int i = 1;i<row;i++){
            ans = ans * (row-i);
            ans /= i;
            ansRow.push_back(ans);
        }
         return ansRow;
    }
    vector<vector<int>>pasTriangle(int N){
        vector<vector<int>>ans;
        for(int i =1;i<=N;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
int main(){
  Pascal obj;
  int n = 4;
  vector<vector<int>>result = obj.pasTriangle(n);
   for (auto &row : result) {
        for (auto &val : row) cout << val << " ";
        cout << endl;
    }
}