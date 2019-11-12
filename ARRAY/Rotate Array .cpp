#include<bits/stdc++.h>
using namespace std;
    int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int mod=d%n;
        for(int i=0;i<n;i++){
            cout<<a[(mod+i)%n]<<" ";
        }
        cout<<endl;
    }
}