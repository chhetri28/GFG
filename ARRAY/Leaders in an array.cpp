#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maxi=a[n-1];
        vector<int>m;
        for(int i=n-1;i>=0;i--){
            if(a[i]>=maxi){
                m.push_back(a[i]);
                maxi=a[i];
            }
        }
        for(int i=m.size()-1;i>=0;i--){
            cout<<m[i]<<" ";
        }
        cout<<endl;
    }
}