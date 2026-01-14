#include<bits/stdc++.h>
using namespace std;
/*
Problem : Lower Bound 
Approach :Binary search*/
int lowerBound(vector<int>arr,int x){
    int low = 0 ;
    int ans = arr.size();
    int high = arr.size()-1;
    while(low<high){
       int mid= low + (high-low)/2;
       if(arr[mid]>=x) {
        ans = mid;
        high = mid-1;
       }
       else {
         low = mid+1;
       }
    }
    return ans;
}
int main(){
    vector<int>arr= {2,3,10,12};
    int x = 11;
    int result = lowerBound(arr,x);
    cout<<result;
    return 0;
}