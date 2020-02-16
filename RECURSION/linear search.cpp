#include<iostream>
using namespace std;
int search(int *a,int i,int n,int k){
   if(i==n){
        return -1;
    }
    if(a[i]==k){
        return i;
    }
    return search(a,i+1,n,k);
}
int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int k=7;
    cout<<search(a,0,n,k);
    return 0;
}