#include<bits/stdc++.h>
using namespace std;
void bubblesort(int *a,int n){
    if(n==1){
        return;
    }
    for(int j=0;j<n;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    bubblesort(a,n-1);
}
int main(){
    int a[]={1,2,5,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    bubblesort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }    
}