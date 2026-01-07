#include<bits/stdc++.h>
using namespace std;
/*
 Problem : Repeating and Missing no.
 Approach:
 1.cal sn , s2n using  math formula
 2.cal s ,s2 by traversing through arr
 3. using x2 -y2 =(x+y)/(x-y) cal x+y and then we can simply cal the x and y 
 */
int main(){
    vector<int>arr = {4,2,1,1};
     long long n = arr.size();
     long long Sn = (n * (n+1))/2; 
     long long S2n = (n * (n+1)*(2*n+1))/6;
     long long s =0 ,  s2 = 0 ;
     for(int i=0;i<n;i++){
        s += arr[i];
        s2 += (long long )arr[i] * (long long )arr[i];
     }
     long long  val1 = s - Sn; // x - y
     long long  val2 = s2 - S2n;// x^2 -y^2
     val2 = val2 / val1;  // x2 - y2 =(x+y)(x-y)
     long long x = (val1 + val2 )/2;
     long long y = x - val1;
     cout<<"Missing no. is :"<<y <<" and the repeating no. is :" <<x; 
       return 0;
    }
