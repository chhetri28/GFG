#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[(i+d)%n];
    }
    for (size_t i = 0; i <n; i++)
    {
        cout<<a[i]<<" ";
    }
}