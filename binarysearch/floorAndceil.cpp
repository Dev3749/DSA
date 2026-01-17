#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={3,4,4,7,8,9};
    int floor= INT_MIN;
    int ceil = INT_MAX;
    int low = 0;
    int high = arr.size()-1;
    int x = 6;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==x){
            floor = ceil =arr[mid]; break;
        }
        else if(arr[mid]> x){
            ceil = min(ceil,arr[mid]);
            high = mid -1;
        }
        else if(arr[mid]<x){
            floor= max(floor,arr[mid]);
            low = mid+1;
        }
    } 
 cout<<"Floor is :"<<floor<<" and ceil is :"<< ceil;
}