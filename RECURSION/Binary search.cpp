#include<bits/stdc++.h>
using namespace std;
int binarySearch(int *a,int s,int e,int k){
   if(s<=e){
       int m=(s+e)/2;
       if(a[m]==k) return m+1;
       if(a[m]<k) return (a,s,m-1,k);
       return (a,m+1,e,k);
   }
   return -1;
}
int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int k=5;
    cout<<binarySearch(a,0,n,k);
}