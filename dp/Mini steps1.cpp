#include<bits/stdc++.h>
using namespace std;
int ministeps(int n,int dp[]){
    if(n==1)return 0;
    if(dp[n]!=0)return dp[n];
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0){
        op1=ministeps(n/3,dp)+1;
    }
    if(n%2==0){
    op2=ministeps(n/2,dp)+1;
    }
    op3=ministeps(n-1,dp)+1;
    int ans=min(min(op1,op2),op3);
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<ministeps(n,dp);
}