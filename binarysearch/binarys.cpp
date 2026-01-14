#include<bits/stdc++.h>
using namespace std;
int  binarySearch(vector<int>arr,int low,int high,int key){
      if(low>high )return -1;       
      int mid = (high-low)/2 +low;
       if(arr[mid]==key) return mid;
       else if(arr[mid]>key){
        return binarySearch(arr,low,mid-1,key);
       }
       else {
        return binarySearch(arr,mid+1,high,key);
       } 
}
int main(){
    vector<int>arr = {2,3,4,12};
    int key = 4;
        int low = 0;
    int high = arr.size()-1;
    int ans = binarySearch(arr,low,high,key);
    if(ans== -1)cout<<"Not found ";
    else{
        cout<<"Key "<< arr[ans]<<" found ! and at index "<<ans;
    }
}