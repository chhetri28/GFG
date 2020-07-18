#include<iostream>
using namespace std;
int inversion_count(int *a,int s,int e);
int merge(int *a,int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=(mid+1);
    int k=s;
    int temp[100000];
    int cnt(0);
    while(i<=mid and j<=e){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k++]=a[j++];
            cnt+=mid-(i-1);
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i]=temp[i];
    }
    return cnt;
}
int inversion_count(int *a,int s,int e){
    if(s>=e){
        return 0;
    }
    int mid=(s+e)/2;
    int x=inversion_count(a,s,mid);
    int y=inversion_count(a,mid+1,e);
    int z=merge(a,s,e);
    return x+y+z;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<inversion_count(a,0,n-1);
}