#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1,2,3,4,5,6,7};

    int lo=0,hi=a.size()-1;
    int ele  = 7;
    while(hi-lo>1){
       int mid = (lo+hi )/ 2;
       if(ele < a[mid]){
        hi=mid-1;
       }else {
           lo=mid;
       }
    }
    if(a[lo]==ele) cout << "found at: "<<lo;
    else if (a[hi]==ele) cout <<" found at: "<<hi;
    return 0;
}