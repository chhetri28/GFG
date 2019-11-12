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
    sort(a,a+n);
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            if(binary_search(a,a+n,a[i]+a[j])){
                count++;
            }
        }
    }
    if(count){
        cout<<count<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    }
}