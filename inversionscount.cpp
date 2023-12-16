// mergesort

#include <bits/stdc++.h> 

using namespace std;

long long  merge(long long *a,long long l,long long mid, long long r,long long *temp){
    long long i=l;
    long long j=mid;
   long long k=l;
 long long inv=0;
    
    while(i<=mid-1&&j<=r){
        
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
            inv+=(mid-i);
        }
        
    }
    while(i<mid){
        temp[k++]=a[i++];
    }
     while(j<=r){
        temp[k++]=a[j++];
    }
    
   for(int i = l ; i <= r ; i++)
        a[i] = temp[i];
    
    return inv;
    
    
}

long long  mergesort(long long *a,long long l,long long r,long long *temp){
  long long  mid=0,inv=0;
    
    if(r>l){
    mid=(l+r)/2;
   inv+= mergesort(a,l,mid,temp);
   inv+= mergesort(a,mid+1,r,temp);
    inv+= merge(a,l,mid+1,r,temp);
    }
    return inv;
}



long long getInversions(long long *arr, int n){
 
 long long temp[n];
    
   return mergesort(arr,0,n-1,temp);
    
}


int main(){
   int n=10;
   long long arr[]={
       52244275,123047899, 493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025 ,339100162
   };

   cout <<getInversions(arr,n);
}