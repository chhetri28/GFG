#include<iostream>
using namespace std;
int last(int *a,int n,int k){
if(n==0){
    return -1;
}
int i=last(a+1,n-1,k);
if(i==-1){
    if(a[0]==k){
        return 0;
    }
    else{
        return -1;
    }
}
return i+1;
}
int first(int *a,int i,int n,int k){
   if(i==n){
        return -1;
    }
    if(a[i]==k){
        return i;
    }
    return first(a,i+1,n,k);
}
int main(){
    int a[]={1,2,3,7,4,5,7};
    int n=sizeof(a)/sizeof(a[0]);
    int k=7;
    cout<<first(a,0,n,k)<<" ";
    cout<<last(a,n,k);
    return 0;
}