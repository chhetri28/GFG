#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n-1; i++) {
        /* code */
        cin>>a[i];
    }
    int total= (n*(n+1))/2;
    //cout<<total<<" ";
    for (int i = 0; i < n-1; i++) {
        /* code */
        total-=a[i];
    }
    cout<<total<<endl;
    }
}