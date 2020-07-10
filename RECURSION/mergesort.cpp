#include<iostream>
using namespace std;
void mergesort(int a[],int s,int e);
int merge(int a[],int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[1000];
    while(i<=s and j<=e){
        if(a[i]<= a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=mid){
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i]=temp[i];
    }
}
void mergesort(int a[],int s,int e){
    //base case 
    if(s>=e){
        return;
    }
    //Divide
    int mid=(s+e)/2;
    //sort
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    //merge
    merge(a,s,e);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}